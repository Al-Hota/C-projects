#include <stdio.h>
#include <stdlib.h>


void safe_input_check(int *x) {
    if (scanf("%d", x) != 1) {
        printf("Invalid input. Please enter a number.\n");
        exit(1);
    }
}

int getSum(int arr[], int size){
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum += arr[i];
    }
    return sum;
}

int getMax(int arr[], int size){
    int max = arr[0];
    for (int i = 1; i < size; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

int countEven(int arr[], int size){
    int count = 0;
    for (int i = 0; i < size; i++){
        if (arr[i] % 2 == 0){
            count++;
        }
    }
    return count;
}


int main() {

    int arr[100];
    int x = 0;

    printf("How many numbers: ");
    safe_input_check(&x);

    if (x <= 0){
        printf("Invalid size\n");
        return 1;
    }

    printf("Enter %d numbers:\n", x);

    for (int i = 0; i < x; i++){
        printf("Enter number %d: ", i + 1);
        safe_input_check(&arr[i]);
    }

    printf("Sum: %d\n", getSum(arr, x));
    printf("Max: %d\n", getMax(arr, x));
    printf("Even count: %d\n", countEven(arr, x));

    return 0;
}

