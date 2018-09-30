// https://www.codewars.com/kata/5939ab6eed348a945f0007b2/
//
// When given a string of space separated words, return the word with the longest length. If there are multiple words with the longest length, return the last instance of the word with the longest length.
//
// Example:
// 'red white blue' //returns string value of white
// 'red blue gold' //returns gold
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *longest_word(char *word_str)
{
    int len, max_len = 0;
    char *word, *word_longest = NULL;
    char *s = strdup(word_str);

    word_longest = word = strtok(s, " ");
    max_len = strlen(word);
    while ((word = strtok(NULL, " ")) != NULL) {
        len = strlen(word);
        if (len >= max_len) {
            max_len = len;
            word_longest = (char *)realloc(word_longest, max_len*sizeof(char));
            strcpy(word_longest, word);
        }
    }
    return word_longest;
}

int main(void)
{
    printf("val: %s\n", longest_word("three two one"));
    printf("%s\n", longest_word("a b c d e fgh"));
    return 0;
}
