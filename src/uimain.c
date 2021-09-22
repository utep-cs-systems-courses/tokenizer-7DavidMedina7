#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

int main()
{
  char userIn[100];
  while(1) {
    printf("\n> ");
    char *userString = fgets(userIn, 100, stdin);
    printf("\nThe original string is: %s\n", userIn);
    printf("wordStart: %s\n", word_start(userIn));
    printf("wordEnd: %s\n", word_terminator(userIn));
    printf("This string has %d words!\n", count_words(userIn));
    char **tokens = tokenize(userString);
    print_tokens(tokens);
    printf("[%d]: %s\n", 0, tokens[0]);
    printf("[%d]: %s\n", 1, tokens[1]);
    printf("[%d]: %s\n", 2, tokens[2]);
    free_tokens(tokens);
    printf("Tokens freed.\n");
  }
  return 0; 
}

