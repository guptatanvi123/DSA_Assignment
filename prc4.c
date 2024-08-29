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

int precedence(char op)
{
  if (op == '+' || op == '-')
    return 1;
  else if (op == '*' || op == '/')
    return 2;
  else
    return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
  int i, j = 0;
  char temp;

  for (i = 0; i < strlen(infix); i++)
  {
    if (infix[i] == ' ' || infix[i] == '(')
      continue;
    else if (infix[i] == ')')
    {
      while ((temp = pop()) != '(')
        postfix[j++] = temp;
    }
    else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
    {
      while (top != -1 && stack[top] != '(' && precedence(stack[top]) >= precedence(infix[i]))
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