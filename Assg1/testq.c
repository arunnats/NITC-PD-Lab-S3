
#include <stdio.h>

double factorial(int num) {
    if (num == 1 || num == 0) {
        return 1.0; // Base case: factorial of 0 and 1 is 1
    } else {
        return num * factorial(num - 1); // Recursive call to calculate factorial
    }
}

double power(double base, int exp) {
    double ans = 1.0;
    for (int i = 0; i < exp; i++) {
        ans *= base;
    }
    return ans;
}
void main() {
    int x, n;
    scanf("%d", &x);
    scanf("%d", &n);
    double rad_x = x * (3.1415 / 180.0), sum = 0.0;

    for (int i = 0; i <= n; i++) {
        int sign = (i % 2 == 0) ? 1 : -1; // Alternate the sign of each term
        double term = (sign * power(rad_x, 2 * i + 1)) / factorial(2 * i + 1);
        sum += term;
    }

    printf("%.4f", sum);
}