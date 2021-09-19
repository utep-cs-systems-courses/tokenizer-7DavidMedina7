#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

int main()
{
  char userIn[100];
  while(1) {
    printf("> ");
    fgets(userIn, 100, stdin);
    printf("%s\n", userIn);

    int result =  count_words(userIn);
    printf("This string has %d words!\n", result);
  }
  return 0; 
}

