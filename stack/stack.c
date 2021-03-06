#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ds-terminal/terminal.h"

//////////////////////////////////////////////////////////////////////

typedef struct Stack {
  unsigned int size;
  int top;
  int* buffer;
}Stack;

//////////////////////////////////////////////////////////////////////

// Declaring private functions

Stack* createStack();
void setupTerminal();
int empty();

// Declaring public functions

void pop();
void push();
void top();
void printStack();

//////////////////////////////////////////////////////////////////////

int main (int argc, char* argv[]){
  if (argc != 2){
    printf("Please execute the file with the stack size as an argument.\nE.g. ./stack 2\n");
    exit(0);
  }

  unsigned int size = (unsigned int) atoi(argv[1]);
  Stack* stack = createStack(size);

  setupTerminal();
  init_terminal(stack);
}

//////////////////////////////////////////////////////////////////////

// Defining private functions

Stack* createStack(unsigned int size){
  Stack* stack = (Stack*) malloc(size * sizeof(Stack));
  stack->size = size;
  stack->top = -1;
  stack->buffer = (int*) malloc(size * sizeof(int));
  return stack;
}

void setupTerminal(){
  add_command(pop,         "pop",        0);
  add_command(push,        "push",       1);
  add_command(top,         "top",        2);
  add_command(printStack,  "printStack", 0);
}

int empty(Stack* stack){
  if(stack->top == -1) return 1;
  else return 0;
}

// Defining public functions

void pop(Stack* stack){
  if (!empty(stack)){
    printf("%d\n", stack->buffer[stack->top--]);
    printStack(stack);
    return;
  }

  else printf("The stack is empty.\n");
  return;
}

void push(Stack* stack, int n){
  if (stack->top == stack->size-1){
    printf("The stack is full.\n");
    return;
  }
  
  stack->buffer[++stack->top] = n;
  printStack(stack);
  return; 
}

void top(Stack* stack){
  if(!empty(stack)){
    printf("%d\n", stack->buffer[stack->top]);
    return;
  }
  
  else  printf("The stack is empty\n");
  return;
}

void printStack(Stack* stack){
  unsigned int i;
  printf("[");
  for (i = 0; i < stack->top+1; i++){
    printf("%u", stack->buffer[i]);
    if (i != stack->top) printf(", ");
  }
  printf("]\n");
}
