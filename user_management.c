#include <stdio.h>

void register_user();
void login_user();

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
            // 
        }
        else if(option == 2){
            // 
        }
        else if(option == 3){
            printf("\nExiting Program...");
            return 0;
        }
        else{
            printf("\nInvalid Option. Please Try Again!");
        }
    }

    return 0;
}