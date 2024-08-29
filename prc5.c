#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char elem)
{
  stack[++top] = elem;
}

char pop()
{
  return stack[top--];
}

void infixToPostfix(char infix[], char postfix[])
{
  int i, j = 0;
  char temp;

  for (i = 0; i < strlen(infix); i++)
  {
    if (infix[i] == '(')
      push(infix[i]);
    else if (infix[i] == ')')
    {
      while ((temp = pop()) != '(')
        postfix[j++] = temp;
    }
    else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
    {
      while (top != -1 && stack[top] != '(' && stack[top] != '+' && stack[top] != '-')
        postfix[j++] = pop();
      push(infix[i]);
    }
    else
      postfix[j++] = infix[i];
  }

  while (top != -1)
    postfix[j++] = pop();

  postfix[j] = '\0';
}

int main()
{
  char infix[100], postfix[100];

  printf("Enter an infix expression: ");
  scanf("%s", infix);

  infixToPostfix(infix, postfix);

  printf("Postfix expression: %s\n", postfix);

  return 0;
}