
#include <stdio.h>
#include <stdlib.h>
#include "store.c"

// Function prototypes
void addComputer(Computer computer);
void modifyComputer(int id, Computer computer);
void deleteComputer(int id);
int searchComputer(int id);
void displayComputers();

int main()
{
    int choice;
    int id;
    Computer computer;

    while (1)
    {
        printf("1. Add a computer\n");
        printf("2. Modify a computer\n");
        printf("3. Delete a computer\n");
        printf("4. Search for a computer\n");
        printf("5. Display all computers\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                // Add a new computer
                printf("Enter the computer's ID: ");
                scanf("%d", &computer.id);
                printf("Enter the computer's model: ");
                scanf("%s", computer.model);
                printf("Enter the computer's price: ");
                scanf("%f", &computer.price);
                printf("Enter the computer's quantity: ");
                scanf("%d", &computer.quantity);
                printf("Enter the computer's sold: ");
                scanf("%d", &computer.sold);
                addComputer(computer);
                break;
            case 2:
                // Modify an existing computer
                printf("Enter the ID of the computer to modify: ");
                scanf("%d", &id);
                printf("Enter the computer's new model: ");
                scanf("%s", computer.model);
                printf("Enter the computer's new price: ");
                scanf("%f", &computer.price);
                printf("Enter the computer's new quantity: ");
                scanf("%d", &computer.quantity);
                printf("Enter the computer's new sold: ");
                scanf("%d", &computer.sold);
                modifyComputer(id, computer);
                break;
            case 3:
                // Delete a computer
                printf("Enter the ID of the computer to delete: ");
                scanf("%d", &id);
                deleteComputer(id);
                break;
            case 4:
                // Search for a computer
                printf("Enter the ID of the computer to search for: ");
                scanf("%d", &id);
                if (searchComputer(id) == 1)
                {
                    printf("Computer found!\n");
                }
                else
                {
                    printf("Computer not found!\n");
                }
                break;
            case 5:
                // sort the computers by sold
                sortComputersBySold();
                break;
            case 6:
                // Display all computers
                displayComputers();
                break;
            case 7:
                // Exit the program
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}
