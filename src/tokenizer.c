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
  word = word_start(word);
  while(non_space_char(*word)) {
    word++;
  }
  return word;
}

/* Counts the number of words in the string argument. */
int count_words(char *str) {
  int num_of_words = 0;
  while (*str != '\0') {
    str = word_start(str);
    str = word_terminator(str);
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
  char *copy = (char *)malloc((len + 1) * sizeof(char));

  int i = 0;
  for (i = 0; i < len; i++) {
    // Copying the char from inStr to our copy
    copy[i] = inStr[i];
  }
  // Adding the terminator char to the end of our copy
  copy[i] = '\0';

  return copy; 
}

char **tokenize(char* str) {
  // Obtaining the number of words in the string
  int num_of_words = 0;
  num_of_words = count_words(str);

  // Allocating the memory for the tokens
  char **tokens = malloc((num_of_words + 1) * sizeof(char*));

  // Iterating through the string and allocating the number of
  // bytes for each word
  int i = 0;
  for (i = 0; i < num_of_words; i++) {
    // Obtaining the length of the current word by
    // subtracting addresses
    char *address_start = word_start(str);
    char *address_end = word_terminator(str);
    int len_of_word = address_end - address_start;

    // Storing and creating our token
    char *current_token = copy_str(address_start, len_of_word);
    tokens[i] = current_token;
    str = address_end;
    printf("Created a token...\n");
  }
  // Adding the terminator char to the end of our tokens memory
  tokens[i] = NULL;

  return tokens;
}

void print_tokens(char **tokens) {
  printf("\n--- Printing tokens! ;) ---");
  // Iterating through the addresses of our tokens
  // and printing each one
  int index = 0;
  while(tokens != NULL) {
    printf("[%d]: %s\n", index, tokens[index]);
    tokens++;
    index++;
  }
  printf("\n--- Boom! Tokens boi ---\n");
}

void free_tokens(char **tokens) {
  free(tokens);
}
