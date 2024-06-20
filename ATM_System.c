#include <stdio.h>
#include <stdlib.h> // for exit() function

// Function prototypes
void displayMenu();
void checkBalance(float balance);
float deposit(float balance);
float withdraw(float balance);

int main() {
    int option;
    float balance = 1000.0; // initial balance

    do {
        // Display the ATM menu
        displayMenu();

        // Prompt user for option
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        // Perform actions based on user's choice
        switch(option) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                balance = deposit(balance);
                break;
            case 3:
                balance = withdraw(balance);
                break;
            case 4:
                printf("Encerrando o programa.\n");
                exit(0); // exit the program
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while(option != 4);

    return 0;
}

// Function to display ATM menu
void displayMenu() {
    printf("\n====== Menu ======\n");
    printf("1. Verificar saldo\n");
    printf("2. Depositar dinheiro\n");
    printf("3. Sacar dinheiro\n");
    printf("4. Sair\n");
}

// Function to check balance
void checkBalance(float balance) {
    printf("Seu saldo é: R$ %.2f\n", balance);
}

// Function to deposit money
float deposit(float balance) {
    float amount;
    printf("Digite o valor a ser depositado: R$ ");
    scanf("%f", &amount);
    balance += amount;
    printf("Depósito realizado com sucesso.\n");
    return balance;
}

// Function to withdraw money
float withdraw(float balance) {
    float amount;
    printf("Digite o valor a ser sacado: R$ ");
    scanf("%f", &amount);

    if (amount <= balance) {
        balance -= amount;
        printf("Retire seu dinheiro.\n");
    } else {
        printf("Saldo insuficiente.\n");
    }
    return balance;
}
