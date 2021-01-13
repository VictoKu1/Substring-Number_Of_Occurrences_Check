#include <stdio.h>
#include <stdlib.h>
#define NUM_LETTERS ((int)27)
typedef enum {FALSE=0, TRUE=1} boolean;

typedef struct node {
char letter;
long unsigned int count;
struct node* children[NUM_LETTERS];
} node;
