#include <stdio.h>
#define MAX_USERS 10

typedef struct
{
    char username[30];
    char password[30];
} User;

User users[MAX_USERS];
int user_count = 0;

void register_user();
int login_user(); // returns the user index

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
        
        if(option == 1){
            register_user(); 
        }
        else if(option == 2){
            int user_index = login_user(); 

            if(user_index >= 0){
                printf("\nLogin successful! Welcome, %s!", users[user_index].username);
            }else{
                printf("\nLogin failed! Incorrect username or password.\n");
            }
        }
        else if(option == 3){
            printf("\nExiting Program.\n");
            return 0;
        }
        else{
            printf("\nInvalid Option. Please Try Again!\n");
        }
    }

    return 0;
}

void register_user(){
    printf("Dummy registration");
}

int login_user(){
    return -1;
}