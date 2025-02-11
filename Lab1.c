#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100  // Maximum number of records

// Holds part details
typedef struct {
    int partNumber;
    char partName[50];
    float partSize;
    char partSizeMetric[10];
    float partCost;
} Part;

// Global variables
char databaseName[50];  // Stores the database name
Part records[MAX_RECORDS];  // Array to store records
int recordCount = 0;  // Number of records in the database

// Function prototypes
void printAllRecords();
void addRecord();
void deleteRecord();
void printNumRecords();
void printDatabaseSize();
int printNumChanges(int print);
void displayMenu();

int main(int argc, char *argv[]) {
    // Check if database name is provided
    if (argc < 2) {
        printf("Error: Please provide a database name.\n");
        return 1;
    }

    // Store database name
    strcpy(databaseName, argv[1]);

    int choice;
    do {
        displayMenu();
        printf("Please enter your selection > ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: printAllRecords(); break;
            case 2: addRecord(); break;
            case 3: deleteRecord(); break;
            case 4: printNumRecords(); break;
            case 5: printDatabaseSize(); break;
            case 6: printNumChanges(1); break;
            case 7: printf("Exiting program...\n"); break;
            default: printf("Invalid selection. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}

// Function to display menu
void displayMenu() {
    printf("\n=== %s Database Menu ===\n", databaseName);
    printf("1. Print all records\n");
    printf("2. Add a record\n");
    printf("3. Delete the last record\n");
    printf("4. Print number of records\n");
    printf("5. Print database size\n");
    printf("6. Print number of changes\n");
    printf("7. Exit\n");
}

// Function to print all records
void printAllRecords() {
    if (recordCount == 0) {
        printf("No records in the database.\n");
        return;
    }
    
    printf("Database Records:\n");
    for (int i = 0; i < recordCount; i++) {
        printf("\tRecord %d:\n", i + 1);
        printf("\t\tPart Number: %d\n", records[i].partNumber);
        printf("\t\tPart Name: %s\n", records[i].partName);
        printf("\t\tPart Size: %.2f %s\n", records[i].partSize, records[i].partSizeMetric);
        printf("\t\tPart Cost: $%.2f\n", records[i].partCost);
    }
}

// Function to add a record
void addRecord() {
    if (recordCount >= MAX_RECORDS) {
        printf("Database is full. Cannot add more records.\n");
        return;
    }

    Part newPart;

    printf("Enter Part Number: ");
    scanf("%d", &newPart.partNumber);
    
    printf("Enter Part Name: ");
    scanf("%s", newPart.partName);
    
    printf("Enter Part Size: ");
    scanf("%f", &newPart.partSize);
    
    printf("Enter Part Size Metric: ");
    scanf("%s", newPart.partSizeMetric);
    
    printf("Enter Part Cost: ");
    scanf("%f", &newPart.partCost);

    // Store the new record in the global array
    records[recordCount] = newPart;
    recordCount++;  // Increase the number of stored records

    printf("Record added successfully.\n");

    printNumChanges(0);  // Increment change count
}

// Function to delete the last record
void deleteRecord() {
    if (recordCount == 0) {
        printf("No records to delete.\n");
        return;
    }

    recordCount--;  // Remove last record
    printf("Last record deleted successfully.\n");

    printNumChanges(0);  // Increment change count
}

// Function to print number of records
void printNumRecords() {
    printf("Number of records: %d\n", recordCount);
}

// Function to print database size (in bytes)
void printDatabaseSize() {
    printf("Database size: %lu bytes\n", recordCount * sizeof(Part));
}

// Function to track number of changes
int printNumChanges(int print) {
    static int changeCount = 0;

    if (print) {
        printf("You have modified the database %d times.\n", changeCount);
    } else {
        changeCount++;
        printf("%d modifications so far.\n", changeCount);
    }
    return changeCount;
}
