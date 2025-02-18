#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
#define MAX_SIZE_LEN 50
typedef struct Warehouse
{
    char itemName[MAX_SIZE][MAX_SIZE_LEN];
    int quantity[MAX_SIZE];
    int itemCount;
}Warehouse;
Warehouse* createWareHouse()
{
    Warehouse* warehouse=(Warehouse*)malloc(sizeof(Warehouse));
    warehouse->itemCount=0;
    return warehouse;
}
int stringCompare(char* str1,char* str2)
{
    while(*str1 && *str2)
    {
        if(*str2!=*str1)
        {
            return 0;
        }
        str1++;
        str2++;
    }
    return (*str1==*str2);
}
void stringCopy(char* dest,char* src)
{
    int iteratorI=0;
    while(*(src+iteratorI)!='\0')
    {
        *(dest+iteratorI)=*(src+iteratorI);
        iteratorI++;
    }
    *(dest+iteratorI)='\0';
}
void addItem(Warehouse* w,char* item,int quantity)
{
    for(int iteratorI=0;iteratorI<w->itemCount;iteratorI++)
    {
        if(stringCompare(w->itemName[iteratorI],item))
        {
            w->quantity[iteratorI]+=quantity;
            return;
        }
    }
    if(w->itemCount<MAX_SIZE)
    {
        stringCopy(w->itemName[w->itemCount],item);
        w->quantity[w->itemCount]=quantity;
        w->itemCount++;
    }
    else
    {
        printf("Warehouse is full\n");
    }
}
void updateItem(Warehouse* w,char* item,int quantity)
{
    for(int iteratorI=0;iteratorI<w->itemCount;iteratorI++)
    {
        if(stringCompare(w->itemName[iteratorI],item))
        {
            w->quantity[iteratorI]=quantity;
            return;
        }
    }
    printf("Item not found\n");
}
int listItem(Warehouse* w , char* item)
{
    for(int iteratorI=0;iteratorI<w->itemCount;iteratorI++)
    {
        if(stringCompare(w->itemName[iteratorI],item))
        {
            return w->quantity[iteratorI];
        }
    }
    return -1;
}
int main() 
{
    int n;
    scanf("%d", &n);

    Warehouse* warehouse = createWareHouse();

    for (int iteratorI = 0; iteratorI < n; iteratorI++) 
    {
        char command[10], item[MAX_SIZE_LEN];
        int quantity;

        scanf("%s", command);

        if (stringCompare(command, "ADD")) 
        {
            scanf("%s %d", item, &quantity);
            addItem(warehouse, item, quantity);
        } 
        else if (stringCompare(command, "UPDATE")) 
        {
            scanf("%s %d", item, &quantity);
            updateItem(warehouse, item, quantity);
        } 
        else if (stringCompare(command, "QUERY"))
        {
            scanf("%s", item);
            int result = listItem(warehouse, item);
            if (result == -1) 
            {
                printf("Item not found\n");
            } 
            else 
            {
                printf("%d\n", result);
            }
        }
    }

    free(warehouse);
    return 0;
}