// Problem Statement: Write a program to implement the Selection Sort algorithm to sort a linked list of integers in ascending order and find the median of the sorted list.

// Selection Sort Algorithm: Traverse the linked list and repeatedly find the smallest element in the unsorted portion. Swap it with the first node of the unsorted portion, and continue until the entire list is sorted. 

// Time Complexity: 
// Best Case: 𝑂(𝑛^2)
// Average Case: 𝑂(𝑛^2)
// Worst Case: 𝑂(𝑛^2)

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

void selectionSort(struct Node *head)
{
    struct Node *temp1, *temp2;
    int minValue;

    if (head == NULL)
    {
        return;
    }

    for (temp1 = head; temp1 != NULL && temp1->next != NULL; temp1 = temp1->next)
    {
        temp2 = temp1->next;
        struct Node *minNode = temp1;

        while (temp2 != NULL)
        {
            if (temp2->data < minNode->data)
            {
                minNode = temp2;
            }
            temp2 = temp2->next;
        }

        if (minNode != temp1)
        {
            int tempValue = temp1->data;
            temp1->data = minNode->data;
            minNode->data = tempValue;
        }
    }
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

    selectionSort(head);

    printf("Sorted Linked List: \n");
    printLinkedList(head);

    float median = findMedian(head);
    printf("Median: %.2f\n", median);

    return 0;
}
