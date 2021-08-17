/*
 * stack.h
 */

typedef struct stack_elt_tag {
  int n;
  int d;
  struct stack_elt_tag *next;
} stack_elt;

typedef struct {
  stack_elt *first, *last;
} stack;

void init_stack (stack *s);
void push (stack *s, int nn, int dd);
void pop (stack *s);
void print_stack (stack *s);
void print_top (stack *s);
int isempty (stack *s);

void add (stack *s);
void subtract (stack *s);
void multiply (stack *s);
void divide (stack *s);

void duplicate (stack *s);
void swap (stack *s);
void drop (stack *s);
void delete_all (stack *s);

