/*
 * queue.h
 */

typedef struct queue_elt_tag {
  char *name;
  struct queue_elt_tag *next;
} queue_elt;

typedef struct {
  queue_elt *first, *last;
} queue;

void init_queue (queue *q);
void add_name_to_end (queue *q, char *name);
void remove_first_name (queue *q);
void delete_all_entries (queue *q);
void print_queue (queue *q);
