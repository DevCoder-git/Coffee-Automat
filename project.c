#include <stdio.h>
#include <stdlib.h>

// Defining the maximum quantity for each item in inventory
#define MAX_COFFEE_BEANS 1000 // in grams
#define MAX_MILK 1000         // in milliliters

// Global variables for inventory
int coffeeBeans = MAX_COFFEE_BEANS;
int milk = MAX_MILK;

// Arrays for coffee prices based on type and size
int coffeePrices[3][3] = {
    {50, 60, 70}, // Espresso: Small, Medium, Large
    {70, 80, 90}, // Latte: Small, Medium, Large
    {80, 90, 100} // Cappuccino: Small, Medium, Large
};

// Arrays for coffee beans and milk requirements based on type and size
int beansRequired[3][3] = {
    {10, 15, 20}, // Espresso: Small, Medium, Large
    {15, 20, 25}, // Latte: Small, Medium, Large
    {15, 20, 25}  // Cappuccino: Small, Medium, Large
};

int milkRequired[3][3] = {
    {30, 50, 70},    // Espresso: Small, Medium, Large
    {150, 200, 250}, // Latte: Small, Medium, Large
    {100, 150, 200}  // Cappuccino: Small, Medium, Large
};

// Function to check inventory
int checkInventory(int coffeeType, int size, int cups)
{
    int beans = beansRequired[coffeeType - 1][size - 1];
    int milk = milkRequired[coffeeType - 1][size - 1];

    if (coffeeBeans < beans * cups || milk < milk * cups)
    {
        printf("Not enough inventory to prepare the selected coffee. Please refill.\n");
        return 0;
    }
    return 1;
}

// Function to dispense coffee
void dispenseCoffee(int coffeeType, int size, int cups)
{
    int price = coffeePrices[coffeeType - 1][size - 1];
    int beans = beansRequired[coffeeType - 1][size - 1];
    int milk = milkRequired[coffeeType - 1][size - 1];

    // Dispense coffee
    printf("Dispensing %d cup(s) of ", cups);
    if (coffeeType == 1)
        printf("Espresso ");
    else if (coffeeType == 2)
        printf("Latte ");
    else if (coffeeType == 3)
        printf("Cappuccino ");

    if (size == 1)
        printf("(Small)...\n");
    else if (size == 2)
        printf("(Medium)...\n");
    else if (size == 3)
        printf("(Large)...\n");

    // Update inventory
    coffeeBeans -= beans * cups;
    milk -= milk * cups;

    // Print remaining inventory
    printf("Remaining Coffee Beans: %d gm\n", coffeeBeans);
    printf("Remaining Milk: %d ml\n", milk);
    printf("Total Price: Rs. %d\n", price * cups);
}

// Function to display the coffee menu
void displayCoffeeMenu()
{
    printf("\nCoffee Dispenser Menu:\n");
    printf("1. Espresso\n");
    printf("2. Latte\n");
    printf("3. Cappuccino\n");
    printf("Enter your choice (1-3): ");
}

// Function to display the size menu
void displaySizeMenu()
{
    printf("Select size:\n");
    printf("1. Small\n");
    printf("2. Medium\n");
    printf("3. Large\n");
    printf("Enter your choice (1-3): ");
}

// Function to get and validate user input for coffee choice
int getCoffeeChoice()
{
    int coffeeChoice;
    displayCoffeeMenu();
    scanf("%d", &coffeeChoice);

    while (coffeeChoice < 1 || coffeeChoice > 3)
    {
        printf("Invalid choice! Please select a valid coffee type.\n");
        displayCoffeeMenu();
        scanf("%d", &coffeeChoice);
    }
    return coffeeChoice;
}

// Function to get and validate user input for size choice
int getSizeChoice()
{
    int sizeChoice;
    displaySizeMenu();
    scanf("%d", &sizeChoice);

    while (sizeChoice < 1 || sizeChoice > 3)
    {
        printf("Invalid choice! Please select a valid size.\n");
        displaySizeMenu();
        scanf("%d", &sizeChoice);
    }
    return sizeChoice;
}

// Function to get and validate user input for the number of cups
int getCups()
{
    int cups;
    printf("Enter the number of cups: ");
    scanf("%d", &cups);

    while (cups <= 0)
    {
        printf("Please enter a valid number of cups.\n");
        printf("Enter the number of cups: ");
        scanf("%d", &cups);
    }
    return cups;
}

int main()
{
    int coffeeChoice, sizeChoice, cups;

    printf("Welcome to the Coffee Dispenser System!\n");

    while (1)
    {
        coffeeChoice = getCoffeeChoice();
        sizeChoice = getSizeChoice();
        cups = getCups();

        // Check inventory and dispense coffee if inventory is sufficient
        if (checkInventory(coffeeChoice, sizeChoice, cups))
        {
            dispenseCoffee(coffeeChoice, sizeChoice, cups);
        }
    }

    return 0;
}
