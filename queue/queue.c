/*
 * queue.c
 */

#include "queue.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>


void init_queue (queue *q)
{
  q->first = NULL;
  q->last = NULL;
}

void add_name_to_end (queue *q, char *name)
{
  queue_elt *elt;
  
  // Allocate a new list element with malloc
  elt = malloc (sizeof(*elt));


  // If malloc fails end the program
  if (elt == NULL) {
    printf ("Couldn't allocate a new queue element\n");
    exit (1);
  }

  // Allocate space to store the name
  elt->name = malloc(strlen(name) + 1);

  // If malloc fails end the program
  if (elt->name == NULL) {
    printf ("Couldn't allocate a new name\n");
    exit (1);
  }

  elt->next = NULL;

  // Copy the name
  strcpy (elt->name, name);

  // Check if queue is empty
  if (q->last) {
    // add elt to the end
    (q->last)->next = elt;
  } else {
    q->first = elt;
  }
  q->last = elt;
}

void remove_first_name (queue *q)
{
  queue_elt *elt;
  
  if (q->first) {
    elt = q->first;

    if (q->first == q->last) {
      // In this case you are deleting the only element in the queue
      q->first = NULL;
      q->last = NULL;
    } else {
      q->first = elt->next;
    }

    // free the elt
    free(elt->name);
    free(elt);
  }
}

void delete_all_entries (queue *q)
{
  while (q->first) {
    remove_first_name (q);
  }
}

void print_queue (queue *q)
{
  queue_elt *elt = q->first;

  printf ("\nQUEUE CONTENTS\n");

  while (elt) {
    printf ("%s\n", elt->name);
    elt = elt->next;
  }
}
