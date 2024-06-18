// Security check so it's not redefined in every class
#ifndef SSORT_H
#define SSORT_H

// Predefined max word length to give enough space for the buffer
#define MAX_WORD_LENGTH 100

// Prototype functions so they can be used in the different files
int is_word(char *str, char *wtype);
int is_skip_word(char *word, char **skipwords, int skipcount);
void read_words_from_file(char *filename, char *wtype, int n, char **skipwords, int skipcount, char *words[], int *word_count);
void print_sorted_words(char *words[], int word_count, char *sorttype);

#endif