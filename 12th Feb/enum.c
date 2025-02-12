#include <stdio.h>
#include <string.h>

enum Fruit 
{ 
    APPLE, 
    BANANA, 
    ORANGE, 
    UNKNOWN 
};

enum Fruit getFruit(char *name) 
{
    if (strcmp(name, "apple") == 0) 
    {
        return APPLE;
    }
    if (strcmp(name, "banana") == 0)
    {
        return BANANA;
    } 
    if (strcmp(name, "orange") == 0) 
    {
        return ORANGE;
    }
    return UNKNOWN;
}

int main() {
    char fruitName[20];
    printf("Enter fruit name : ");
    scanf("%s", fruitName);

    enum Fruit fruit = getFruit(fruitName);
    switch (fruit) 
    {
        case APPLE:  
        {
            printf("You selected Apple.\n");
            break;
        }
        case BANANA:
        {
            printf("You selected Banana.\n"); 
            break;
        }
        case ORANGE:
        {
            printf("You selected Orange.\n"); 
            break;
        } 
        default:     
            printf("Invalid fruit.\n");
    }

    return 0;
}
