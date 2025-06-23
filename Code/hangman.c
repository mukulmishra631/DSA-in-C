// hangman.c
// Source file for the Hangman game project.

// Include necessary standard library header files
#include <stdio.h>  // For FILE, fopen, fclose, fgets, printf, fprintf, perror, stderr, ferror, rewind, EOF
#include <stdlib.h> // For malloc, free, rand, srand, exit, size_t, RAND_MAX
#include <string.h> // For strlen, strcpy, strcmp, strchr
#include <time.h>   // For time
#include <ctype.h>  // For tolower(), isalpha() (will be needed later)

// Define constants used throughout the game
#define MAX_WORD_LENGTH 100 // Maximum characters expected for a word + newline + null terminator

// --- Game Constants ---
#define MAX_INCORRECT_GUESSES 6 // Maximum number of allowed incorrect guesses (standard Hangman)

// --- Function Prototypes ---

char **loadWords(const char *filename, int *wordCount);
void freeWordList(char **wordList, int wordCount);
// We will add prototypes for game functions later (e.g., drawHangman)

// --- Function Definitions ---

// ... (loadWords function definition remains unchanged) ...
char **loadWords(const char *filename, int *wordCount) {
    *wordCount = 0; // Initialize output parameter at the start
    FILE *file = NULL;
    char **wordList = NULL;
    char lineBuffer[MAX_WORD_LENGTH];
    int lineCount = 0; // Initial count from first pass
    int i = 0; // Index, also tracks successfully processed words in second pass
    char *currentWord = NULL;

    // --- File Opening & Counting (Tasks 5-7) ---
    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot open word file '%s'. ", filename);
        perror(NULL); // Print system error message related to fopen failure
        return NULL;
    }
    while (fgets(lineBuffer, MAX_WORD_LENGTH, file) != NULL) { lineCount++; }
    if (ferror(file)) {
         fprintf(stderr, "Error: Failed to read from word file '%s'. ", filename);
         perror(NULL);
         fclose(file); return NULL;
    }
    if (lineCount == 0) {
        fprintf(stderr, "Error: Word file '%s' is empty.\n", filename);
        fclose(file); return NULL;
    }

    // --- Rewind (Task 8) ---
    rewind(file);

    // --- Allocate wordList (Task 9) & Check (Task 10) ---
    size_t listSize = lineCount * sizeof(char *);
    wordList = (char **)malloc(listSize);
    if (wordList == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for word list (%d words). ", lineCount);
        perror(NULL);
        fclose(file); return NULL;
    }
    for(int k=0; k < lineCount; ++k) { wordList[k] = NULL; } // Initialize pointers

    // --- Second Pass: Read, Allocate, Copy, Store (Tasks 11-16) ---
    i = 0; // Reset index for storing words
    while (i < lineCount && fgets(lineBuffer, MAX_WORD_LENGTH, file) != NULL) {
        // Task 12: Remove trailing newline & re-calculate len
        size_t len = strlen(lineBuffer);
        if (len > 0 && lineBuffer[len - 1] == '\n') {
            lineBuffer[len - 1] = '\0';
            len = strlen(lineBuffer);
        }
        if (len == 0) { continue; } // Skip empty lines

        // Task 13: Allocate memory for individual word string
        size_t wordMemorySize = len + 1;
        currentWord = (char *)malloc(wordMemorySize);

        // Task 14: Check word memory allocation success (includes full cleanup on failure)
        if (currentWord == NULL) {
            fprintf(stderr, "Error: Failed to allocate memory for word #%d. ", i + 1);
            perror(NULL);
            // Cleanup previously allocated words and list
            for (int j = 0; j < i; j++) { if (wordList[j] != NULL) { free(wordList[j]); } }
            free(wordList);
            fclose(file);
            return NULL;
        }
        // Task 15: Copy the cleaned word into the allocated space
        strcpy(currentWord, lineBuffer);
        // Task 16: Store the pointer in the word list array
        wordList[i] = currentWord;
        i++; // Increment index *after* success
    } // End of while(fgets...) loop

    // --- Check for read errors after the second pass loop ---
    if (ferror(file)) {
         fprintf(stderr, "Error: Failed reading word file '%s' during loading. ", filename);
         perror(NULL);
         // Cleanup previously allocated words and list
         for (int j = 0; j < i; j++) { if (wordList[j] != NULL) { free(wordList[j]); } }
         free(wordList);
         fclose(file); // Close file even on error
         return NULL;
    }

    // Final count of successfully processed words is 'i'
    int finalWordCount = i;

    // --- Task 17: Close the file (`fclose`). ---\
    if (fclose(file) == EOF) { perror("Warning: Error closing file"); }

    // If finalWordCount is 0 after skipping lines, treat as error
    if (finalWordCount == 0 && lineCount > 0) {
         fprintf(stderr, "Error: No valid words found in '%s' after processing.\n", filename);
         free(wordList); // Free the allocated list array
         return NULL;
    }

    // --- Task 18: Set the `wordCount` output parameter. ---\
    *wordCount = finalWordCount;

    // --- Task 19: Return the pointer to the array of word pointers. ---\
    printf("INFO: Successfully loaded %d words from '%s'.\n", finalWordCount, filename);
    return wordList;
}

