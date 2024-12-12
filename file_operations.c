#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILENAME "users.txt"

typedef struct
{
    int id;
    char name[50];
    int age;
} User;

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

void addUser()
{
    User user;
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL)
    {
        perror("Unable to open file");
        return;
    }

    printf("Enter user ID: ");
    scanf("%d", &user.id);
    printf("Enter user name: ");
    scanf("%s", user.name);
    printf("Enter user age: ");
    scanf("%d", &user.age);

    fprintf(file, "%d %s %d\n", user.id, user.name, user.age);
    fclose(file);
    printf("User added successfully!\n");
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
    while (fscanf(file, "%d %s %d", &user.id, user.name, &user.age) != EOF)
    {
        printf("ID: %d, Name: %s, Age: %d\n", user.id, user.name, user.age);
    }
    fclose(file);
}

void updateUser()
{
    int id, found = 0;
    User user;
    FILE *file = fopen(FILENAME, "r");
    FILE *newFile = fopen("temp.txt", "w");
    if (file == NULL || newFile == NULL)
    {
        perror("Unable to open file");
        return;
    }

    printf("Enter user ID to update: ");
    scanf("%d", &id);

    while (fscanf(file, "%d %s %d", &user.id, user.name, &user.age) != EOF)
    {
        if (user.id == id)
        {
            found = 1;
            printf("Enter new name: ");
            scanf("%s", user.name);
            printf("Enter new age: ");
            scanf("%d", &user.age);
        }
        fprintf(newFile, "%d %s %d\n", user.id, user.name, user.age);
    }

    fclose(file);
    fclose(newFile);
    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (found)
    {
        printf("User updated successfully!\n");
    }
    else
    {
        printf("User with ID %d not found.\n", id);
    }
}

void deleteUser()
{
    int id, found = 0;
    User user;
    FILE *file = fopen(FILENAME, "r");
    FILE *tempFile = fopen("temp.txt", "w");
    if (file == NULL || tempFile == NULL)
    {
        perror("Unable to open file");
        return;
    }

    printf("Enter user ID to delete: ");
    scanf("%d", &id);

    while (fscanf(file, "%d %s %d", &user.id, user.name, &user.age) != EOF)
    {
        if (user.id != id)
        {
            fprintf(tempFile, "%d %s %d\n", user.id, user.name, user.age);
        }
        else
        {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);
    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (found)
    {
        printf("User deleted successfully!\n");
    }
    else
    {
        printf("User with ID %d not found.\n", id);
    }
}

int main()
{
    int choice;

    createFile();

    do
    {
        printf("\nUser  Management System\n");
        printf("1. Add User\n");
        printf("2. Read Users\n");
        printf("3. Update User\n");
        printf("4. Delete User\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

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