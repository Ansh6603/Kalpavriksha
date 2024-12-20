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

void readAndPrint(const char *inputMsg, const char *outputMsg, void *input, char type)
{
    printf("%s", inputMsg);

    if (type == 'i')
    {
        scanf("%d", (int *)input);
    }
    else if (type == 's')
    {
        scanf("%s", (char *)input);
    }

    printf("%s", outputMsg);

    if (type == 'i')
    {
        printf("%d\n", *(int *)input);
    }
    else if (type == 's')
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

    readAndPrint("Enter user ID: ", "User ID: ", &newUser.userId, 'i');

    if (checkUserIdExists(newUser.userId))
    {
        printf("Error: User ID %d already exists!\n", newUser.userId);
        fclose(file);
        return;
    }

    readAndPrint("Enter user name: ", "User Name: ", newUser.userName, 's');
    readAndPrint("Enter user age: ", "User Age: ", &newUser.userAge, 'i');

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

    readAndPrint("Enter user ID to update: ", "User ID to update: ", &userIdToUpdate, 'i');

    while (fscanf(file, "%d %s %d", &user.userId, user.userName, &user.userAge) != EOF)
    {
        if (user.userId == userIdToUpdate)
        {
            isFound = 1;
            readAndPrint("Enter new name: ", "New Name: ", user.userName, 's');
            readAndPrint("Enter new age: ", "New Age: ", &user.userAge, 'i');
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

    readAndPrint("Enter user ID to delete: ", "User ID to delete: ", &userIdToDelete, 'i');

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

        readAndPrint("Enter your choice: ", "You selected: ", &choice, 'i');

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
