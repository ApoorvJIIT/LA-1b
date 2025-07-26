#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define WORD_LEN 50

// Convert a string to lowercase
void toLowerCase(char* str) {
    for(int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}

// Remove punctuation from a word (like comma, dot, etc.)
void cleanWord(char* word) {
    int i, j = 0;
    char temp[WORD_LEN];
    for(i = 0; word[i]; i++) {
        if (isalnum(word[i])) {
            temp[j++] = tolower(word[i]);
        }
    }
    temp[j] = '\0';
    strcpy(word, temp);
}

int main() {
    char paragraph[1000];
    char words[MAX_WORDS][WORD_LEN];
    int count[MAX_WORDS] = {0};
    int totalWords = 0;

    printf("Enter a paragraph:\n");
    fgets(paragraph, sizeof(paragraph), stdin);

    char *token = strtok(paragraph, " \n\t");

    while (token != NULL) {
        cleanWord(token);

        int found = 0;
        for (int i = 0; i < totalWords; i++) {
            if (strcmp(words[i], token) == 0) {
                count[i]++;
                found = 1;
                break;
            }
        }

        if (!found && strlen(token) > 0) {
            strcpy(words[totalWords], token);
            count[totalWords] = 1;
            totalWords++;
        }

        token = strtok(NULL, " \n\t");
    }

    printf("\nWord Frequencies:\n");
    for (int i = 0; i < totalWords; i++) {
        printf("%s: %d\n", words[i], count[i]);
    }

    return 0;
}
