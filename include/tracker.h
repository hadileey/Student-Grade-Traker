#ifndef TRACKER_H
#define TRACKER_H

#define MAX_STUDENTS 100
#define MAX_SUBJECTS 5
#define NAME_LEN 50

void addRecord(char names[][NAME_LEN], int marks[][MAX_SUBJECTS], int *count);
void calculateAndDisplayGrades(char names[][NAME_LEN], int marks[][MAX_SUBJECTS], char grades[], int count);
void searchStudent(char names[][NAME_LEN], int marks[][MAX_SUBJECTS], char grades[], int count);
void findHighestLowest(char names[][NAME_LEN], int marks[][MAX_SUBJECTS], int count);

#endif