#include <stdio.h>
#include <string.h> // for string functions like strcmp

// Function prototypes
int login();
int changePassword();

// Global variables
char username[20] = "admin";     // Default username
char password[20] = "password";  // Default password

int main() {
    int option;

    do {
        printf("\n====== Security System Menu ======\n");
        printf("1. Login\n");
        printf("2. Change Password\n");
        printf("3. Exit\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                if (login()) {
                    printf("Login bem-sucedido.\n");
                    // Place your secured actions or menu here
                } else {
                    printf("Login falhou. Tente novamente.\n");
                }
                break;
            case 2:
                if (changePassword()) {
                    printf("Senha alterada com sucesso.\n");
                } else {
                    printf("Alteração de senha falhou. Tente novamente.\n");
                }
                break;
            case 3:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while(option != 3);

    return 0;
}

// Function to perform login
int login() {
    char inputUsername[20];
    char inputPassword[20];

    printf("Digite o nome de usuário: ");
    scanf("%s", inputUsername);
    printf("Digite a senha: ");
    scanf("%s", inputPassword);

    // Check if username and password match
    if (strcmp(inputUsername, username) == 0 && strcmp(inputPassword, password) == 0) {
        return 1; // Successful login
    } else {
        return 0; // Failed login
    }
}

// Function to change password
int changePassword() {
    char currentPassword[20];
    char newPassword[20];

    printf("Digite a senha atual: ");
    scanf("%s", currentPassword);

    // Check if current password matches
    if (strcmp(currentPassword, password) == 0) {
        printf("Digite a nova senha: ");
        scanf("%s", newPassword);
        strcpy(password, newPassword); // Update password
        return 1; // Password changed successfully
    } else {
        return 0; // Incorrect current password
    }
}
