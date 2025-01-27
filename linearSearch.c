// Problem Statement:
// Write a program to implement the Linear Search algorithm on a linked list to find a given element in the list. 
// The program should return the position of the element if found, or -1 if the element is not found.

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

struct Node *createLinkedList(int n)
{
    struct Node *head = NULL, *temp = NULL;
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

int main()
{
    int n, key;
    printf("Enter the number of elements: \n");
    scanf("%d", &n);

    struct Node *head = createLinkedList(n);

    printf("Enter the key to search: \n");
    scanf("%d", &key);

    int index = linearSearch(head, key);
    if (index != -1)
    {
        printf("Element %d found at index %d\n", key, index);
    }
    else
    {
        printf("Element %d not found in the list\n", key);
    }

    return 0;
}
