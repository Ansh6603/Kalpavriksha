// Problem Statement : Write a C program to create a linked list of n integers and sort it in descending order using Quick Sort. After sorting, output the sorted list and find the median of the linked list.

// Quick Sort Algorithm: 
// - Choose a pivot element (typically the first element in the list). 
// - Partition the linked list into two parts: elements less than the pivot and elements greater than or equal to the pivot. 
// - Recursively apply Quick Sort to the two partitions. 
// - Combine the sorted partitions and pivot to get the fully sorted linked list. 

// Time Complexity: 
// Best Case: 𝑂(𝑛 log 𝑛) 
// Average Case: 𝑂(𝑛 log 𝑛)
// Worst Case: 𝑂(𝑛^2) 

// Space Complexity: 𝑂(log 𝑛)

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

struct Node *partition(struct Node *head, struct Node **left, struct Node **right)
{
    struct Node *pivot = head;
    struct Node *current = head->next;

    *left = NULL;
    *right = NULL;

    while (current != NULL)
    {
        struct Node *nextNode = current->next;
        if (current->data > pivot->data)
        {
            current->next = *left;
            *left = current;
        }
        else
        {
            current->next = *right;
            *right = current;
        }
        current = nextNode;
    }
    return pivot;
}

struct Node *quickSort(struct Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    struct Node *left = NULL, *right = NULL;
    struct Node *pivot = partition(head, &left, &right);

    left = quickSort(left);
    right = quickSort(right);

    struct Node *sortedList = left;
    if (left == NULL)
    {
        sortedList = pivot;
    }
    else
    {
        struct Node *temp = left;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = pivot;
    }
    pivot->next = right;

    return sortedList;
}

float findMedian(struct Node *head)
{
    struct Node *slow = head;
    struct Node *fast = head;

    if (head == NULL)
    {
        return -1;
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
        return (slow->data + slow->next->data) / 2.0;
    }
}

int main()
{
    struct Node *head = createLinkedList();

    printf("Original Linked List:\n");
    printLinkedList(head);

    head = quickSort(head);

    printf("Sorted Linked List (Descending Order):\n");
    printLinkedList(head);

    float median = findMedian(head);
    printf("Median: %.2f\n", median);

    return 0;
}
