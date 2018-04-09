/* When provided with a letter, return its position in the alphabet. */
/* Input :: "a" */
/* Ouput :: "Position of alphabet: 1" */
#include <string.h>

char* position(char alphabet)
{
  char *str;
  asprintf(&str, "Position of alphabet: %d", alphabet - 'a' + 1);
  return str;
}
