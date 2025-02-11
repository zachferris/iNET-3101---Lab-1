# README.txt

## Program Information
**Author:** Zach Ferris
**Program Name:** Simple In-Memory Database (Lab 1)
**Description:** 
The program is a very simple menu-driven interface to interact with an in-memory database.
It also allows users to add, delete, and display records, all while checking database statistics.

## Menu Options
1. Print all records
2. Add a record
3. Delete the last record
4. Print number of records
5. Print database size
6. Print number of changes
7. Exit

The program will repeatedly display this menu until the user selects the Exit option which is number 7.

## Functions and Their Behavior

### `void printAllRecords()`
- **Input:** None
- **Output:** Prints a message which lists all records.
- **Description:** Prints a message that shows this function was called. 

### `void addRecord()`
- **Input:** User inputs values for:
  - Part number (integer)
  - Part name (string)
  - Part size (float)
  - Part size metric (string)
  - Part cost (float)
- **Output:** Prints the entered record details.
- **Description:** Prompts user for each field and prints entered values.

### `void deleteRecord()`
- **Input:** None
- **Output:** Prints a message which shows deletion of records.
- **Description:** Simulates record deletion by printing a message.

### `void printNumRecords()`
- **Input:** None
- **Output:** Prints a placeholder message.
- **Description:** Displays the number of records.

### `void printDatabaseSize()`
- **Input:** None
- **Output:** Prints a placeholder message.
- **Description:** Displays database size.

### `int printNumChanges(int print)`
- **Input:** Boolean-like integer (1 for print, 0 for increment).
- **Output:** Prints number of changes if `print` is `1`, otherwise increments changes count.
- **Description:** Uses a static variable to track changes.

## Files in the Project
- Lab1.c → The main source file containing the program logic.
- README.txt → This design document.
- `executable (compiled file)` → Compiled version of the program.

## Command Line Arguments
- The program requires a **database name** as a command-line argument.
- Compile: gcc Lab1.c -o databaseProgram
- Example usage: ./databaseProgram MyDatabase
