#include <stdio.h>
#include <stdlib.h>

void safe_input_check(int *x) {
    if (scanf("%d", x) != 1) {
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

int division(int a, int b){
    if (b == 0){
        printf("Error: Division by zero.\n");
        exit(1);
    }
    return a / b;
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

    printf("=== Simple Calculator ===\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Percentage\n");
    printf("Enter choice: ");
    safe_input_check(&choice);

    if (choice < 1 || choice > 5){
        printf("Invalid choice\n");
        return 1;
    }

    printf("Enter number 1: ");
    safe_input_check(&a);

    printf("Enter number 2: ");
    safe_input_check(&b);

    if (choice == 1)
        printf("Result: %d\n", addition(a, b));
    else if (choice == 2)
        printf("Result: %d\n", subtraction(a, b));
    else if (choice == 3)
        printf("Result: %d\n", multiplication(a, b));
    else if (choice == 4)
        printf("Result: %d\n", division(a, b));
    else if (choice == 5)
        printf("Result: %.2f%%\n", percentagecalc(a, b));

    return 0;
}