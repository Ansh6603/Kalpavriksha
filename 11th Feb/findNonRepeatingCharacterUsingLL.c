#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char data;
    int count;
    struct Node *next;
} Node;

Node *insertEnd(Node *head, char character)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = character;
    newNode->count = 1;
    newNode->next = NULL;
    if (head == NULL)
    {
        return newNode;
    }
    Node *temp = head;
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node *insert(Node *head, char character)
{
    Node *temp = head;
    while (temp!=NULL)
    {
        if (temp->data == character)
        {
            temp->count++;
            return head;
        }
        temp = temp->next;
    }
    return insertEnd(head, character);
}

char findNonRepeatingCharacter(Node *head)
{
    Node *temp = head;
    while (temp!=NULL)
    {
        if (temp->count == 1)
        {
            return temp->data;
        }
        temp = temp->next;
    }
    return '\0';
}

int main()
{
    char str[100];
    printf("Enter a string: \n");
    scanf("%s", str);
    Node *head = NULL;
    int iteratorI = 0;
    while (str[iteratorI] != '\0')
    {
        head = insert(head, str[iteratorI]);
        iteratorI++;
    }
    char result = findNonRepeatingCharacter(head);
    if (result)
    {
        printf("%c\n", result);
    }
    else
    {
        printf("null\n");
    }
    return 0;
}