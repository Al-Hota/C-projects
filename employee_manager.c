#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int old_emp;
    int new_emp;
    int rank_position;
} ReplacementRecord;

#define MAX_HISTORY 100
ReplacementRecord history[MAX_HISTORY];
int history_count = 0;

void safe_input_check(int *x){
    if (scanf("%d", x) != 1) {
        printf("Invalid input.\n");
        exit(1);
    }
}
void safe_input_check_char(char *x){
    if (scanf(" %c", x) != 1) {
        printf("Invalid input.\n");
        exit(1);
    }
}

void employee_sort(int emp[10], int rank[10]){

    int *pEmp = emp;
    int *pRank = rank;

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (pEmp[i] == pRank[j]){
                switch (j){
                    case 0: printf("Employee %d is ranked 1st\n", pEmp[i]); break;
                    case 1: printf("Employee %d is ranked 2nd\n", pEmp[i]); break;
                    case 2: printf("Employee %d is ranked 3rd\n", pEmp[i]); break;
                    case 3: printf("Employee %d is ranked 4th\n", pEmp[i]); break;
                    case 4: printf("Employee %d is ranked 5th\n", pEmp[i]); break;
                    case 5: printf("Employee %d is ranked 6th\n", pEmp[i]); break;
                    case 6: printf("Employee %d is ranked 7th\n", pEmp[i]); break;
                    case 7: printf("Employee %d is ranked 8th\n", pEmp[i]); break;
                    case 8: printf("Employee %d is ranked 9th\n", pEmp[i]); break;
                    case 9: printf("Employee %d is ranked 10th\n", pEmp[i]); break;
                }


            }
        }
    }
    return;
}


void replace_employee(int rank[10], int old_emp, int new_emp){
  for (int i = 0; i < 10; i++) {
        if (rank[i] == old_emp) {
            rank[i] = new_emp;
            printf("Replacement successful. Employee %d replaced by %d at rank %d.\n", 
                   old_emp, new_emp, i + 1);
            
            if (history_count < MAX_HISTORY) {
                history[history_count].old_emp = old_emp;
                history[history_count].new_emp = new_emp;
                history[history_count].rank_position = i + 1;
                history_count++;
            }
            return;
        }
    }
    printf("Employee %d not found in the rankings.\n", old_emp);
}

void display_history(){
    if (history_count == 0){
        printf("No replacements have been made yet.\n");
        return;
    }
    printf("\n=== REPLACEMENT HISTORY ===\n");
    for (int i = 0; i < history_count; i++){
        printf("Employee %d replaced by %d at rank %d\n",
            i + 1,
            history[i].old_emp,
            history[i].new_emp,
            history[i].rank_position);
    }
}


int main(void){
    int emp[100];
    int rank[10];
    int choice;
    char continue_choice;
    int loop = 1;
    int initialized = 0;
    while (loop) {
        printf("=== Employee Manager ===\n");
        printf("1. Sort Employees\n");
        printf("2. Replace Employee\n");
        printf("3. Display Replacement History\n");
        printf("4. Exit\n");
        printf("Enter choice: \n");
        safe_input_check(&choice);
        
        if (choice == 1){
            printf("Enter Employee IDs (0x1 to 0x10):\n");
            for (int i = 0; i < 10; i++){
                printf("Employee %d: ", i + 1);
                safe_input_check(&emp[i]);
            }

            printf("\nEnter the top 10 employee ranks (0x1 to 0x10):\n");
            for (int i = 0; i < 10; i++){
                printf("Rank %d: ", i + 1);
                safe_input_check(&rank[i]);
            }
            initialized = 1;

            printf("Employee Number and Rank: \n");
            employee_sort(emp, rank);
      

        } else if (choice == 2){

            if (!initialized) {
                printf("Please sort employees first before replacing.\n");
                continue;
            }

            int old_emp, new_emp;
            printf("Enter the employee ID to replace (0x1 to 0x100): ");
            safe_input_check(&old_emp);
            printf("Enter the new employee ID (0x1 to 0x100): ");
            safe_input_check(&new_emp);
            replace_employee(rank, old_emp, new_emp);
            
        } else if (choice == 3){
            display_history();
        } else if (choice == 4){
            printf("Exiting Employee Manager. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice.\n");
            continue;
        }

        printf("Do you want to continue? (y/n): ");
        safe_input_check_char(&continue_choice);
        if (continue_choice == 'y' || continue_choice == 'Y') {
            loop = 1;
        } else if (continue_choice == 'n' || continue_choice == 'N') {
            loop = 0;
        } else {
            printf("Invalid input. Please enter y or n.\n");
            continue;
        }


    }
    return 0;
}