// Problem Statement : Write a C program to sort a linked list of n integers using the insertion sort algorithm and find the number of unique elements in the sorted list. 

// Insertion Sort Algorithm: Traverse the linked list one node at a time. For each node, find its correct position in the sorted portion of the list and insert it there. Repeat until the entire list is sorted. 

// Time Complexity: 
// Best Case (Already Sorted): 𝑂(𝑛)
// Average Case: 𝑂(𝑛^2)
// Worst Case (Reverse Sorted): 𝑂(𝑛^2)

// Space Complexity: 𝑂(1)

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory Allocation Failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node *createLinkedList()
{
    int n;
    printf("Enter Number of elements \n");
    scanf("%d", &n);
    struct Node *head = NULL;
    struct Node *temp = NULL;
    printf("Enter elements of the Linked List \n");
    for (int iteratorI = 0; iteratorI < n; iteratorI++)
    {
        float data;
        scanf("%f", &data);
        struct Node *newNode = createNode(data);
        if (head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    return head;
}
void printLinkedList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertionSort(struct Node **head)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }
    struct Node *sorted = NULL;
    struct Node *current = *head;

    while (current != NULL)
    {
        struct Node *nextNode = current->next;
        if (sorted == NULL || sorted->data >= current->data)
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            struct Node *temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data)
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = nextNode;
    }

    *head = sorted;
}

int countUniqueElements(struct Node *head)
{
    if (head == NULL)
        return 0;
    int count = 1;
    struct Node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        if (temp->data != temp->next->data)
        {
            count++;
        }
        temp = temp->next;
    }
    return count;
}

int main()
{
    struct Node *head = createLinkedList();

    insertionSort(&head);

    printLinkedList(head);

    int uniqueCount = countUniqueElements(head);
    printf("Number of unique elements: %d\n", uniqueCount);

    return 0;
}
