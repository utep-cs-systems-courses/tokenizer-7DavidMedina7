#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/* Return true (non-zero) if c is a whitespace character   
   ('\t' or ' ').
   Zero terminators are not pritable (therefore false) */
int space_char(char c) {
  return (c == ' ' || c == '\t') ? 1 : 0;
}

/* Return true (non-zero) if c is a non-whitespace
   character (not tab or space).
   Zero terminators are not printable (therefore false) */
int non_space_char(char c) {
  return (c == ' ' || c == '\t' || c == '\0') ? 0 : 1;
}

/* Returns a pointer to the first character of the next
   space-separated word in zero-terminated str. Return a zero pointer if
   str does not contain any words */
char *word_start(char *str) {
  
  while(space_char(*str)) {
    str++; 
    // If it is a non_space - we are done
    if(*str == '\0') {
      return NULL;
    }
  }
  return str;
}

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word) {
  *word = *word_start(word);
  while(non_space_char(*word)) {
    word++;
  }
  return word;

}

/* Counts the number of words in the string argument. */
int count_words(char *str) {

  int i = 0;
  int num_of_words = 0;

  while(str[i] != '\0') {
    // This is one word
    if (non_space_char(str[i]) && space_char(str[i + 1])) {
      // Increment number of words
      num_of_words++;
    }
    // Increment index val
    i++;
  }

  // Checking if there is one last word at the end of the string
  if (str[i] == '\0' && !space_char(str[i - 1])) {
    num_of_words++;
  }
 
  return num_of_words;
}

/* Returns a freshly allocated now zero-terminated string
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len) {
  // Allocating the memory we need for our copy of inStr
  // Getting the len provided and mult. times char val
  // Typecast it to char pointer
  char *copy = (char *)malloc(len * sizeof(char));

  int i = 0;
  for (i = 0; i < len; i++) {
    printf("Value of inStr[i]: %c\n", inStr[i]);
    // Copying the char from inStr to our copy
    copy[i] = inStr[i];
  }
  
  return copy; 
}
