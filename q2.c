#include <stdio.h>//header file
#include <string.h>//string operations
#include <stdlib.h>//for dma
int n;//initializing a global variable
//creating a array of constant strings in alphabetical order
const char *morse[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", 
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};
// creating an array of charecters
const char letters[] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 
    'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 
    'W', 'X', 'Y', 'Z'
};
//function to decode the morsecode
void decode(char *code[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        int found = 0; // Flag to check if the code was found
        for (int j = 0; j < 26; j++)
        {
            if (strcmp(morse[j], code[i]) == 0)//Correct string comparison
            {  
                printf("%c", letters[j]);
                found = 1;
                break;  // Exit loop after finding the match
            }
        }
        if (!found) 
        printf("?");  // Print '?' for unrecognized Morse code
    }
    printf("\n");
}
int main() {
    printf("Enter the number of Morse code symbols:\n");
    scanf("%d", &n);
    getchar();  // Consume the leftover newline character
    char *code[n];//initializing a string of arrays
    printf("Enter the Morse code symbols separated by spaces:\n");
    for (int i = 0; i < n; i++)
    {
        //memory allocation for those pointers to avoid buffer overflow
        code[i] = (char *)malloc(10 * sizeof(char));  // Allocate memory for each code
        if (code[i] == NULL)// Memory allocation error handling
        { 
            printf("Memory allocation failed!\n");
            return 1;
        }
        scanf("%s", code[i]);  // Read Morse code symbol
    }
    //calling of a function to decode the morse code
    decode(code, n);
    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(code[i]);
    }
    return 0;
}

