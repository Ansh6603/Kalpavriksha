#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "users.txt"

typedef struct
{
    int userId;
    char userName[50];
    int userAge;
} User;

int compareStrings(const char *str1, const char *str2)
{
    while (*str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

void readAndPrint(const char *inputMsg, const char *outputMsg, void *input, const char *type)
{
    printf("%s", inputMsg);

    if (compareStrings(type, "typeInt") == 0)
    {
        scanf("%d", (int *)input);
    }
    else if (compareStrings(type, "typeString") == 0)
    {
        scanf("%s", (char *)input);
    }

    printf("%s", outputMsg);

    if (compareStrings(type, "typeInt") == 0)
    {
        printf("%d\n", *(int *)input);
    }
    else if (compareStrings(type, "typeString") == 0)
    {
        printf("%s\n", (char *)input);
    }
}

void createFile()
{
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL)
    {
        perror("Unable to create file");
        exit(EXIT_FAILURE);
    }
    fclose(file);
}

int checkUserIdExists(int userId)
{
    User user;
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL)
    {
        return 0;
    }

    while (fscanf(file, "%d %s %d", &user.userId, user.userName, &user.userAge) != EOF)
    {
        if (user.userId == userId)
        {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

void addUser()
{
    User newUser;
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL)
    {
        perror("Unable to open file");
        return;
    }

    readAndPrint("Enter user ID: ", "User ID: ", &newUser.userId, "typeInt");

    if (checkUserIdExists(newUser.userId))
    {
        printf("Error: User ID %d already exists!\n", newUser.userId);
        fclose(file);
        return;
    }

    readAndPrint("Enter user name: ", "User Name: ", newUser.userName, "typeString");
    readAndPrint("Enter user age: ", "User Age: ", &newUser.userAge, "typeInt");

    fprintf(file, "%d %s %d\n", newUser.userId, newUser.userName, newUser.userAge);
    fclose(file);
}

void readUsers()
{
    User user;
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL)
    {
        printf("No users found.\n");
        return;
    }

    printf("User Records:\n");
    while (fscanf(file, "%d %s %d", &user.userId, user.userName, &user.userAge) != EOF)
    {
        printf("ID: %d, Name: %s, Age: %d\n", user.userId, user.userName, user.userAge);
    }
    fclose(file);
}

void updateUser()
{
    int userIdToUpdate, isFound = 0;
    User user;
    FILE *file = fopen(FILENAME, "r");
    FILE *newFile = fopen("temp.txt", "w");
    if (file == NULL || newFile == NULL)
    {
        perror("Unable to open file");
        return;
    }

    readAndPrint("Enter user ID to update: ", "User ID to update: ", &userIdToUpdate, "typeInt");

    while (fscanf(file, "%d %s %d", &user.userId, user.userName, &user.userAge) != EOF)
    {
        if (user.userId == userIdToUpdate)
        {
            isFound = 1;
            readAndPrint("Enter new name: ", "New Name: ", user.userName, "typeString");
            readAndPrint("Enter new age: ", "New Age: ", &user.userAge, "typeInt");
        }
        fprintf(newFile, "%d %s %d\n", user.userId, user.userName, user.userAge);
    }

    fclose(file);
    fclose(newFile);
    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (isFound)
    {
        printf("User updated successfully!\n");
    }
    else
    {
        printf("User with ID %d not found.\n", userIdToUpdate);
    }
}

void deleteUser()
{
    int userIdToDelete, isFound = 0;
    User user;
    FILE *file = fopen(FILENAME, "r");
    FILE *tempFile = fopen("temp.txt", "w");
    if (file == NULL || tempFile == NULL)
    {
        perror("Unable to open file");
        return;
    }

    readAndPrint("Enter user ID to delete: ", "User ID to delete: ", &userIdToDelete, "typeInt");

    while (fscanf(file, "%d %s %d", &user.userId, user.userName, &user.userAge) != EOF)
    {
        if (user.userId != userIdToDelete)
        {
            fprintf(tempFile, "%d %s %d\n", user.userId, user.userName, user.userAge);
        }
        else
        {
            isFound = 1;
        }
    }

    fclose(file);
    fclose(tempFile);
    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (isFound)
    {
        printf("User deleted successfully!\n");
    }
    else
    {
        printf("User with ID not found.\n");
    }
}

int main()
{
    int choice;

    createFile();

    do
    {
        printf("\nUser Management System\n");
        printf("1. Add User\n");
        printf("2. Read Users\n");
        printf("3. Update User\n");
        printf("4. Delete User\n");
        printf("5. Exit\n");

        readAndPrint("Enter your choice: ", "You selected: ", &choice, "typeInt");

        switch (choice)
        {
        case 1:
            addUser();
            break;
        case 2:
            readUsers();
            break;
        case 3:
            updateUser();
            break;
        case 4:
            deleteUser();
            break;
        case 5:
            printf("Exit\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}
