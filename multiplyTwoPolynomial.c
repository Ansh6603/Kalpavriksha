// Problem Statement:
// Represent two polynomials using singly linked lists, where each node contains a coefficient and an
// exponent. Implement a function to multiply the two polynomials and return the resultant
// polynomial as a linked list.

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> 

struct Node 
{
    int coefficient;
    int exponent;
    struct Node* next;
};

struct Node* createNode(int coefficient, int exponent)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) 
    {
        printf("Memory Allocation Failed \n");
        return NULL;
    }
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

void readInputString(char* inputString) 
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

int stringLength(char *inputString) 
{
    int iteratorI = 0;
    while (*(inputString + iteratorI) != '\0') 
    {
        iteratorI++;
    }
    return iteratorI;
}

void numberFromString(char *inputString, int length, int *size, int *coefficient, int *exponent) 
{
    int iteratorI = 0, iteratorJ = 0;
    while (iteratorI < length) 
    {
        int coeff = 0;
        int exponents = 0;  
        int sign = 1;

        if (*(inputString + iteratorI) == '-') 
        {
            sign = -1;
            iteratorI++;
        } 
        else if (*(inputString + iteratorI) == '+') 
        {
            iteratorI++;
        }

        if (*(inputString + iteratorI) >= '0' && *(inputString + iteratorI) <= '9') 
        {
            while (*(inputString + iteratorI) >= '0' && *(inputString + iteratorI) <= '9') 
            {
                coeff = coeff * 10 + (*(inputString + iteratorI) - '0');
                iteratorI++;
            }
        } 
        else if (*(inputString + iteratorI) == 'x') 
        {
            coeff = 1;
        }

        coeff *= sign;

        if (*(inputString + iteratorI) == 'x') 
        {
            iteratorI++;
            if (*(inputString + iteratorI) == '^') 
            {
                iteratorI++;
                if (*(inputString + iteratorI) >= '0' && *(inputString + iteratorI) <= '9') 
                {
                    while (*(inputString + iteratorI) >= '0' && *(inputString + iteratorI) <= '9') 
                    {
                        exponents = exponents * 10 + (*(inputString + iteratorI) - '0');
                        iteratorI++;
                    }
                }
            } 
            else 
            {
                exponents = 1;
            }
        } 
        else 
        {
            exponents = 0;
        }

        *(coefficient + iteratorJ) = coeff;
        *(exponent + iteratorJ) = exponents;
        iteratorJ++;
    }
    *size = iteratorJ;
}

void insertEnd(struct Node** result, int coefficient, int exponent) 
{
    struct Node* newNode = createNode(coefficient, exponent);
    if (*result == NULL)
    {
        *result = newNode;
    } 
    else 
    {
        struct Node* temp = *result;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

struct Node* createPolynomial(char *inputString) 
{
    int length = stringLength(inputString);
    int size = 0;
    int coefficient[10], exponent[10]; 
    numberFromString(inputString, length, &size, coefficient, exponent);
    struct Node* polynomial = NULL;
    for (int iteratorI = 0; iteratorI < size; iteratorI++) 
    {
        insertEnd(&polynomial, *(coefficient + iteratorI), *(exponent + iteratorI));
    }
    return polynomial;
}

struct Node* multiplyPolynomial(struct Node* polynomial1, struct Node* polynomial2) 
{
    struct Node* result = NULL;

    for (struct Node* term1 = polynomial1; term1 != NULL; term1 = term1->next) 
    {
        for (struct Node* term2 = polynomial2; term2 != NULL; term2 = term2->next) 
        {
            int newCoefficient = term1->coefficient * term2->coefficient;
            int newExponent = term1->exponent + term2->exponent;
            bool found = false;
            struct Node* temp = result;
            while (temp != NULL) 
            {
                if (temp->exponent == newExponent) 
                {
                    temp->coefficient += newCoefficient;
                    found = true;
                    break;
                }
                temp = temp->next;
            }
            if (!found) 
            {
                insertEnd(&result, newCoefficient, newExponent);
            }
        }
    }
    return result;
}

void displayPolynomial(struct Node* result) 
{
    struct Node* temp = result;
    bool first = true;
    while (temp != NULL) 
    {
        if (!first) {
            printf(" + ");
        }
        if (temp->exponent == 0)
        {
            printf("%d", temp->coefficient);
        } 
        else if (temp->exponent == 1) {
            printf("%dx", temp->coefficient);
        } 
        else 
        {
            printf("%dx^%d", temp->coefficient, temp->exponent);
        }
        temp = temp->next;
        first = false;
    }
    printf("\n");
}

int main() 
{
    char inputString1[100];
    char inputString2[100];
    printf("Enter the first polynomial: \n");
    readInputString(inputString1);
    printf("Enter the second polynomial: \n");
    readInputString(inputString2);

    struct Node* polynomial1 = createPolynomial(inputString1);
    struct Node* polynomial2 = createPolynomial(inputString2);

    struct Node* result = multiplyPolynomial(polynomial1, polynomial2);

    printf("The result of polynomial multiplication is: ");
    displayPolynomial(result);

    return 0;
}
