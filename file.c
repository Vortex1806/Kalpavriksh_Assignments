#include <stdio.h>
#include <stdlib.h>
#define FILENAME "users.txt"
typedef struct
{
    int id;
    char name[50];
    int age;
} User;

int userIdCheck(int userId)
{
    FILE *file = fopen(FILENAME, "r");
    if (!file)
    {
        file = fopen(FILENAME, "w");
        if (!file)
        {
            printf("Error: Cannot create file\n");
            return -1;
        }
        fclose(file);
        return 0;
    }
    User user;
    while (fscanf(file, "%d,%49[^,],%d", &user.id, user.name, &user.age) == 3)
    {
        if (user.id == userId)
        {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

int isValidNumber(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            return 0;
        }
    }
    return 1;
}
int isValidName(char *name)
{
    for (int i = 0; name[i] != '\0'; i++)
    {
        if (name[i] == ',' || name[i] == '\n')
        {
            return 0;
        }
    }
    return 1;
}

void string_copy(char dest[], const char src[])
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int custom_atoi(char *str)
{
    int result = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        result = (result * 10) + (str[i] - '0');
    }
    return result;
}

int getValidInteger(char *prompt)
{
    char input[20];
    int value;

    while (1)
    {
        printf("%s", prompt);
        scanf("%10s", input);

        if (isValidNumber(input))
        {
            value = custom_atoi(input);
            return value;
        }
        printf("Invalid input. Please enter a valid number.\n");
    }
}

void createUser()
{
    User user;
    char tempName[50];
    do
    {
        user.id = getValidInteger("Enter UserID: ");
        if (userIdCheck(user.id))
        {
            printf("Error: UserID %d already exists\n", user.id);
        }
        else
        {
            break;
        }
    } while (1);
    do
    {
        printf("Enter UserName (no commas allowed): ");
        scanf(" %49[^\n]", tempName);
        if (isValidName(tempName))
        {
            string_copy(user.name, tempName);
            break;
        }
        else
        {
            printf("Invalid username. Commas are not allowed. Please try again.\n");
        }
    } while (1);

    user.age = getValidInteger("Enter User Age: ");

    FILE *file = fopen(FILENAME, "a");
    if (!file)
    {
        printf("Error opening file\n");
        return;
    }
    fprintf(file, "%d,%s,%d\n", user.id, user.name, user.age);
    fclose(file);
    printf("User added successfully\n");
}
void displayUsers()
{
    User user;
    FILE *file = fopen(FILENAME, "r");
    if (!file)
    {
        printf("Error: No users found. File does not exist\n");
        return;
    }
    printf("UserId  UserName  Age\n\n");
    if (fscanf(file, "%d,%49[^,],%d", &user.id, user.name, &user.age) != 3)
    {
        fclose(file);
        printf("No users found.\n");
    }
    rewind(file);

    while (fscanf(file, "%d,%49[^,],%d", &user.id, user.name, &user.age) == 3)
    {
        printf("   %d    %s    %d\n", user.id, user.name, user.age);
    }
    fclose(file);
}

void updateUser()
{
    int userId, flag = 0;
    User user;
    FILE *file = fopen(FILENAME, "r");
    if (!file)
    {
        printf("Error: No users found. File does not exist\n");
        return;
    }

    User users[100];
    int n = 0;

    while (fscanf(file, "%d,%49[^,],%d", &user.id, user.name, &user.age) == 3)
    {
        users[n] = user;
        n++;
    }
    fclose(file);
    if (n == 0)
    {
        printf("No users in the system.\n");
        return;
    }
    userId = getValidInteger("Enter UserID to update: ");
    for (int i = 0; i < n; i++)
    {
        if (users[i].id == userId)
        {
            flag = 1;
            char tempName[50];
            do
            {
                printf("Enter new UserName (no commas allowed): ");
                scanf(" %49[^\n]", tempName);
                if (isValidName(tempName))
                {
                    string_copy(users[i].name, tempName);
                    break;
                }
                else
                {
                    printf("Invalid username. Commas are not allowed. Please try again.\n");
                }
            } while (1);
            users[i].age = getValidInteger("Enter new User Age: ");
            printf("\nSuccessfully modified to:\n");
            printf("UserID: %d, UserName: %s, Age: %d\n", users[i].id, users[i].name, users[i].age);
            break;
        }
    }
    if (!flag)
    {
        printf("Error: UserID %d not found\nn", userId);
        return;
    }
    file = fopen(FILENAME, "w");
    if (!file)
    {
        printf("Error opening file\n");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(file, "%d,%s,%d\n", users[i].id, users[i].name, users[i].age);
    }
    fclose(file);
}
void deleteUser()
{
    int userId, flag = 0;
    User user;
    FILE *file = fopen(FILENAME, "r");
    if (!file)
    {
        printf("Error: No users found. File does not exist\n");
        return;
    }
    User users[100];
    int n = 0;

    while (fscanf(file, "%d,%49[^,],%d", &user.id, user.name, &user.age) == 3)
    {
        users[n] = user;
        n++;
    }
    fclose(file);

    if (n == 0)
    {
        printf("No users in the system.\n");
        return;
    }

    userId = getValidInteger("Enter UserID to delete: ");

    for (int i = 0; i < n; i++)
    {
        if (users[i].id == userId)
        {
            flag = 1;
            for (int j = i; j < n - 1; j++)
            {
                users[j] = users[j + 1];
            }
            n--;
            break;
        }
    }

    if (!flag)
    {
        printf("Error: UserID %d not found\n", userId);
        return;
    }

    file = fopen(FILENAME, "w");
    if (!file)
    {
        printf("Error opening file\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(file, "%d,%s,%d\n", users[i].id, users[i].name, users[i].age);
    }
    fclose(file);
    printf("User with UserID %d deleted successfully\n", userId);
}

int main()
{
    int ch;
    do
    {
        printf("\n--- CRUD Operations ---\n");
        printf("1. Create User\n");
        printf("2. Display Users\n");
        printf("3. Update User\n");
        printf("4. Delete User\n");
        printf("5. Exit Program\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            createUser();
            break;
        case 2:
            displayUsers();
            break;
        case 3:
            updateUser();
            break;
        case 4:
            deleteUser();
            break;
        case 5:
            printf("Exiting.....\n");
            break;
        default:
            printf("Invalid choice\n\n");
        }
    } while (ch != 5);
    return 0;
}