
/*
 * stack.c
 */

#include "stack.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void init_stack (stack *s)
{
  s->first = NULL;
  s->last = NULL;
}

int gcd(int a, int b) { 
  if (a == 0) 
    return b; 
  return gcd(b%a, a); 
}

int isempty (stack *s) {
  if(s->first) {
    return 1;
  } else {
    return 0;
  }
}

void print_top (stack *s) {
  if (s->first) {
    stack_elt *elt = s->first;
    printf ("%d/%d\n", elt->n, elt->d);
  }
}

void push (stack *s, int nn, int dd)
{
  stack_elt *elt;
  
  // Allocate a new list element with malloc
  elt = malloc (sizeof(*elt));

  // If malloc fails end the program
  if (elt == NULL) {
    //printf ("Couldn't allocate a new stack element\n");
    exit (1);
  }
  int factor = gcd(abs(nn), abs(dd));

  elt->n = nn/factor;
  elt->d = dd/factor;

  // Check if stack is empty
  if (s->first) {
    elt->next = s->first;
    s->first = elt;
  } else {
    s->first = elt;
    s->last = elt;
    elt->next = NULL;
  }
  print_top (s);
}

void pop (stack *s)
{
  stack_elt *elt;
  
  if (s->first) {
    elt = s->first;

    if (s->first == s->last) {
      //deleting the only element in the stack
      s->first = NULL;
      s->last = NULL;
    } else {
      s->first = elt->next;
    }

    // free the elt
    free(elt);
  } else {
  	printf ("STACK ERROR\n");
  }
}

/*void print_stack (stack *s)
{
  stack_elt *elt = s->first;

  printf ("STACK CONTENTS\n");

  while (elt) {
    printf ("%d/%d\n", elt->n, elt->d);
    elt = elt->next;
  }
}*/


void add (stack *s){
  if (s->first) {
    if (s->first->next) {
      int n1 = (s->first)->n;
      int n2 = ((s->first)->next)->n;
  	  int d1 = (s->first)->d;
  	  int d2 = ((s->first)->next)->d;
  	  pop(s);
  	  pop(s);
  	  int resd = d1*d2;
  	  int resn = n1*d2 + n2*d1;
  	  int factor = gcd(abs(resd), abs(resn));
  	  push(s, resn/factor, resd/factor);
    } else {
    printf ("STACK ERROR\n");
    }
  } else {
    printf ("STACK ERROR\n");
  }
}

void subtract (stack *s){
  if (s->first) {
    if (s->first->next) {
      int n1 = (s->first)->n;
  	  int n2 = ((s->first)->next)->n;
  	  int d1 = (s->first)->d;
  	  int d2 = ((s->first)->next)->d;
  	  pop(s);
  	  pop(s);
  	  int resd = d1*d2;
  	  int resn = n2*d1 - n1*d2;
      int factor;
     
  	  if (resd < 0) {
		  resn = resn * -1;
		  resd = resd * -1;
	  }
  	  push(s, resn, resd);
    } else {
    printf ("STACK ERROR\n");
    }
  } else {
    printf ("STACK ERROR\n");
  }
}

void multiply (stack *s){
  if (s->first) {
    if (s->first->next) {
      int n1 = (s->first)->n;
  	  int n2 = ((s->first)->next)->n;
  	  int d1 = (s->first)->d;
  	  int d2 = ((s->first)->next)->d;
  	  pop(s);
  	  pop(s);
  	  int resd = d1*d2;
  	  int resn = n1*n2;
  	  int factor = gcd(abs(resd), abs(resn));
  	  push(s, resn/factor, resd/factor);
    } else {
    printf ("STACK ERROR\n");
    }
  } else {
    printf ("STACK ERROR\n");
  }
}

void divide (stack *s){
  if (s->first) {
    if (s->first->next) {
      int n1 = (s->first)->n;
  	  int n2 = ((s->first)->next)->n;
  	  int d1 = (s->first)->d;
  	  int d2 = ((s->first)->next)->d;
      
      if (n1 == 0) {
        printf("DIVIDE BY ZERO\n");
        delete_all(s);
        exit (0);
      } else {
  	    pop(s);
  	    pop(s);
  	    int resn = d1*n2;
  	    int resd = n1*d2;
  	    int factor;
       
  	    if (resd < 0) {
		      resn = resn * -1;
		      resd = resd * -1;
		}
  	    push(s, resn, resd);
  	  }
  	  
    } else {
      printf ("STACK ERROR\n");
    }
  } else {
    printf ("STACK ERROR\n");
  }
  
}

void duplicate (stack *s){
  if (s->first) {
    int resn = (s->first)->n;
    int resd = (s->first)->d;
    push(s, resn, resd);
  } else {
      printf ("STACK ERROR\n");
  }
}

void swap (stack *s){
  if (s->first) {
    if (s->first->next) {
      stack_elt *elt1;
  	  stack_elt *elt2;
  	  stack_elt *elt3;
  
  	  //if (s->first && (s->first)->next) {
        elt1 = s->first;
        elt2 = (s->first)->next;
        elt3 = ((s->first)->next)->next;
        s->first = elt2;
        (s->first)->next = elt1;
        elt1->next = elt3;
  	    //}
  	  print_top (s);
  	    
    } else {
      printf ("STACK ERROR\n");
    }
  } else {
    printf ("STACK ERROR\n");
  }
  
}

void delete_all (stack *s)
{
  while (s->first) {
    pop(s);
  }
}

