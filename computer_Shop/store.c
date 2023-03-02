#include <stdio.h>
#include <string.h>
#include "computer.c"
#define FILE_NAME "store.dat"
void showComputer(Computer c)
{
    printf("ID: %d\n", c.id);
    printf("Model: %s\n", c.model);
    printf("Price: %.2f\n", c.price);
    printf("Quantity: %d\n", c.quantity);
    printf("Sold: %d\n", c.sold);
    printf("\n");
}
void addComputer(Computer computer)
{
    FILE* fp = fopen(FILE_NAME, "ab"); // Open the file in append mode

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    // Write the data to the file
    fwrite(&computer, sizeof(Computer), 1, fp);

    fclose(fp); // Close the file
}
void modifyComputer(int id, Computer computer)
{
    FILE* fp = fopen(FILE_NAME, "r+b"); // Open the file in read/write mode

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    // Search for the computer with the specified ID
    Computer c;
    while (fread(&c, sizeof(Computer), 1, fp) == 1)
    {
        if (c.id == id)
        {
            // Update the computer's data
            strcpy(c.model, computer.model);
            c.price = computer.price;
            c.quantity = computer.quantity;

            // Write the updated data to the file
            fseek(fp, -sizeof(Computer), SEEK_CUR); // Move the file pointer back to the start of the record
            fwrite(&c, sizeof(Computer), 1, fp);
            break;
        }
    }

    fclose(fp); // Close the file
}
void deleteComputer(int id)
{
    FILE* fp = fopen(FILE_NAME, "r+b"); // Open the file in read/write mode

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    // Search for the computer with the specified ID
    Computer c;
    while (fread(&c, sizeof(Computer), 1, fp) == 1)
    {
        if (c.id == id)
        {
            // Overwrite the data for the computer with a blank record
            Computer blank = { 0, "", 0.0, 0 };
            fseek(fp, -sizeof(Computer), SEEK_CUR); // Move the file pointer back to the start of the record
            fwrite(&blank, sizeof(Computer), 1, fp);
            break;
        }
    }

    fclose(fp); // Close the file
}
int searchComputer(int id)
{
    FILE* fp = fopen(FILE_NAME, "rb"); // Open the file in read mode

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return 0;
    }

    // Search for the computer with the specified ID
    Computer c;
    while (fread(&c, sizeof(Computer), 1, fp) == 1)
    {
        if (c.id == id)
        {
            fclose(fp); // Close the file
            showComputer(c);
            return 1; // Computer found
        }
    }

    fclose(fp); // Close the file
    return 0; // Computer not found
}
void displayComputers()
{
    FILE* fp = fopen(FILE_NAME, "rb"); // Open the file in read mode

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    // Read and display the data for each computer
    Computer c;
    while (fread(&c, sizeof(Computer), 1, fp) == 1)
    {
        printf("ID: %d\n", c.id);
        printf("Model: %s\n", c.model);
        printf("Price: %.2f\n", c.price);
        printf("Quantity: %d\n", c.quantity);
        printf("\n");
    }

    fclose(fp); // Close the file
}
void sortComputersBySold() {
    FILE *fp = fopen(FILE_NAME, "r+b"); // Open the file in read/write mode

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Read the data for each computer into an array
    Computer computers[100];
    int count = 0;
    while (fread(&computers[count], sizeof(Computer), 1, fp) == 1) {
        count++;
    }

    // Sort the array by sold
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (computers[i].sold < computers[j].sold) {
                Computer temp = computers[i];
                computers[i] = computers[j];
                computers[j] = temp;
            }
        }
    }
    displayComputers();
    // Write the sorted data back to the file
    fseek(fp, 0, SEEK_SET); // Move the file pointer to the start of the file
    for (int i = 0; i < count; i++) {
        fwrite(&computers[i], sizeof(Computer), 1, fp);
    }
}
