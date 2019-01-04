/*
https://www.codewars.com/kata/numbers-with-d-occurences-of-digit-d

In this kata, we want to discover a small property of numbers.
We say that a number is a **dd** number if it contains d occurences of a digit d, (d is in [1,9]).

## Examples

* 664444309 is a **dd** number, as it contains 4 occurences of the number 4
* 30313, 122 are **dd** numbers as they respectively contain 3 occurences of the number 3, and (1 occurence of the number 1 AND 2 occurences of the number 2)
* 123109, 0, 56542 are not **dd** numbers

## Task

Your task is to implement a function called `is_dd` that takes a **positive** number (type depends on the langage) and returns a boolean corresponding to whether the number is a **dd** number or not.
*/

#include <stdbool.h>

bool is_dd(const long d){
  char ds[9];
  int counter = 0;

  sprintf(ds, "%d", d);
  for(int i = 0; i < strlen(ds); i++) {
    for(int j = 0; j < strlen(ds); j++) {
      if(ds[j] == (i + '0')) {
        counter++;
      }
    }
    if(counter == i && counter != 0) {
      return true;
    }
    counter = 0;
  }

  return false;
}
