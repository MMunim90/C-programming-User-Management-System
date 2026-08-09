#include <stdio.h>
#include <string.h>
#define MAX_USERS 10
#define CREDENTIAL_LENGTH 30

typedef struct
{
    char username[CREDENTIAL_LENGTH];
    char password[CREDENTIAL_LENGTH];
} User;

User users[MAX_USERS];
int user_count = 0;

void register_user();
int login_user(); // returns the user index
void fix_fgets_input(char *);
void input_password(char *);

int main()
{
    while (1)
    {
        int option;
        printf("\n ----- Welcome to User Management System -----");
        printf("\n1. Register");
        printf("\n2. Login");
        printf("\n3. Exit");

        printf("\nSelect an option: ");
        scanf("%d", &option);
        getchar();  // Consume extra enter

        if (option == 1)
        {
            register_user();
        }
        else if (option == 2)
        {
            int user_index = login_user();

            if (user_index >= 0)
            {
                printf("\nLogin successful! Welcome, %s!\n", users[user_index].username);
            }
            else
            {
                printf("\nLogin failed! Incorrect username or password.\n");
            }
        }
        else if (option == 3)
        {
            printf("\nExiting Program.\n");
            return 0;
        }
        else
        {
            printf("\nInvalid Option. Please Try Again!\n");
        }
    }

    return 0;
}

void register_user()
{
    if (user_count < MAX_USERS)
    {
        int new_index = user_count;
        printf("\n--- Register a new user ---\n");
        printf("\nEnter username: ");
        fgets(users[new_index].username, CREDENTIAL_LENGTH, stdin);
        fix_fgets_input(users[new_index].username);
        input_password(users[new_index].password);
        user_count++;
        printf("\nRegistration successful!\n");
    }
    else
    {
        printf("\nMaximum %d users can be stored! No more registration allowed!!!\n", MAX_USERS);
        return;
    }
}

int login_user()
{
    char username[CREDENTIAL_LENGTH];
    char password[CREDENTIAL_LENGTH];
    printf("\n--- Login to a user ---\n");
    printf("\nEnter username: ");
    fgets(username, CREDENTIAL_LENGTH, stdin);
    fix_fgets_input(username);
    input_password(password);

    for(int i=0; i<user_count; i++){
        if(strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0){
            return i;
        }
    }

    return -1;
}

void fix_fgets_input(char *string)
{
    int index = strcspn(string, "\n");
    string[index] = '\0';
}

void input_password(char *password)
{
    printf("Enter password: ");
    fgets(password, CREDENTIAL_LENGTH, stdin);
    fix_fgets_input(password);
}