int main(){
    int ch;
    do{
        printf("\n--- CRUD Operations ---\n");
        printf("1. Create User\n");
        printf("2. Display Users\n");
        printf("3. Update User\n");
        printf("4. Delete User\n");
        printf("5. Exit Program\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: createUser(); break;
            case 2: displayUsers(); break;
            case 3: updateUser(); break;
            case 4: deleteUser(); break;
            case 5: printf("Exiting.....\n"); break;
            default: printf("Invalid choice.\n Try again.\n");
        }
    }while(ch!=5);
    return 0;
}