// ... (freeWordList function definition remains unchanged) ...
void freeWordList(char **wordList, int wordCount) {
    if (wordList == NULL) {
        return; // Nothing to free
    }
    // printf("\nDEBUG: Freeing word list memory...\n"); // Optional debug
    for (int i = 0; i < wordCount; i++) {
        if (wordList[i] != NULL) {
            free(wordList[i]);
            wordList[i] = NULL;
        }
    }
    free(wordList);
    // printf("DEBUG: Word list memory freed.\n"); // Optional debug
}

// --- Main Function ---

int main() {
    // Seed the random number generator
    srand(time(NULL));

    printf("Welcome to Hangman!\n\n");

    // --- Load Words (Step 1) ---
    int loadedWordCount = 0;
    const char *wordFileName = "words.txt";
    char **wordListMain = NULL;

    printf("Loading words from %s...\n", wordFileName);
    wordListMain = loadWords(wordFileName, &loadedWordCount);

    // Check loading result
    if (wordListMain == NULL || loadedWordCount <= 0) {
        fprintf(stderr, "Error: Failed to initialize word list. Cannot start game.\n");
        if (wordListMain != NULL) { freeWordList(wordListMain, loadedWordCount); }
        return 1; // Indicate failure
    }
    printf("Word list loaded successfully. Ready to play!\n\n");

    // --- Select a Random Word (Step 2) ---
    int randomIndex = rand() % loadedWordCount;
    char *secretWord = wordListMain[randomIndex];
    printf("DEBUG: Random word selected: %s\n", secretWord); // Keep for debugging for now

    // --- Initialize Game State (Step 3) ---

    // Task 3.1: Define max incorrect guesses (using constant defined above)
    // The constant MAX_INCORRECT_GUESSES is now available here.
    printf("DEBUG: Maximum incorrect guesses allowed: %d\n", MAX_INCORRECT_GUESSES);

    // --- Placeholder for subsequent game logic and state initialization ---
    // Task 3.2: Initialize incorrect guess counter
    // Task 3.3: Calculate secretWord length
    // Task 3.4: Create displayWord array
    // Task 3.5: Initialize displayWord with underscores
    // Task 3.6: Ensure displayWord null termination
    // Task 3.7: Create guessedLetters array
    // Task 3.8: Initialize gameOver flag
    // Task 3.9: Initialize playerWon flag

    // --- Game Loop (Step 4 onwards - Placeholder) ---
    printf("\nDEBUG: Game logic starts now...\n");

    // --- Memory cleanup ---
    freeWordList(wordListMain, loadedWordCount);

    printf("\nGame Over. Thanks for playing!\n");
    return 0; // Indicate successful execution
}
