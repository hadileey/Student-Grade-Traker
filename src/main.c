#include <stdio.h>
#include "../include/tracker.h"

int main() {
    char names[MAX_STUDENTS][NAME_LEN];
    int marks[MAX_STUDENTS][MAX_SUBJECTS];
    char grades[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    while (1) {
        printf("\n=== Student Grade Checker ===\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Grades\n");
        printf("3. Search Student\n");
        printf("4. Performance Analysis (High/Low)\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord(names, marks, &studentCount);
                break;
            case 2:
                calculateAndDisplayGrades(names, marks, grades, studentCount);
                break;
            case 3:
                searchStudent(names, marks, grades, studentCount);
                break;
            case 4:
                findHighestLowest(names, marks, studentCount);
                break;
            case 5:
                printf("Exiting system.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}