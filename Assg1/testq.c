#include <stdio.h>

void printNumbersReverse(int n) {
    if (n == 1) {
        printf("%d", n); // Base case: print the first number without space
    } else {
        printNumbersReverse(n - 1); // Recursively call printNumbersReverse with n-1
        printf(" %d", n); // Print the current number followed by a space
    }
}

int main() {
    int N;
    printf("Enter a positive integer N: ");
    scanf("%d", &N);

    if (N > 0) {
        printf("Numbers from %d to 1 in reverse order: ", N);
        printNumbersReverse(N);
        printf("\n");
    } else {
        printf("Please enter a positive integer.\n");
    }

    return 0;
}