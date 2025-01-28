// Problem Statement : Write a C program to sort a linked list of n floating-point numbers using the merge sort algorithm and find the k-th smallest element in the sorted list. 
 
// Merge Sort Algorithm: 
// - Divide the linked list into two halves until each part contains one or zero nodes. 
// - Recursively sort each half. 
// - Merge the two sorted halves back together in sorted order. 

// Time Complexity: 
// Best Case, Average Case, Worst Case: 𝑂(𝑛 log 𝑛)

// Space Complexity: 𝑂(log 𝑛)

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    float data;
    struct Node *next;
};

struct Node *createNode(float data)
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
        printf("%.2f -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node *findMiddle(struct Node *head)
{
    struct Node *slow = head, *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct Node *merge(struct Node *left, struct Node *right)
{
    if (left == NULL)
    {
        return right;
    }
    if (right == NULL)
    {
        return left;
    }
    struct Node *result = NULL;

    if (left->data <= right->data)
    {
        result = left;
        result->next = merge(left->next, right);
    }
    else
    {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

struct Node *mergeSort(struct Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct Node *middle = findMiddle(head);
    struct Node *nextToMiddle = middle->next;
    middle->next = NULL;

    struct Node *left = mergeSort(head);
    struct Node *right = mergeSort(nextToMiddle);

    return merge(left, right);
}

float findKthSmallest(struct Node *head, int k)
{
    struct Node *temp = head;
    int count = 1;
    while (temp != NULL && count < k)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL && count == k)
    {
        return temp->data;
    }
    return -1;
}

int main()
{
    struct Node *head = createLinkedList();

    printf("Original Linked List:\n");
    printLinkedList(head);

    head = mergeSort(head);

    printf("Sorted Linked List:\n");
    printLinkedList(head);

    int k;
    printf("Enter the value of k to find the k-th smallest element: ");
    scanf("%d", &k);
    float kthSmallest = findKthSmallest(head, k);
    if (kthSmallest != -1)
    {
        printf("The %d-th smallest element is: %.2f\n", k, kthSmallest);
    }
    else
    {
        printf("Invalid value of k.\n");
    }

    return 0;
}
