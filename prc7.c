// write menu driven program to implement double queue 1)insert 2)delete 3)modify 4)display

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure for a double-ended queue (deque)
struct Deque
{
  int items[MAX_SIZE];
  int front;
  int rear;
};

// Function to initialize a deque
void initializeDeque(struct Deque *deque)
{
  deque->front = -1;
  deque->rear = -1;
}

// Function to check if the deque is empty
int isEmpty(struct Deque *deque)
{
  return (deque->front == -1);
}

// Function to check if the deque is full
int isFull(struct Deque *deque)
{
  return ((deque->rear + 1) % MAX_SIZE == deque->front);
}

// Function to insert an element at the front of the deque
void insertFront(struct Deque *deque, int data)
{
  if (isFull(deque))
  {
    printf("Deque Overflow\n");
    return;
  }

  if (isEmpty(deque))
  {
    deque->front = 0;
    deque->rear = 0;
  }
  else
  {
    deque->front = (deque->front - 1 + MAX_SIZE) % MAX_SIZE;
  }

  deque->items[deque->front] = data;
}

// Function to insert an element at the rear of the deque
void insertRear(struct Deque *deque, int data)
{
  if (isFull(deque))
  {
    printf("Deque Overflow\n");
    return;
  }

  if (isEmpty(deque))
  {
    deque->front = 0;
    deque->rear = 0;
  }
  else
  {
    deque->rear = (deque->rear + 1) % MAX_SIZE;
  }

  deque->items[deque->rear] = data;
}

// Function to delete an element from the front of the deque
int deleteFront(struct Deque *deque)
{
  if (isEmpty(deque))
  {
    printf("Deque Underflow\n");
    return -1;
  }

  int data = deque->items[deque->front];

  if (deque->front == deque->rear)
  {
    deque->front = -1;
    deque->rear = -1;
  }
  else
  {
    deque->front = (deque->front + 1) % MAX_SIZE;
  }

  return data;
}

// Function to delete an element from the rear of the deque
int deleteRear(struct Deque *deque)
{
  if (isEmpty(deque))
  {
    printf("Deque Underflow\n");
    return -1;
  }

  int data = deque->items[deque->rear];

  if (deque->front == deque->rear)
  {
    deque->front = -1;
    deque->rear = -1;
  }
  else
  {
    deque->rear = (deque->rear - 1 + MAX_SIZE) % MAX_SIZE;
  }

  return data;
}

// Function to modify an element at a given index
void modify(struct Deque *deque, int index, int data)
{
  if (index < 0 || index >= MAX_SIZE)
  {
    printf("Invalid index\n");
    return;
  }

  deque->items[index] = data;
}

// Function to display the elements of the deque
void display(struct Deque *deque)
{
  if (isEmpty(deque))
  {
    printf("Deque is empty\n");
    return;
  }

  int i = deque->front;
  while (i != deque->rear)
  {
    printf("%d ", deque->items[i]);
    i = (i + 1) % MAX_SIZE;
  }
  printf("%d\n", deque->items[i]);
}

int main()
{
  struct Deque deque;
  initializeDeque(&deque);

  int choice, data, index;

  while (1)
  {
    printf("\nDeque Operations:\n");
    printf("1. Insert at Front\n");
    printf("2. Insert at Rear\n");
    printf("3. Delete from Front\n");
    printf("4. Delete from Rear\n");
    printf("5. Modify\n");
    printf("6. Display\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter data to insert at front: ");
      scanf("%d", &data);
      insertFront(&deque, data);
      break;
    case 2:
      printf("Enter data to insert at rear: ");
      scanf("%d", &data);
      insertRear(&deque, data);
      break;
    case 3:
      data = deleteFront(&deque);
      if (data != -1)
      {
        printf("Deleted element: %d\n", data);
      }
      break;
    case 4:
      data = deleteRear(&deque);
      if (data != -1)
      {
        printf("Deleted element: %d\n", data);
      }
      break;
    case 5:
      printf("Enter index to modify: ");
      scanf("%d", &index);
      printf("Enter new data: ");
      scanf("%d", &data);
      modify(&deque, index, data);
      break;
    case 6:
      display(&deque);
      break;
    case 7:
      exit(0);
    default:
      printf("Invalid choice\n");
    }
  }

  return 0;
}