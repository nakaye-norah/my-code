#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 5

typedef struct {
    char name[20];
    int quantity;
    float price;
} Item;

Item inventory[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount < MAX_ITEMS) {
        printf("Enter item name: ");
        scanf("%s", inventory[itemCount].name);
        printf("Enter quantity: ");
        scanf("%d", &inventory[itemCount].quantity);
        printf("Enter price: ");
        scanf("%f", &inventory[itemCount].price);
        itemCount++;
    } else {
        printf("Inventory is full!\n");
    }
}

void displayItems() {
    if (itemCount == 0) {
        printf("No items in inventory.\n");
    } else {
        for (int i = 0; i < itemCount; i++) {
            printf("%d. %s - Quantity: %d, Price: $%.2f\n", i + 1, inventory[i].name, inventory[i].quantity, inventory[i].price);
        }
    }
}

void updateItem() {
    int index;
    displayItems();
    printf("Enter the item number to update: ");
    scanf("%d", &index);
    if (index > 0 && index <= itemCount) {
        index--; // convert to zero-based index
        printf("Enter new quantity: ");
        scanf("%d", &inventory[index].quantity);
        printf("Enter new price: ");
        scanf("%f", &inventory[index].price);
    } else {
        printf("Invalid item number.\n");
    }
}

void calculateTotalValue() {
    float totalValue = 0;
    for (int i = 0; i < itemCount; i++) {
        totalValue += inventory[i].quantity * inventory[i].price;
    }
    printf("Total inventory value: UGX%.2f\n", totalValue);
}

int main() {
    int choice;

    strcpy(inventory[0].name, "Chocolate");
    inventory[0].quantity = 0;
    inventory[0].price = 5400.0;

    strcpy(inventory[1].name, "Cereal");
    inventory[1].quantity = 0;
    inventory[1].price = 10000.0;

    strcpy(inventory[2].name, "Milk");
    inventory[2].quantity = 0;
    inventory[2].price = 2600.0;

    strcpy(inventory[3].name, "Juice");
    inventory[3].quantity = 0;
    inventory[3].price = 2500.0;

    strcpy(inventory[4].name, "Water");
    inventory[4].quantity = 0;
    inventory[4].price = 1000.0;

    while (1) {
        printf("\nInventory Management System\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Update Item\n");
        printf("4. Calculate Total Value\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                displayItems();
                break;
            case 3:
                updateItem();
                break;
            case 4:
                calculateTotalValue();
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}