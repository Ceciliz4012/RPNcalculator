/*
 * main_queue.c
 */

#include "queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 200

int main ()
{
  char input[MAX_LINE_LENGTH];
  char name[MAX_LINE_LENGTH];
  queue theQueue;

  init_queue(&theQueue);
  
  while (1) {
    printf ("Enter command (add, delete, list quit) : \n");

    fgets (input, MAX_LINE_LENGTH, stdin);

    // Check for add command
    if (sscanf (input, "add %s", name) == 1) {
      add_name_to_end (&theQueue, name);
      print_queue (&theQueue);
    }

    // Check for delete command
    if (input[0] == 'd') {
      remove_first_name (&theQueue);
      print_queue (&theQueue);
    }

    // Check for list command
    if (input[0] == 'l') {
      print_queue (&theQueue);
    }

    // check for quit command
    if (input[0] == 'q') {
      delete_all_entries (&theQueue);
      exit (0);
    }
    
  }
  
  return 0;
}
