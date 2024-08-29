#include <stdio.h>

#define MAX_SIZE 5
int stack1[MAX_SIZE], stack2[MAX_SIZE];
int top1 = -1, top2 = -1;

void push1(int elem)
{
  if (top1 < MAX_SIZE - 1)
  {
    stack1[++top1] = elem;
    printf("Element pushed to stack 1!\n");
  }
  else
  {
    printf("Stack 1 is full!\n");
  }
}

void push2(int elem)
{
  if (top2 < MAX_SIZE - 1)
  {
    stack2[++top2] = elem;
    printf("Element pushed to stack 2!\n");
  }
  else
  {
    printf("Stack 2 is full!\n");
  }
}

int pop1()
{
  if (top1 >= 0)
  {
    return stack1[top1--];
  }
  else
  {
    printf("Stack 1 is empty!\n");
    return -1;
  }
}

int pop2()
{
  if (top2 >= 0)
  {
    return stack2[top2--];
  }
  else
  {
    printf("Stack 2 is empty!\n");
    return -1;
  }
}

int peep1()
{
  if (top1 >= 0)
  {
    return stack1[top1];
  }
  else
  {
    printf("Stack 1 is empty!\n");
    return -1;
  }
}

int peep2()
{
  if (top2 >= 0)
  {
    return stack2[top2];
  }
  else
  {
    printf("Stack 2 is empty!\n");
    return -1;
  }
}

void modify1(int elem)
{
  if (top1 >= 0)
  {
    stack1[top1] = elem;
    printf("Element modified in stack 1!\n");
  }
  else
  {
    printf("Stack 1 is empty!\n");
  }
}

void modify2(int elem)
{
  if (top2 >= 0)
  {
    stack2[top2] = elem;
    printf("Element modified in stack 2!\n");
  }
  else
  {
    printf("Stack 2 is empty!\n");
  }
}

void display1()
{
  int i;
  for (i = 0; i <= top1; i++)
  {
    printf("%d ", stack1[i]);
  }
  printf("\n");
}

void display2()
{
  int i;
  for (i = 0; i <= top2; i++)
  {
    printf("%d ", stack2[i]);
  }
  printf("\n");
}

int main()
{
  int choice, elem;

  while (1)
  {
    printf("Menu:\n");
    printf("1. Push to stack 1\n");
    printf("2. Push to stack 2\n");
    printf("3. Pop from stack 1\n");
    printf("4. Pop from stack 2\n");
    printf("5. Peep stack 1\n");
    printf("6. Peep stack 2\n");
    printf("7. Modify stack 1\n");
    printf("8. Modify stack 2\n");
    printf("9. Display stack 1\n");
    printf("10. Display stack 2\n");
    printf("11. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter element to push to stack 1: ");
      scanf("%d", &elem);
      push1(elem);
      break;
    case 2:
      printf("Enter element to push to stack 2: ");
      scanf("%d", &elem);
      push2(elem);
      break;
    case 3:
      elem = pop1();
      if (elem != -1)
      {
        printf("Popped element from stack 1: %d\n", elem);
      }
      break;
    case 4:
      elem = pop2();
      if (elem != -1)
      {
        printf("Popped element from stack 2: %d\n", elem);
      }
      break;
    case 5:
      elem = peep1();
      if (elem != -1)
      {
        printf("Top element of stack 1: %d\n", elem);
      }
      break;
    case 6:
      elem = peep2();
      if (elem != -1)
      {
        printf("Top element of stack 2: %d\n", elem);
      }
      break;
    case 7:
      printf("Enter new element for stack 1: ");
      scanf("%d", &elem);
      modify1(elem);
      break;
    case 8:
      printf("Enter new element for stack 2: ");
      scanf("%d", &elem);
      modify2(elem);
      break;
