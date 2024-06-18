#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ssort.h"

/* Reads words from file
@param *filename the file name
@param *wtype the word type (ALPHA, ALPHANUM or ALL)
@param n the array size, so the maximum number of words to read
@param **skipwords words to skip reading
@param skipcount index of current skip word to check
@param *words array to append the words to
@param *word_count number of words in words */
void read_words_from_file(char *filename, char *wtype, int n, char **skipwords, int skipcount, char *words[], int *word_count)
{
    FILE *file = fopen(filename, "r");
    // Bad file error (not found etc.)
    if (!file)
    {
        perror("Error opening file");
        exit(1);
    }

    char buffer[MAX_WORD_LENGTH];
    // Read each line from the file into the buffer until end of file or max word count
    while (fgets(buffer, sizeof(buffer), file) && *word_count < n)
    {
        // Lines are split into tokens using spaces, tabs, newlines and commas as split points
        char *token = strtok(buffer, " ,\t\n");
        // Loop until all tokens are read or max word count is reached
        while (token != NULL && *word_count < n)
        {
            // Validate if it's a valid word and that it's not a skip word
            if (is_word(token, wtype) && !is_skip_word(token, skipwords, skipcount))
            {
                // If it's valid, copy unto the words array
                words[*word_count] = strdup(token);
                (*word_count)++;
            }
            // Otherwise, go to next token
            token = strtok(NULL, " ,\t\n");
        }
    }
    fclose(file);
}