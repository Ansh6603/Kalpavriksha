// Problem Statement : Create a program in C that reads a series of characters into a singly linked list, sorts the characters in ascending order using the Selection Sort algorithm, and counts the number of vowels in the sorted list.
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
    char data;
    struct Node *next;
};

struct Node *createNode(char value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory Allocation Failed\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node *createLinkedList()
{
    int size;
    printf("Enter number of elements: \n");
    scanf("%d", &size);
    struct Node *head = NULL;
    struct Node *temp = NULL;
    printf("Enter characters for the linked list: \n");
    for (int iteratorI = 0; iteratorI < size; iteratorI++)
    {
        char value;
        scanf(" %c", &value);
        struct Node *newNode = createNode(value);
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
        printf("%c -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void selectionSort(struct Node *head)
{
    struct Node *current, *nextNode;
    if (head == NULL)
        return;
    for (current = head; current != NULL && current->next != NULL; current = current->next)
    {
        struct Node *minNode = current;
        for (nextNode = current->next; nextNode != NULL; nextNode = nextNode->next)
        {
            if (nextNode->data < minNode->data)
            {
                minNode = nextNode;
            }
        }
        if (minNode != current)
        {
            char tempValue = current->data;
            current->data = minNode->data;
            minNode->data = tempValue;
        }
    }
}

int countVowels(struct Node *head)
{
    int count = 0;
    struct Node *current = head;
    while (current != NULL)
    {
        if (current->data == 'a' || current->data == 'e' || current->data == 'i' || current->data == 'o' || current->data == 'u' ||
            current->data == 'A' || current->data == 'E' || current->data == 'I' || current->data == 'O' || current->data == 'U')
        {
            count++;
        }
        current = current->next;
    }
    return count;
}

int main()
{
    struct Node *head = createLinkedList();

    printf("Original Linked List:\n");
    printLinkedList(head);

    selectionSort(head);

    printf("Sorted Linked List:\n");
    printLinkedList(head);

    int vowelCount = countVowels(head);
    printf("Number of vowels in the list: %d\n", vowelCount);

    return 0;
}
