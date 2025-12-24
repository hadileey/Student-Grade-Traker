#include <stdio.h>
#include <string.h>
#include "../include/tracker.h"

char determineGrade(float average) {
    if (average >= 90) return 'A';
    else if (average >= 80) return 'B';
    else if (average >= 70) return 'C';
    else if (average >= 60) return 'D';
    else return 'F';
}

void addRecord(char names[][NAME_LEN], int marks[][MAX_SUBJECTS], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Database full.\n");
        return;
    }

    printf("Enter Student Name: ");
    scanf("%s", names[*count]);

    printf("Enter marks for %d subjects:\n", MAX_SUBJECTS);
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%d", &marks[*count][i]);
    }

    (*count)++;
    printf("Record added successfully.\n");
}

void calculateAndDisplayGrades(char names[][NAME_LEN], int marks[][MAX_SUBJECTS], char grades[], int count) {
    if (count == 0) {
        printf("No records found.\n");
        return;
    }

    printf("\n%-15s %-10s %-10s\n", "Name", "Total", "Grade");
    printf("--------------------------------------\n");

    for (int i = 0; i < count; i++) {
        int total = 0;
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            total += marks[i][j];
        }
        float avg = (float)total / MAX_SUBJECTS;
        grades[i] = determineGrade(avg);

        printf("%-15s %-10d %-10c\n", names[i], total, grades[i]);
    }
}

void searchStudent(char names[][NAME_LEN], int marks[][MAX_SUBJECTS], char grades[], int count) {
    char searchName[NAME_LEN];
    int found = 0;

    printf("Enter name to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < count; i++) {
        if (strcmp(names[i], searchName) == 0) {
            int total = 0;
            for (int j = 0; j < MAX_SUBJECTS; j++) {
                total += marks[i][j];
            }
            float avg = (float)total / MAX_SUBJECTS;
            grades[i] = determineGrade(avg);

            printf("\nStudent Found!\n");
            printf("Name: %s\n", names[i]);
            printf("Total Marks: %d\n", total);
            printf("Average: %.2f\n", avg);
            printf("Grade: %c\n", grades[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }
}

void findHighestLowest(char names[][NAME_LEN], int marks[][MAX_SUBJECTS], int count) {
    if (count == 0) {
        printf("No records to analyze.\n");
        return;
    }

    int highestTotal = -1, lowestTotal = 10000;
    int highIndex = -1, lowIndex = -1;

    for (int i = 0; i < count; i++) {
        int total = 0;
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            total += marks[i][j];
        }

        if (total > highestTotal) {
            highestTotal = total;
            highIndex = i;
        }
        if (total < lowestTotal) {
            lowestTotal = total;
            lowIndex = i;
        }
    }

    printf("\nPerformance Analysis:\n");
    printf("Highest Score: %s (Total: %d)\n", names[highIndex], highestTotal);
    printf("Lowest Score:  %s (Total: %d)\n", names[lowIndex], lowestTotal);
}