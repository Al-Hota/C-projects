#include <stdio.h>
#include <stdlib.h>


int main() {
    int x = 10;
    int *ptr = &x; // ptr now holds the address of x

    printf("Value of x: %d\n", x); // Output: 10
    printf("Address of x: %p\n", (void*)&x); // Output: Address of x
    printf("Value of ptr (address of x): %p\n", (void*)ptr); // Output: Address of x
    printf("Value pointed to by ptr (*ptr): %d\n", *ptr); // Output: 10

    return 0;
}