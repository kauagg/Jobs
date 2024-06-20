#include <stdio.h>
#include <stdlib.h> // for exit()

// Constants
#define MAX_STUDENTS 50
#define MAX_DAYS 31 // assuming a maximum of 31 days in a month

// Function prototypes
void displayMenu();
void markAttendance(int attendance[MAX_STUDENTS][MAX_DAYS], int numStudents, int day);
void displayAttendance(int attendance[MAX_STUDENTS][MAX_DAYS], int numStudents, int days);

int main() {
    int numStudents;
    printf("Digite o número de alunos: ");
    scanf("%d", &numStudents);

    if (numStudents > MAX_STUDENTS) {
        printf("Número de alunos excede o limite máximo.\n");
        exit(1);
    }

    int attendance[MAX_STUDENTS][MAX_DAYS] = {0}; // initialize all attendance to 0 (absent)

    int option, day;
    do {
        displayMenu();
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Digite o dia de presença (1-%d): ", MAX_DAYS);
                scanf("%d", &day);
                markAttendance(attendance, numStudents, day);
                break;
            case 2:
                displayAttendance(attendance, numStudents, MAX_DAYS);
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

// Function to display menu
void displayMenu() {
    printf("\n====== Menu ======\n");
    printf("1. Marcar presença\n");
    printf("2. Mostrar relatório de presença\n");
    printf("3. Sair\n");
}

// Function to mark attendance for a specific day
void markAttendance(int attendance[MAX_STUDENTS][MAX_DAYS], int numStudents, int day) {
    int i;
    printf("\nMarcar presença para o dia %d:\n", day);

    for (i = 0; i < numStudents; i++) {
        printf("Aluno %d (1 para presente, 0 para ausente): ", i + 1);
        scanf("%d", &attendance[i][day - 1]); // store attendance (1 or 0) for day
    }
}

// Function to display attendance report
void displayAttendance(int attendance[MAX_STUDENTS][MAX_DAYS], int numStudents, int days) {
    int i, j;
    printf("\nRelatório de presença:\n");

    // Header row: days
    printf("    ");
    for (j = 0; j < days; j++) {
        printf("Dia %d ", j + 1);
    }
    printf("\n");

    // Attendance data for each student
    for (i = 0; i < numStudents; i++) {
        printf("Aluno %d: ", i + 1);
        for (j = 0; j < days; j++) {
            printf("%d     ", attendance[i][j]);
        }
        printf("\n");
    }
}
