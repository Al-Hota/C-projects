#include <stdio.h>
#include <stdlib.h>

void safe_input_check(int *x){
    if (scanf("%d", x) != 1) {
        printf("Invalid input.\n");
        exit(1);
    }
}
void safe_input_check_char(char *x){
    if (scanf(" %c", x) != 1) {
        printf("Invalid input.\n");
        exit(1);
    }
}


int addition(int a, int b){
    return a + b;
}

int subtraction(int a, int b){
    return a - b;
}

int multiplication(int a, int b){
    return a * b;
}

float division(int a, int b){
    if (b == 0){
        printf("Error: Division by zero.\n");
        exit(1);
    }
    return (float)a / b;
}

float percentagecalc(int a, int b){
    if (b == 0){
        printf("Error: Division by zero.\n");
        exit(1);
    }
    return ((float)a / b) * 100;
}

int main() {
    int choice;
    int a, b;
    int loop = 1;
    while (loop) {
        printf("=== Simple Calculator ===\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Percentage\n");
        printf("Enter choice: \n");
        safe_input_check(&choice);

        if (choice < 1 || choice > 5){
            printf("Invalid choice. Please select a number between 1 and 5.\n");
            continue;
        }

        printf("Enter number 1: ");
        safe_input_check(&a);

        printf("Enter number 2: ");
        safe_input_check(&b);
        switch(choice){
            case 1:
                printf("Result: %d\n", addition(a, b));
                break;
            case 2:
                printf("Result: %d\n", subtraction(a, b));
                break;
            case 3:
                printf("Result: %d\n", multiplication(a, b));
                break;
            case 4:
                printf("Result: %.2f\n", division(a, b));
                break;
            case 5:
                printf("Result: %.2f%%\n", percentagecalc(a, b));
                break;
        }
        char continue_choice;
        printf("Would you like to continue? (Y/N)\n");
        printf("Enter Choice:");
        safe_input_check_char(&continue_choice);
       if (continue_choice == 'Y' || continue_choice == 'y') {
        loop = 1;
        } 
        else if (continue_choice == 'N' || continue_choice == 'n') {
        loop = 0;
        } 
        else {
        printf("Invalid input. Please enter Y or N.\n");
        continue;
        }
    }

    return 0;
}
