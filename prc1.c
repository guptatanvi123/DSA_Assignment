// write menu driven program to implement oprations on array ,(Add,delete ,modify,sort,simple search ,binary search)

#include <stdio.h>

int arr[10];
int size = 0;

void add()
{
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);
  arr[size] = num;
  size++;
  printf("Number added!\n");
}

void delete()
{
  // int num;
  // printf("Enter a number to delete: ");
  // scanf("%d", &num);
  // for (int i = 0; i < size; i++)
  // {
  //   if (arr[i] == num)
  //   {
  //     arr[i] = 0;
  //     printf("Number deleted!\n");
  //     return;
  //   }
  // }
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);
  arr[size] = num;
  size--;
  printf("Number !\n");
}

// printf("Number not found!\n");
// }

void modify()
{
  int old, new;
  printf("Enter old number: ");
  scanf("%d", &old);
  printf("Enter new number: ");
  scanf("%d", &new);
  size++;

  // for (int i = 0; i < size; i++)
  //{
  if (arr[size] == old)
  {
    arr[size] = new;
    printf("Number modified!\n");
    return;
  }
}
// printf("Number not found!\n");
//}

void sort()
{
  for (int i = 0; i < size; i++)
  {
    for (int j = i + 1; j < size; j++)
    {
      if (arr[i] > arr[j])
      {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
  printf("Numbers sorted!\n");
}

void search()
{
  int num;
  printf("Enter a number to search: ");
  scanf("%d", &num);
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == num)
    {
      printf("Number found!\n");
      return;
    }
  }
  printf("Number not found!\n");
}

int main()
{
  while (1)
  {
    printf("Menu:\n");
    printf("1. Add number\n");
    printf("2. Delete number\n");
    printf("3. Modify number\n");
    printf("4. Sort numbers\n");
    printf("5. Search number\n");
    printf("6. Exit\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      add();
      break;
    case 2:
      delete ();
      break;
    case 3:
      modify();
      break;
    case 4:
      sort();
      break;
    case 5:
      search();
      break;
    case 6:
      return 0;
    default:
      printf("Invalid choice!\n");
    }
  }
  return 0;
}