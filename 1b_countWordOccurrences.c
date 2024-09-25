#include <stdio.h>
#include <string.h>
#include <ctype.h>

void countWordOccurrences(char text[]) {
    char* word;
    char* delimiters = " ,.!?;:\"'\n\t"; // Add any other punctuation marks as needed
    char textCopy[strlen(text) + 1]; // Create a copy of the input text for modification
    strcpy(textCopy, text);

    word = strtok(textCopy, delimiters);

    while (word != NULL) {
        printf("%s: ", word);
       
        // Count the occurrences of the current word in the original text
        int count = 0;
        char* searchPtr = text;
       
        while ((searchPtr = strstr(searchPtr, word)) != NULL) {
            // Check if the word is a separate word and not part of a larger word
            if ((searchPtr == text || !isalnum(searchPtr[-1])) && !isalnum(searchPtr[strlen(word)])) {
                count++;
            }
            searchPtr++;
        }
       
        printf("%d\n", count);
        word = strtok(NULL, delimiters);
    }
}

int main() {
    char text[] = "This is a sample text. It contains sample words, some of which are repeated.";
    countWordOccurrences(text);
    return 0;
}
