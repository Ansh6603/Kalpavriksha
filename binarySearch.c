// Problem Statement : Write a C program to perform a binary search in a linked list of n integers. After performing the binary search, count how many elements in the linked list are greater than the found key and display this count.

// // Steps:
// 1. Ensure that the linked list is sorted before performing the binary search.
// 2. Use the slow and fast pointer approach to find the middle node.
// 3. Compare the target element with the middle element of the list.
// 4. If the target element is smaller than the middle element, search the left half of the list.
// 5. If the target element is larger than the middle element, search the right half of the list.
// 6. Repeat the above steps until the element is found or the search space is exhausted.

// Time Complexity:
// - Best Case: O(1) if the middle element matches the target.
// - Worst Case: O(n), as in the case where you need to traverse the entire list.
// - Average Case: O(log n), where 'n' is the number of elements in the list .

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

struct Node *findMiddle(struct Node *start, struct Node *end)
{
    struct Node *slow = start;
    struct Node *fast = start;

    while (fast != end && fast->next != end)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int binarySearch(struct Node *head, int key)
{
    struct Node *start = head;
    struct Node *end = NULL;

    while (start != end)
    {
        struct Node *mid = findMiddle(start, end);

        if (mid == NULL)
        {
            break;
        }
        if (mid->data == key)
        {
            return 1;
        }
        if (mid->data < key)
        {
            start = mid->next;
        }
        else
        {
            end = mid;
        }
    }
    return 0;
}

int countGreaterThanKey(struct Node *head, int key)
{
    struct Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        if (temp->data > key)
        {
            count++;
        }
        temp = temp->next;
    }
    return count;
}

int main()
{
    int key;
    struct Node *head = createLinkedList();

    printf("Enter the key to search: \n");
    scanf("%d", &key);

    int found = binarySearch(head, key);
    if (found)
    {
        printf("Element %d found in the list\n", key);
        int greaterCount = countGreaterThanKey(head, key);
        printf("Number of elements greater than %d: %d\n", key, greaterCount);
    }
    else
    {
        printf("Element %d not found in the list\n", key);
    }

    return 0;
}
