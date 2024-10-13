#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "ordering.h"
#include <string.h>


int baseline_A = 80;
int baseline_B = 70;
int baseline_C = 60;
int baseline_D = 50;
void calcGrade(struct student* *students){
    for(int i=0;i<student_count;i++){
        students[i]->total = (students[i]->A1*0.625/3 + 
        students[i]->A2*0.625/3 + 
        students[i]->A3*0.625/3 + 
        students[i]->midterm + 
        students[i]->exam*1.25);

            
            if (students[i]->total >= baseline_A) {
                students[i]->letter = 'A';
            } else if (students[i]->total >= baseline_B) {
                students[i]->letter = 'B';
            } else if (students[i]->total >= baseline_C) {
                students[i]->letter = 'C';
            } else if (students[i]->total >= baseline_D) {
                students[i]->letter = 'D';
            } else {
                students[i]->letter = 'F';
            }
}}

void updateGrade(struct student* *students, int ID, int examGrade){
    for(int i=0;i<student_count;i++){
        if(students[i]->id==ID){
            students[i]->exam=examGrade;
        }
    }
}








void bellCurve(struct student* *students){
    calcGrade(students);
    printf("A: ");
    for(int i=0;i<student_count;i++){
        if(students[i]->letter=='A'){
            printf("%s","*");
        }
    }
    printf("\nB: ");
    for(int i=0;i<student_count;i++){
        if(students[i]->letter=='B'){
            printf("%s","*");
        }
    }
    printf("\nC: ");
    for(int i=0;i<student_count;i++){
        if(students[i]->letter=='C'){
            printf("%s","*");
        }
    }
    printf("\nD: ");
    for(int i=0;i<student_count;i++){
        if(students[i]->letter=='D'){
            printf("%s","*");
        }
    }
    printf("\nF: ");
    for(int i=0;i<student_count;i++){
        if(students[i]->letter=='F'){
            printf("%s","*");
        }
    }
}

void updateLastName(struct student* *students, int ID, char* lastName){
    for(int i=0;i<student_count;i++){
        if(students[i]->id==ID){
            strcpy(students[i]->lastName, lastName);
           
        }
    }
}


void remove_student(struct student* *students, int ID) {
    
    for (int i = 0; i < student_count; i++) {
        if (students[i]->id == ID) {
            free(students[i]);
            for (int j = i; j < student_count - 1; j++) {
                students[j] = students[j + 1];
            }
            students[student_count - 1] = NULL;
            student_count--;

            return; 
        }
    }}