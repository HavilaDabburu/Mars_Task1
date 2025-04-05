#include <stdio.h>

// Function to decode
void decode(char code[], int n) {
    for (int i = 0; i < n && code[i] != '\0'; i++) {
        // Convert lowercase to uppercase
        if (code[i] >= 'a' && code[i] <= 'z') {
            code[i] = code[i] - 32;
        }

        // Decode uppercase letters
        if (code[i] >= 'A' && code[i] <= 'Z') {
            code[i] = code[i] - i - 1;

            // Wrap around if below 'A'
            if (code[i] < 'A') {
                code[i] = code[i] + 26;
            }

            printf("%c", code[i]);  // Print decoded character
        }
        else if (code[i] == ' ') {
            printf(" ");  // Keep spaces
        }
        else {
            printf("\nInvalid input: only alphabets and spaces are allowed.\n");
            return;
        }
    }

    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of input array: ");
    scanf("%d", &n);
    getchar(); // consume the newline left by scanf

    char code[n];
    printf("Enter the code: ");
    scanf(" %[^\n]", code); // read input with spaces

    decode(code, n);
    return 0;
}

