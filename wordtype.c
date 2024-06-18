#include <ctype.h>
#include <string.h>
#include "ssort.h"

/* Checks if the string in parameter is a word. ALPHA: Only a word if letters. ALPHANUM: Only a word if letters and numbers
@param *str the word to check
@param *wtype the word type (ALPHA, ALPHANUM or ALL) */
int is_word(char *str, char *wtype)
{
    // If alpha, check every character
    if (strcmp(wtype, "ALPHA") == 0)
    {
        while (*str)
        {
            // If it's not alpha, return false
            if (!isalpha(*str))
                return 0;
            str++;
        }
    }
    // If alphanum, check every character
    else if (strcmp(wtype, "ALPHANUM") == 0)
    {
        while (*str)
        {
            // If it's not alphanum, return false
            if (!isalnum(*str))
                return 0;
            str++;
        }
    }
    // Otherwise, return true
    return 1;
}

/* Checks if the string in parameter is a skip word 
@param *word the word to check
@param **skipwords the list of words to skip
@param skipcount index of the current skip word*/
int is_skip_word(char *word, char **skipwords, int skipcount)
{
    // Check every word in the skip list
    for (int i = 0; i < skipcount; i++)
    {
        // If the word read is in the list, return true
        if (strcmp(word, skipwords[i]) == 0)
            return 1;
    }
    // Otherwise, return false
    return 0;
}