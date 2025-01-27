// Problem Statement:
// Write a program to implement the Two-Pointer technique to find the middle element of a linked list.
// The program should return the middle element of the list.
// If the list has an even number of elements, the middle element is the second of the two middle nodes.

// Steps:
// 1. Initialize two pointers, `slow` and `fast`, both pointing to the head node of the linked list.
// 2. Traverse the linked list by moving the `slow` pointer one step at a time and the `fast` pointer two steps at a time.
// 3. When the `fast` pointer reaches the end of the list, the `slow` pointer will be at the middle element.
// 4. Return the data of the `slow` pointer as the middle element.

// Time Complexity:
// - Best Case: O(1) if the list has only one node .
// - Worst Case: O(n) where 'n' is the number of nodes in the linked list, when the `fast` pointer reaches the end of the list.
// - Average Case: O(n), as it requires traversing half of the list.

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
        printf("Memory Allocation Failed \n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node *insertNode()
{
    int n;
    printf("Enter Number of elements \n");
    scanf("%d", &n);
    int data;
    printf("Enter elements of Linked List\n");
    struct Node *head = NULL;
    struct Node *temp = NULL;
    for (int iteratorI = 0; iteratorI < n; iteratorI++)
    {
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
void midElement(struct Node *head)
{
    if (head == NULL)
    {
        printf("No elements \n");
        return;
    }
    struct Node *slow = head;
    struct Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Mid Element:");
    printf("%d \n", slow->data);
}
int main()
{
    struct Node *head = insertNode();
    midElement(head);
    return 0;
}