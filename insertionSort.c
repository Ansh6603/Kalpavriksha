// Problem Statement: Write a program to implement the Insertion Sort algorithm to sort a linked list of integers in ascending order and find the median of the sorted list.

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
        printf("Memory Allocation Failed \n");
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
        int data;
        scanf("%d", &data);
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

float findMedian(struct Node *head)
{
    struct Node *slow = head;
    struct Node *fast = head;

    if (head == NULL)
    {
        return -1;
    }

    if (head->next == NULL)
    {
        return head->data;
    }

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast == NULL)
    {
        return slow->data;
    }
    else
    {
        int middle1 = slow->data;
        int middle2 = slow->next->data;
        return (middle1 + middle2) / 2.0;
    }
}

int main()
{
    struct Node *head = createLinkedList();

    printf("Original Linked List: \n");
    printLinkedList(head);

    insertionSort(&head);

    printf("Sorted Linked List: \n");
    printLinkedList(head);

    float median = findMedian(head);
    printf("Median: %.2f\n", median);

    return 0;
}
