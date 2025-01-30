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

void insertEnd(struct Node **result, int data)
{
    struct Node *newNode = createNode(data);
    if (*result == NULL)
    {
        *result = newNode;
    }
    else
    {
        struct Node *temp = *result;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void findTripletSum(struct Node *head1, struct Node *head2, struct Node *head3, int targetSum)
{
    struct Node *ptr1 = head1;
    while (ptr1 != NULL)
    {
        struct Node *ptr2 = head2;
        struct Node *ptr3 = head3;

        while (ptr2 != NULL && ptr3 != NULL)
        {
            int sum = ptr1->data + ptr2->data + ptr3->data;
            if (sum == targetSum)
            {
                printf("Triplet: %d -> %d -> %d\n", ptr1->data, ptr2->data, ptr3->data);
                return;
            }
            else if (sum < targetSum)
            {
                ptr2 = ptr2->next;
            }
            else
            {
                ptr3 = ptr3->next;
            }
        }
        ptr1 = ptr1->next;
    }
    printf("No triplet found with sum %d\n", targetSum);
}

void readInputString(char *inputString)
{
    int iteratorI = 0;
    char character;
    while ((character = getchar()) != '\n' && character != EOF)
    {
        *(inputString + iteratorI) = character;
        iteratorI++;
    }
    *(inputString + iteratorI) = '\0';
}

struct Node *createLinkedList(char *inputString)
{
    int size = 0;
    int data[200];
    int iteratorI = 0, iteratorJ = 0;

    while (*(inputString + iteratorI) != '\0')
    {
        if (*(inputString + iteratorI) >= '0' && *(inputString + iteratorI) <= '9')
        {
            data[iteratorJ++] = *(inputString + iteratorI) - '0';
        }
        iteratorI++;
    }

    struct Node *result = NULL;
    for (int iteratorI = 0; iteratorI < iteratorJ; iteratorI++)
    {
        insertEnd(&result, data[iteratorI]);
    }

    return result;
}

int main()
{
    char inputString1[200];
    char inputString2[200];
    char inputString3[200];

    printf("Enter Linked List 1\n");
    readInputString(inputString1);
    printf("Enter Linked List 2\n");
    readInputString(inputString2);
    printf("Enter Linked List 3\n");
    readInputString(inputString3);

    int targetSum;
    printf("Enter target Sum \n");
    scanf("%d", &targetSum);

    struct Node *head1 = createLinkedList(inputString1);
    struct Node *head2 = createLinkedList(inputString2);
    struct Node *head3 = createLinkedList(inputString3);

    findTripletSum(head1, head2, head3, targetSum);
    return 0;
}
