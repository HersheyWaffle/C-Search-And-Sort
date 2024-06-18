#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ssort.h"

/*Called in QSort to sort in ascending order
@param *a generic pointer for qsort
@param *b generic pointer for qsort*/
int compare_asc(const void *a, const void *b)
{
    // Compare the two strings lexicographically for ascending order
    return strcmp(*(const char **)a, *(const char **)b);
}

/*Called in qsort to sort in descending order
@param *a generic pointer for qsort
@param *b generic pointer for qsort*/
int compare_desc(const void *a, const void *b)
{
    // Compare the two strings reverse lexicographically for descending order
    return strcmp(*(const char **)b, *(const char **)a);
}

/*Prints sorted words
@param *words the list of words to sort
@param word_count the number of words in the list
@param *sorttype the sorting type (ASC for ascending and DESC for descending)*/
void print_sorted_words(char *words[], int word_count, char *sorttype)
{
    // Function sorts the words according to the parameters
    qsort(words, word_count, sizeof(char *), (strcmp(sorttype, "DESC") == 0) ? compare_desc : compare_asc);

    // For each word in the list
    for (int i = 0; i < word_count; i++)
    {
        // Print the word
        printf("%s", words[i]);
        // If it's the tenth word, print a newline
        if ((i + 1) % 10 == 0)
        {
            printf("\n");
        }
        // Otherwise print a space between the words
        else
        {
            printf(" ");
        }
        // Free the memory since we don't need it
        free(words[i]);
    }
    // Print a newline at the end only if not multiple of 10
    //since otherwise it's already printed in the for loop
    if (word_count % 10 != 0)
    {
        printf("\n");
    }
}