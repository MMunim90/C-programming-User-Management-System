#include <stdio.h>
#include <string.h>
#define MAX_USERS 15
#define CREDENTIAL_LENGTH 30

typedef struct
{
    char username[CREDENTIAL_LENGTH];
    char password[CREDENTIAL_LENGTH];
} User;

User users[MAX_USERS];
int user_count = 2;

void register_user();
int login_user(); // returns the user index
void fix_fgets_input(char *);
void input_username(char *);
void input_password(char *);
void adminAndModerator();

int main()
{
    while (1)
    {
        strcpy(users[0].username, "Admin");
        strcpy(users[0].password, "admin");
        strcpy(users[1].username, "Moderator");
        strcpy(users[1].password, "moderator");

        int option;

        printf("\n ----- Welcome to User Management System -----");
        printf("\n1. Register");
        printf("\n2. Login");
        printf("\n3. Exit");

        printf("\nSelect an option: ");
        scanf("%d", &option);
        getchar(); // Consume extra enter

        if (option == 1)
        {
            register_user();
        }
        else if (option == 2)
        {
            int user_index = login_user();

            if (user_index > 0)
            {
                printf("\n\033[32mLogin successful! Welcome, %s!\033[0m\n", users[user_index].username); // green colored text
                if (user_index == 1)
                {
                    adminAndModerator();
                }else
                {
                    printf("\033[32mMember number: %dXbit.\033[0m\n", user_index + 1);
                }
            }else if(user_index == 0){
                printf("\nExiting...\n");
            }else
            {
                printf("\n\033[31mLogin failed! Incorrect username or password!!!\033[0m\n"); // red colored text
            }
        }
        else if (option == 3)
        {
            printf("\nExiting Program...\n");
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
        if (strcmp(users[new_index].username, "Admin") == 0 || strcmp(users[new_index].username, "Moderator") == 0)
        {
            printf("\n\033[31mUsing "
                   "Admin"
                   " or "
                   "Moderator"
                   " as an username is prohibited!!!\033[0m\n");
            return;
        }
        input_password(users[new_index].password);
        user_count++;
        printf("\n\033[32mRegistration successful! Member number: %dXbit.\033[0m\n", user_count);
    }
    else
    {
        printf("\n\033[31mMaximum %d users can be stored! No more registration allowed!!!\033[0m\n", MAX_USERS);
        return;
    }
}

int login_user()
{
    while (1)
    {
        char username[CREDENTIAL_LENGTH];
        char password[CREDENTIAL_LENGTH];
        int opt;

        printf("\n--- Login as an user ---\n");

        printf("\n1. Admin or Moderator");
        printf("\n2. Member");
        printf("\n3. Exit");

        printf("\nSelect an option: ");
        scanf("%d", &opt);
        getchar(); // Consume extra enter

        if (opt == 1)
        {
            input_username(username);
            input_password(password);

            if (strcmp(username, "Admin") == 0 && strcmp(password, "admin") == 0 || strcmp(username, "Moderator") == 0 && strcmp(password, "moderator") == 0)
            {
                return 1;
            }else
            {
                return -1;
            }
        }
        else if (opt == 2)
        {
            input_username(username);
            input_password(password);

            for (int i = 2; i < user_count; i++)
            {
                if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0)
                {
                    return i;
                }
            }
        }
        else if (opt == 3)
        {
            return 0;
        }
        else
        {
            printf("\nInvalid Option. Please Try Again!\n");
        }

        return -1;
    }
}

void fix_fgets_input(char *string)
{
    int index = strcspn(string, "\n");
    string[index] = '\0';
}

void input_username(char *username)
{
    printf("\nEnter username: ");
    fgets(username, CREDENTIAL_LENGTH, stdin);
    fix_fgets_input(username);
}

void input_password(char *password)
{
    printf("Enter password: ");
    fgets(password, CREDENTIAL_LENGTH, stdin);
    fix_fgets_input(password);
}

void adminAndModerator(){
    printf("\nHello Administrator!!!\n");
}