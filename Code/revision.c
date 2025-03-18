// // Array Insertion
// #include <stdio.h>

// void display(int arr[], int n)
// {
//     // Traversal
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// int indInsertion(int arr[], int size, int capacity, int element, int index)
// {
//     if (size >= capacity)
//     {
//         return -1; // -1 represents that the capacity is full and no element can be inserted in the array
//     }

//     for (int i = size - 1; i >= index; i--)
//     {
//         arr[i + 1] = arr[i];
//     }
//     arr[index] = element;
//     return 1; // denotes success
// }

// int main()
// {
//     int arr[100] = {6, 7, 8, 15, 16};
//     int size = 5;
//     int element, index;
//     display(arr, size);
//     printf("Enter the element you want to insert : \n");
//     scanf("%d", &element);
//     printf("Enter the index at which you want to insert hte element : \n");
//     scanf("%d", &index);
//     indInsertion(arr, size, 100, element, index);
//     size += 1;
//     display(arr, size);
//     return 0;
// }

// Array Deletion Code

/*
#include <stdio.h>

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int indDeletion(int arr[], int size, int capacity, int index)
{
    for (int i = index; i <= size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    return 1;
}

int main()
{
    int arr[] = {5, 9, 8, 16, 17, 19};
    int size = 6 , index;
    display(arr, size);
    printf("Enter the index at which you want to delete the element : \n");
    scanf("%d", &index);
    indDeletion(arr, size, 100, index);
    size -= 1;
    display(arr, size);
    return 0;
}

*/

// Creating LinkedList and traversing it

// #include <stdio.h>
// #include <stdlib.h>

// struct Node
// {
//     int data;
//     struct Node *next; // This is a pointer that stores the address of the next node in the list
// };

// void display(struct Node *ptr)
// {
//     while (ptr != NULL)
//     {
//         printf("Element : %d\n", ptr->data);
//         ptr = ptr->next;
//     }
// }

// int main()
// {
//     struct Node *head;
//     struct Node *first;
//     struct Node *second;
//     struct Node *third;
//     struct Node *fourth;
//     struct Node *fifth;
//     struct Node *sixth;
//     struct Node *seventh;
//     struct Node *eighth;

//     head = (struct Node *)malloc(sizeof(struct Node)); /* we are allocating memory dynamically in heap for head of type struct Node * using malloc which uses size of struct Node */
//     second = (struct Node *)malloc(sizeof(struct Node));
//     third = (struct Node *)malloc(sizeof(struct Node));
//     fourth = (struct Node *)malloc(sizeof(struct Node));
//     fifth = (struct Node *)malloc(sizeof(struct Node));
//     sixth = (struct Node *)malloc(sizeof(struct Node));
//     seventh = (struct Node *)malloc(sizeof(struct Node));
//     eighth = (struct Node *)malloc(sizeof(struct Node));

//     head->data = 7;
//     head->next = second;

//     second->data = 9;
//     second->next = third;

//     third->data = 15;
//     third->next = fourth;

//     fourth->data = 25;
//     fourth->next = fifth;

//     fifth->data = 85;
//     fifth->next = sixth;

//     sixth->data = 46;
//     sixth->next = seventh;

//     seventh->data = 78;
//     seventh->next = eighth;

//     eighth->data = 46;
//     eighth->next = NULL;

//     display(head); // Calling the display function to print the elements of the linkedlist

//     return 0;
// }

// OPERATIONS ON AN ARRAY
// Traversal and insertion
// #include <stdio.h>

// void display(int arr[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         printf("Element at index %d = %d\n", i, arr[i]);
//     }
// }

// int indInsertion(int arr[], int size, int capacity, int element, int index)
// {
//     if (size >= capacity)
//     {
//         return -1; // this denotes that the array is full and no element can be inserted
//     }
//     for (int i = size - 1; i >= index; i--)
//     {
//         arr[i + 1] = arr[i];
//     }
//     arr[index] = element;
//     return 1;
// }

// int main()
// {
//     int arr[100] = {1, 3, 5, 7, 9, 11, 32};
//     int size = 7;
//     int index, element;
//     // int index = 0, element = 7;
//     printf("Enter the index at which you want insertion to be done : ");
//     scanf("%d", &index);
//     printf("Enter the element to be inserted : ");
//     scanf("%d", &element);
//     printf("The array is printed below : \n");
//     display(arr, size);
//     indInsertion(arr, size, 100, element, index);
//     size += 1;
//     printf("Array after insertion : \n");
//     display(arr, size);

//     return 0;
// }
#include<stdio.h>



int main() {
    printf("This is a change !");
    return 0;
}