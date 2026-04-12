#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 0;
    int y = 0;
    int count = 0;
    int sum = 0;

    printf("How many numbers do you want to enter? \n");

    // ✅ SAFE INPUT CHECK
    if (scanf("%d", &x) != 1) {
        printf("Invalid input. Please enter a number.\n");
        return 1;
    }


    // ✅ VALIDATE RANGE
    if (x <= 2) {
        printf("Please enter a number greater than 2.\n");
        return 1;
    }

    for (int i = 0; i < x; i++) {

        printf("Enter number %d: ", i + 1);

        // ✅ SAFE SCAN
        if (scanf("%d", &y) != 1) {
            printf("Invalid input. Stopping program.\n");
            return 1;
        }

        // Optional stop condition (kept from your idea)
        if (y == 1) {
            printf("Stop value (1) entered. Breaking loop.\n");
            break;
        }

        count++;
        sum += y;

        printf("Current Sum: %d\n", sum);

        if (sum % 2 == 0) {
            printf("Sum is Even: %d\n", sum);
        } else {
            printf("Sum is Odd: %d\n", sum);
        }
    }

    printf("\nFinal Results:\n");
    printf("Count of valid inputs: %d\n", count);
    printf("Final sum: %d\n", sum);

    return 0;
}
