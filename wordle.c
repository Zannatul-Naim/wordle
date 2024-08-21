#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WORD_LENGTH 5
#define MAX_ATTEMPTS 6
#define MAX_WORDS 1000

char wordList[MAX_WORDS][WORD_LENGTH + 1];  // Array to hold the words from the file

// ANSI color codes
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define RESET   "\033[0m"
#define RED    "\033[1;31m"

int loadWords(const char* file_name) {
    FILE* file = fopen(file_name, "r");

    if(file == NULL) {
        printf("\t\tError: could not open %s\n", file_name);
        exit(1);
    }
    int wordCount = 0;

    while(fscanf(file, "%s", wordList[wordCount]) != EOF && wordCount < MAX_WORDS) {
        if(strlen(wordList[wordCount]) == WORD_LENGTH) {
            wordCount++;
        }
    }
    
    fclose(file);

    return wordCount;
}

void checkGuess(const char* word, const char* guess) {
    char result[WORD_LENGTH + 1];

    printf("\t\t\t");

    for (int i = 0; i < WORD_LENGTH; i++) {
        if (guess[i] == word[i]) {
            printf(GREEN "%c" RESET, guess[i]);  // Green for correct position
        } else if (strchr(word, guess[i])) {
            printf(YELLOW "%c" RESET, guess[i]);  // Yellow for correct letter, wrong position
        } else {
            printf(RED "%c" RESET, guess[i]);  // RED for incorrect letter
        }
    }
    printf("\n");
}

int main() {
    srand(time(0));  // Seed random number generator

   int wordCount = loadWords("wordList.txt");

    if(wordCount == 0) {
        printf("\t\t\tNo valid words loaded from the file. \n");
        return 1;
    }

    const char* word = wordList[rand() % wordCount];

    char guess[WORD_LENGTH + 1];
    int attempts = 0;

    printf("\n\t\t\t\tWelcome to Wordle!\n\n\n");

    while (attempts < MAX_ATTEMPTS) {
        printf("\t\tAttempt %d: Enter your guess: ", attempts + 1);
        scanf("%s", guess);

        if (strlen(guess) != WORD_LENGTH) {
            printf("\t\t\tInvalid input. Please enter a %d-letter word.\n", WORD_LENGTH);
            continue;
        }

        checkGuess(word, guess);

        if (strcmp(guess, word) == 0) {
            printf("\t\t\tCongratulations! You've guessed the word.\n");
            return 0;
        }

        attempts++;
    }

    printf("\n\t\t\tSorry, you've used all attempts. The word was: %s\n", word);

    return 0;
}
