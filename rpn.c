/*
 * rpn.c
 */

#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 100

int main ()
{
  char input[MAX_LINE_LENGTH];
  int i;
  char command[MAX_LINE_LENGTH];
  char extra1[MAX_LINE_LENGTH];
  char extra2[MAX_LINE_LENGTH];
  stack theStack;
  
  init_stack(&theStack);
  
  while (1) {
    fgets (input, MAX_LINE_LENGTH, stdin);
	
    if (sscanf (input, "%d%s", &i, extra1) == 1) {
      push (&theStack, i, 1);
      //print_top (&theStack);
      //print_stack (&theStack);
      
    } else if (sscanf(input,"%s%s", command, extra2) == 1) {
    	if (strcasecmp(command, "+") == 0) {
      		add(&theStack);
      		//print_top (&theStack);
      		//print_stack (&theStack);
    	}
    	
    	else if (strcasecmp(command,"-") == 0) {
      		subtract(&theStack);
      		//print_top (&theStack);
      		//print_stack (&theStack);
    	}
    	
    	else if (strcasecmp(command, "*") == 0) {
      		multiply(&theStack);
      		//print_top (&theStack);
      		//print_stack (&theStack);
    	}
    	
    	else if (strcasecmp(command, "/") == 0) {
      		divide(&theStack);
      		//print_top (&theStack);
      		//print_stack (&theStack);
    	}
	
    	else if (strcasecmp(command, "dup") == 0) {
      		duplicate (&theStack);
      		//print_top (&theStack);
      		//print_stack (&theStack);
    	}
	
    	else if (strcasecmp(command, "swap") == 0) {
      		swap(&theStack);
      		//print_top (&theStack);
      		//print_stack (&theStack);
    	}
	
    	else if (strcasecmp(command, "quit") == 0) {
      		delete_all (&theStack);
      		exit (0);
    	}
    	
    	else if (strcasecmp(command, "drop") == 0) {
      		pop(&theStack);
      		if (isempty(&theStack) == 1) {
      		   print_top (&theStack);
      		}
      		//print_stack (&theStack);
    	}
    	
    	else if (strcasecmp(command, "clear") == 0) {
      		delete_all (&theStack);
      		//print_stack (&theStack);
    	} 
    	
    	else {
    	  printf ("INVALID COMMAND\n");
    	}
    } else {
    	  printf ("INVALID COMMAND\n");
    	}
  }
  
  return 0;
}

