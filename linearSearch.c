// Problem Statement : Write a C program to perform a linear search in a linked list of n integers. After performing the linear search, delete the found element from the linked list and print the updated linked list. 

// Steps:
// 1. Traverse the linked list from the head node.
// 2. Compare each node's data with the target element.
// 3. If a match is found, return the position (index) of the element.
// 4. If the end of the list is reached without finding the element, return -1 to indicate that the element is not in the list.

// Time Complexity:
// - Best Case: O(1) if the element is found at the head of the list.
// - Worst Case: O(n) where 'n' is the number of nodes in the linked list, when the element is not present or is at the last node.
// - Average Case: O(n)

// Space Complexity: O(1) 

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

int linearSearch(struct Node *head, int key)
{
    struct Node *temp = head;
    int index = 0;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}

struct Node *deleteNode(struct Node *head, int key)
{
    struct Node *temp = head, *prev = NULL;
    if (head != NULL && head->data == key)
    {
        head = head->next;
        free(temp);
        return head;
    }
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return head;
    }
    prev->next = temp->next;
    free(temp);
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

int main()
{
    int key;

    struct Node *head = createLinkedList();

    printf("Enter the key to search: \n");
    scanf("%d", &key);

    int index = linearSearch(head, key);
    if (index != -1)
    {
        printf("Element %d found at index %d\n", key, index);
        head = deleteNode(head, key);
        printf("Linked List after deletion: \n");
        printLinkedList(head);
    }
    else
    {
        printf("Element %d not found in the list\n", key);
    }

    return 0;
}
