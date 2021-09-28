#include <stdio.h>
#include <stdlib.h>
#include "history.h"

/* Initialize the linked list to keep the history. */
List* init_history() {
  struct s_List *list = NULL;
  list = (struct s_List*)malloc(sizeof(struct s_List));
  return list;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str) {
  struct s_Item *ptr, *temp;
  ptr = list->root;
  temp = (struct s_Item*)malloc(sizeof(struct s_Item));

  // Checking if the linked list is empty
  // If it is, make this node the root node
  if(ptr == NULL) {
    // Adding the data to the node
    temp->id = 1;
    temp->str = str;
    temp->next = NULL;

    ptr = temp;
    list->root = ptr;
    return;
  }

  // Traversing the linked list +
  // creating the new id
  int id = 2;
  while(ptr->next != NULL) {
    ptr = ptr->next;
    id++;
  }

  // Adding the data to the node
  temp->id = id;
  temp->str = str;
  temp->next = NULL;

  // Placing the created node in the right order
  ptr->next = temp;
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id = the id of the Item to find */
char *get_history(List *list, int id) {
  // Creating a iter variable to iterate through list
  struct s_Item *iter;
  iter = list->root;

  while(iter != NULL) {
    if(iter->id == id) {
      return iter->str;
    }
    iter = iter->next;
  }
  printf("\n*This string does not exist in the linked list.*\n");
}

/* Print the entire contents of the list. */
void print_history(List *list) {
  // Creating a iter variable to iterate through list
  struct s_Item *iter;
  iter = list->root;

  // Traversing the linked list
  while(iter != NULL) {
    printf("This is the current id: %d\n", iter->id);
    printf("This is the current str: %s\n", iter->str);
    printf("\n");
    iter = iter->next;
  }
}

/* Free the history list and the strings it references. */
void free_history(List *list) {
  struct s_Item *iter;
  iter = list->root;

  // Traversing the linked list
  while(iter != NULL) {
    // Freeing the current node
    free(iter);
    iter = iter->next;
  }
  free(list);
}
