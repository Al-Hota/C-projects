#include <stdio.h>
#include <stdlib.h>

#define FILE_SIZE 256

void safe_input_check(int *x) {
    if (scanf("%d", x) != 1) {
        printf("Invalid input. Please enter a number.\n");
        exit(1);
    }
}

void safe_input_check_char(char *x) {
    if (scanf(" %c", x) != 1) {
        printf("Invalid input. Please enter a character.\n");
        exit(1);
    }
}

void display_file_content(int choice, char file1[], char file2[], char file3[]) {
    switch (choice) {
        case 1: printf("%s", file1); break;
        case 2: printf("%s", file2); break;
        case 3: printf("%s", file3); break;
        default: printf("Invalid choice.\n");
    }
}

void edit(int choice, char file1[], char file2[], char file3[]) {
    char edit_choice;

    printf("Would you like to edit this file? (y/n): ");
    safe_input_check_char(&edit_choice);

    if (edit_choice == 'y' || edit_choice == 'Y') {

        char new_content[256];
        printf("Enter new content: ");
        scanf(" %[^\n]", new_content);

        if (choice == 1) {
            snprintf(file1, FILE_SIZE, "File 1: %s\n", new_content);
        } else if (choice == 2) {
            snprintf(file2, FILE_SIZE, "File 2: %s\n", new_content);
        } else if (choice == 3) {
            snprintf(file3, FILE_SIZE, "File 3: %s\n", new_content);
        }

        printf("File updated successfully.\n");
    } else {
        printf("No changes made.\n");
    }
}

int main(void) {
    char file1[FILE_SIZE] = "File 1: This is the content of file 1.\n";
    char file2[FILE_SIZE] = "File 2: This is the content of file 2.\n";
    char file3[FILE_SIZE] = "File 3: This is the content of file 3.\n";

    int choice;

    printf("==== TO DO FILES ====\n");
    printf("Select a file:\n1. File 1\n2. File 2\n3. File 3\n");

    safe_input_check(&choice);

    display_file_content(choice, file1, file2, file3);
    edit(choice, file1, file2, file3);

    return 0;
}