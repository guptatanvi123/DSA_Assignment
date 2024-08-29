#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure for a queue node
struct Node
{
  int data;
  struct Node *next;
};

// Structure for a queue
struct Queue
{
  struct Node *front;
  struct Node *rear;
  int size;
};

// Function to create a new queue
struct Queue *createQueue()
{
  struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
  q->front = NULL;
  q->rear = NULL;
  q->size = 0;
  return q;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *q)
{
  return (q->size == 0);
}

// Function to insert an element into the queue
void enqueue(struct Queue *q, int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if (isEmpty(q))
  {
    q->front = newNode;
    q->rear = newNode;
  }
  else
  {
    q->rear->next = newNode;
    q->rear = newNode;
  }
  q->size++;
}

// Function to delete an element from the queue
int dequeue(struct Queue *q)
{
  if (isEmpty(q))
  {
    printf("Queue is empty!\n");
    return -1;
  }

  int data = q->front->data;
  q->front = q->front->next;
  if (q->front == NULL)
  {
    q->rear = NULL;
  }
  q->size--;
  return data;
}

// Function to modify the element at the front of the queue
void modify(struct Queue *q, int new_data)
{
  if (isEmpty(q))
  {
    printf("Queue is empty!\n");
    return;
  }
  q->front->data = new_data;
}

// Function to display the elements in the queue
void display(struct Queue *q)
{
  if (isEmpty(q))
  {
    printf("Queue is empty!\n");
    return;
  }
  struct Node *temp = q->front;
  printf("Queue: ");
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

// Main function
int main()
{
  struct Queue *q = createQueue();
  int choice, data;

  while (1)
  {
    printf("\nQueue Operations:\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Modify\n");
    printf("4. Display\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter data to insert: ");
      scanf("%d", &data);
      enqueue(q, data);
      break;
    case 2:
      data = dequeue(q);
      if (data != -1)
      {
        printf("Deleted element: %d\n", data);
      }
      break;
    case 3:
      printf("Enter new data for front element: ");
      scanf("%d", &data);
      modify(q, data);
      break;
    case 4:
      display(q);
      break;
    case 5:
      exit(0);
    default:
      printf("Invalid choice!\n");
    }
  }

  return 0;
}