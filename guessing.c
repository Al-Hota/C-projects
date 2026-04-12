#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
    int number, guess, attempts = 0;
    srand(time(0));
    number = rand() % 100 + 1; // Generates a random number between 1 and 100
    printf("Guess a number between 1 and 100, if you fail your computer will destroy itself!\n"); //dont mind this, its just a joke
    do {
        printf("Enter your guess: ");
        if (scanf("%d", &guess) != 1) { //safe input check
            printf("Invalid input. Please enter a number.\n");
            return 1;
        }
        attempts++;
        if (guess < number) {
            printf("Too low! Try again.\n");
        } else if (guess > number) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You've guessed the number in %d attempts.\n", attempts);
            break;

        }
    } while (1);
    return 0;
}