#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertAtEnd(struct Node **head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtBeginning(struct Node **head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void insertAtPosition(struct Node **head, int position, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (position == 1)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    int iteratorI = 1;
    while (iteratorI < position - 1 && temp != NULL)
    {
        temp = temp->next;
        iteratorI++;
    }

    if (temp == NULL)
    {
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void displayElements(struct Node *head)
{
    struct Node *temp = head;
    printf("Displaying elements:\n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void updateAtPosition(struct Node **head, int position, int value)
{
    if (position <= 0)
    {
        return;
    }

    struct Node *temp = *head;
    int iteratorI = 1;

    while (temp != NULL && iteratorI < position)
    {
        temp = temp->next;
        iteratorI++;
    }

    if (temp == NULL)
    {
        return;
    }

    temp->data = value;
}

void deleteAtBeginning(struct Node **head)
{
    if (*head == NULL)
    {
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteAtEnd(struct Node **head)
{
    if (*head == NULL)
    {
        return;
    }
    struct Node *temp = *head;

    if (temp->next == NULL)
    {
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteAtPosition(struct Node **head, int position)
{
    if (*head == NULL || position <= 0)
    {
        return;
    }

    struct Node *temp = *head;

    if (position == 1)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    int iteratorI = 1;
    while (temp != NULL && iteratorI < position - 1)
    {
        temp = temp->next;
        iteratorI++;
    }

    if (temp == NULL || temp->next == NULL)
    {
        return;
    }

    struct Node *nextNode = temp->next->next;
    free(temp->next);
    temp->next = nextNode;
}

int main()
{
    struct Node *head = NULL;
    int n;
    printf("Enter Number of Opeartions to be performed \n");
    scanf("%d", &n);
    int operation, value, position;

    for (int iteratorI = 0; iteratorI < n; iteratorI++)
    {
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
            scanf("%d", &value);
            insertAtEnd(&head, value);
            break;
        case 2:
            scanf("%d", &value);
            insertAtBeginning(&head, value);
            break;
        case 3:
            scanf("%d", &position);
            scanf("%d", &value);
            insertAtPosition(&head, position, value);
            break;
        case 4:
            displayElements(head);
            break;
        case 5:
            scanf("%d", &position);
            scanf("%d", &value);
            updateAtPosition(&head, position, value);
            break;
        case 6:
            deleteAtBeginning(&head);
            break;
        case 7:
            deleteAtEnd(&head);
            break;
        case 8:
            scanf("%d", &position);
            deleteAtPosition(&head, position);
            break;
        default:
            printf("Invalid operation \n");
        }
    }

    return 0;
}
