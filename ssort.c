#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ssort.h"

int main(int argc, char *argv[])
{
    // Bad argument count error
    if (argc < 4)
    {
        fprintf(stderr, "Usage: ssort <inputfile> <n> <wtype> <sorttype> [<skipword1> <skipword2> ...]\n");
        return 1;
    }

    char *filename = argv[1];
    int n = atoi(argv[2]);
    // Bad array size error
    if (n <= 0)
    {
        fprintf(stderr, "Invalid array size\n");
        return 1;
    }
    // Bad word type error
    char *wtype = argv[3];
    if (strcmp(wtype, "ALPHA") != 0 && strcmp(wtype, "ALPHANUM") != 0 && strcmp(wtype, "ALL") != 0)
    {
        fprintf(stderr, "Invalid word type\n");
        return 2;
    }

    // Determines if the sorting argument is present, if not defaults to ascending
    char *sorttype = (argc > 4 && (strcmp(argv[4], "ASC") == 0 || strcmp(argv[4], "DESC") == 0)) ? argv[4] : "ASC";
    // Checks it again so that it doesn't skip over a skip word by assuming it's the sorting argument
    char **skipwords = (argc > 4 && (strcmp(argv[4], "ASC") == 0 || strcmp(argv[4], "DESC") == 0)) ? &argv[5] : &argv[4];
    int skipcount = argc - (skipwords - argv);

    char *words[n];
    int word_count = 0;

    // Read the words
    read_words_from_file(filename, wtype, n, skipwords, skipcount, words, &word_count);

    // Sort then print the words
    print_sorted_words(words, word_count, sorttype);

    return 0;
}