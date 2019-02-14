#include "linkedList.h"

int isEmpty(stack* stack){

    return stack->top = -1;
}

stack* createStack(unsigned length){

  stack* stack = (struct stack*)malloc(sizeof(stack));

  if (stack == NULL){
    printf("Error in allocating memory to stack\n");
    return NULL;
  }

  stack->top = -1;
  stack->length = length;
  stack->hold = malloc(stack->length * sizeof(int));

  return stack;
}

void push(stack* stack, char elem){

  stack->top++;
  stack->hold[stack->top] = elem;
}

char pop(stack* stack){

  if(!isEmpty(stack)){
    return stack->hold[stack->top--];
  }
  return '1';
}

int evaluatePostfix(char *postFix){

  stack* stack = createStack(strlen(postFix));
  int i;
  int val1;
  int val2;
  int c;

  if(stack == NULL){
    return 0;
  }
  for (i = 0; i < strlen(postFix); i++){
    c = postFix[i];
    if (isdigit(c)){
      push(stack, c);
    }
    else {
      val1 = pop(stack);
      val2 = pop(stack);
      if (c == '+'){
        push(stack, val1 + val2);
      }
      else if (c == '-'){
        push(stack, val2 - val1);
      }
      else if (c == '/'){
        push(stack, val2 / val1);
      }
      else if (c == '*'){
        push(stack, val2 * val1);
      }
    }
  }
return pop(stack);
}
