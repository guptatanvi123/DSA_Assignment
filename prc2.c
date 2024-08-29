

#include <stdio.h>

#define MAX_SIZE 5
int stack[MAX_SIZE];
int top = -1;

void push(int elem)
{
  if (top < MAX_SIZE - 1)
  {
    stack[++top] = elem;
    printf("Element pushed!\n");
  }
  else
  {
    printf("Stack is full!\n");
  }
}

int pop()
{
  if (top >= 0)
  {
    return stack[top--];
  }
  else
  {
    printf("Stack is empty!\n");
    return -1;
  }
}

int peep()
{
  if (top >= 0)
  {
    return stack[top];
  }
  else
  {
    printf("Stack is empty!\n");
    return -1;
  }
}

void modify(int elem)
{
  if (top >= 0)
  {
    stack[top] = elem;
    printf("Element modified!\n");
  }
  else
  {
    printf("Stack is empty!\n");
  }
}

void display()
{
  int i;
  for (i = 0; i <= top; i++)
  {
    printf("%d ", stack[i]);
  }
  printf("\n");
}

int main()
{
  int choice, elem;

  while (1)
  {
    printf("Menu:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peep\n");
    printf("4. Modify\n");
    printf("5. Display\n");
    printf("6. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter element to push: ");
      scanf("%d", &elem);
      push(elem);
      break;
    case 2:
      elem = pop();
      if (elem != -1)
      {
        printf("Popped element: %d\n", elem);
      }
      break;
    case 3:
      elem = peep();
      if (elem != -1)
      {
        printf("Top element: %d\n", elem);
      }
      break;
    case 4:
      printf("Enter new element: ");
      scanf("%d", &elem);
      modify(elem);
      break;
    case 5:
      display();
      break;
    case 6:
      return 0;
    default:
      printf("Invalid choice!\n");
    }
  }

  return 0;
}