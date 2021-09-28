#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

// Returns the length of the string
int str_length(char *str){
  int count;
  for(count=0; *str != '\0'; str++){
    count++;
  }
  return count;
}

int main()
{ 
  char userIn[100];
  struct s_List *history_list = init_history(); // Initializing the history
  while(1) {
    printf("\nEnter a command: \n* [!t] to tokenize a string\n* [!<num>] to acesses a particular history record\n* [!h] to view the full history\n* [!q] to quit\n");

    fgets(userIn, 100, stdin);
    char command = userIn[1];

    if(command == 't') {
      char userString[100];
      printf("\nPlease enter a string to tokenize: \n");
      fgets(userString, 100, stdin);
      printf("\nThis string has %d words!\n\n", count_words(userString));
      char **tokens = tokenize(userString);
      char *copyStr = copy_str(userString, str_length(userString));
      add_history(history_list, copyStr);
      print_tokens(tokens);
    } else if (command == 'h') {
      print_history(history_list);
    } else if (command == 'q') {
      printf("Bye!");
      break;
    } else {
      int index = atoi(userIn + 1);
      char *token = get_history(history_list, index);
      printf("H[%d]: %s\n", index, token);
    }
  }
  return 0; 
}

