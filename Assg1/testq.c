#include <stdio.h>

#define MAX_LENGTH 100

char findMostFrequentChar(const char *str) {
    int freq[256] = {0}; // Initialize frequency array to count characters
    int n = 0;

    // Step 2: Create the fancy string and count its length
    char fancyStr[MAX_LENGTH * (MAX_LENGTH + 1) / 2];
    int k = 0;

    while (str[n] != '\0') {
        for (int i = 0; i <= n; i++) {
            fancyStr[k++] = str[n];
        }
        n++;
    }
    fancyStr[k] = '\0'; // Null-terminate the fancy string

    // Step 3: Count the frequency of each character in the fancy string
    n = k; // Update n to the length of the fancy string
    for (int i = 0; i < n; i++) {
        char ch = fancyStr[i];
        freq[ch]++;
    }

    // Step 4: Find the character with the maximum frequency
    char mostFrequentChar = fancyStr[0];
    int maxFrequency = freq[fancyStr[0]];

    for (int i = 1; i < n; i++) {
        char ch = fancyStr[i];
        if (freq[ch] > maxFrequency) {
            mostFrequentChar = ch;
            maxFrequency = freq[ch];
        }
    }

    return mostFrequentChar;
}

int main() {
    char str[MAX_LENGTH];
    printf("Enter the input string: ");
    scanf("%s", str);

    char mostFrequentChar = findMostFrequentChar(str);
    printf("The character that appears most frequently in the fancy string is: %c\n", mostFrequentChar);

    return 0;
}
