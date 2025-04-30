// Problem Statement:
// Create a program that represents two polynomials as singly linked lists, where each node contains
// a coefficient and an exponent. Implement a function to add the two polynomials and return the
// resulting polynomial as a linked list.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
        printf("Memory Allocation Failed\n");
        return NULL;
    }
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
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

void readInputString(char* inputString) 
{
    int iteratorI = 0;
    char character;
    while ((character = getchar()) != '\n' && character != EOF) 
    {
        *(inputString + iteratorI++) = character;
    }
    *(inputString + iteratorI) = '\0';
}

int getStringLength(char* inputString)
{
    int iteratorI = 0;
    while (*(inputString + iteratorI) != '\0') 
    {
        iteratorI++;
    }
    return iteratorI;
}

void numberFromString(char *inputString, int length, int *coefficients, int *exponents, int *size) 
{
    int iteratorI = 0, iteratorJ = 0;
    while (iteratorI < length) 
    {
        int coeff = 0, exp = 0;
        int sign = 1;
        
        if (*(inputString+iteratorI) == '-') 
        {
            sign = -1;
            iteratorI++;
        } 
        else if (*(inputString+iteratorI) == '+') 
        {
            iteratorI++;
        }

        if ((*(inputString+iteratorI) >= '0' && *(inputString+iteratorI) <= '9')) 
        {
            while (iteratorI < length && (*(inputString+iteratorI) >= '0' && *(inputString+iteratorI) <= '9')) 
            {
                coeff = coeff * 10 + (*(inputString+iteratorI) - '0');
                iteratorI++;
            }
        } 
        else if (*(inputString+iteratorI) == 'x') 
        {
            coeff = 1;
        }
        
        coeff *= sign;

        if (*(inputString+iteratorI) == 'x') 
        {
            iteratorI++;
            if (*(inputString+iteratorI) == '^')
            {
                iteratorI++;
                exp = 0;
                while (iteratorI < length && (*(inputString+iteratorI) >= '0' && *(inputString+iteratorI) <= '9')) 
                {
                    exp = exp * 10 + (*(inputString+iteratorI) - '0');
                    iteratorI++;
                }
            } 
            else
            {
                exp = 1;
            }
        } 
        else 
        {
            exp = 0;
        }

        *(coefficients+iteratorJ) = coeff;
        *(exponents+iteratorJ) = exp;
        iteratorJ++;
    }
    *size = iteratorJ;
}

struct Node* createPolynomialFromInput(char* inputString) 
{
    int length = getStringLength(inputString);
    int coefficients[10], exponents[10];
    int size = 0;

    numberFromString(inputString, length, coefficients, exponents, &size);

    struct Node* polynomial = NULL;
    for (int iteratorI = 0; iteratorI < size; iteratorI++) 
    {
        insertEnd(&polynomial, *(coefficients+iteratorI), *(exponents+iteratorI));
    }

    return polynomial;
}

struct Node* addTwoPolynomial(struct Node* poly1, struct Node* poly2) 
{
    struct Node* result = NULL;
    while (poly1 != NULL || poly2 != NULL) 
    {
        if (poly1 != NULL && (poly2 == NULL || poly1->exponent > poly2->exponent)) 
        {
            insertEnd(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } 
        else if (poly2 != NULL && (poly1 == NULL || poly2->exponent > poly1->exponent)) 
        {
            insertEnd(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        }
        else 
        {
            insertEnd(&result, poly1->coefficient + poly2->coefficient, poly1->exponent);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    return result;
}

void displayPolynomial(struct Node* result) 
{
    while (result != NULL) 
    {
        if (result->exponent == 0) 
        {
            printf("%d", result->coefficient);
        } 
        else if (result->exponent == 1) 
        {
            printf("%dx", result->coefficient);
        } 
        else
        {
            printf("%dx^%d", result->coefficient, result->exponent);
        }
        if (result->next != NULL) 
        {
            printf(" -> ");
        }
        result = result->next;
    }
    printf("\n");
}

int main() 
{
    char inputString1[100], inputString2[100];

    printf("Enter the first polynomial: ");
    readInputString(inputString1);

    printf("Enter the second polynomial: ");
    readInputString(inputString2);

    struct Node* polynomial1 = createPolynomialFromInput(inputString1);
    struct Node* polynomial2 = createPolynomialFromInput(inputString2);

    struct Node* result = addTwoPolynomial(polynomial1, polynomial2);

    printf("The result of polynomial addition is: ");
    displayPolynomial(result);

    return 0;
}
