#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "calc.h"
#include "ordering.h"

int sortedByGrade = 0;


void display_spreadsheet(struct student* *students, int count);

void displayOptions() {
    system("clear");
    printf("Spreadsheet Menu\n");
    printf("----------------\n");
    printf("1. Display Spreadsheet\n");
    printf("2. Display Histogram\n");
    printf("3. Set sort column\n");
    printf("4. Update Last Name\n");
    printf("5. Update Exam Grade\n");
    printf("6. Update Grade Mapping\n");
    printf("7. Delete Student\n");
    printf("8. Exit\n");
    printf("\n");
}

int main() {
    int userInput;
   
    
    int size = 10; 
    struct student** students = create_student_arr(size);

    if (students == NULL) {
        return EXIT_FAILURE; 
    }
    
    calcGrade(students);
    int student_count = read_students_from_file(students, size);
    sort_complex_student_array(students, student_count, 1);
   do{
    displayOptions();
    printf("Selection: ");
    scanf("%d", &userInput);
    switch (userInput) {
        case 1:{
             
             display_spreadsheet(students, student_count);
             char proceed;
            printf("\nPress 'c' or 'C' to continue ");
            do{
            scanf("%c", &proceed);
            } while ( (proceed != 'c') && (proceed != 'C'));

        }
            
            break;
        case 2:{
            printf("COMP 348 Grade Distribution\n\n");
            bellCurve(students);
            char proceed;
            printf("\n\nPress 'c' or 'C' to continue ");
            do{
            scanf(" %c", &proceed);
            } while ( (proceed != 'c') && (proceed != 'C'));

        }
            break;
        case 3:{
            int sortColumn;
            printf("Column Options\n");
            printf("---------------\n");
            printf("1. Student ID\n");
            printf("2. Last name\n");
            printf("3. Exam\n");
            printf("4. Total\n\n");
            printf("Sort Column: ");
            scanf("%d", &sortColumn);
            printf("\nSort column updated\n");
            calcGrade(students);
            if(sortColumn==1){
                sort_complex_student_array(students, student_count, 1);
            }
            else if(sortColumn==2){
                sort_complex_student_array(students, student_count, 2);
            }
           else if(sortColumn==3){
                sort_complex_student_array(students, student_count, 3);
                sortedByGrade=1;
            }
            else if(sortColumn==4){
                sort_complex_student_array(students, student_count, 4);
                sortedByGrade=2;
               
            }
            char proceed;
            printf("\nPress 'c' or 'C' to continue ");
            do{
            scanf("%c", &proceed);
            } while ( (proceed != 'c') && (proceed != 'C'));

            }
            break;
        case 4:{
            
            display_spreadsheet(students, student_count);
            char userLastName[30];
            int userID;
             printf("\nEnter student ID: ");
             scanf("%d", &userID);
            printf("\nEnter updated Last Name: ");
            scanf("%s", userLastName);
            updateLastName(students, userID, userLastName);
            printf("\nLast name updated");
            char proceed;
            printf("\n\nPress 'c' or 'C' to continue ");
            do{
            scanf("%c", &proceed);
            } while ( (proceed != 'c') && (proceed != 'C'));

            
        }
            
            break;
        case 5:{
            int userID;
            int examGrade=-1;
            display_spreadsheet(students, student_count);
             printf("\nEnter student ID: ");
             scanf("%d", &userID);
             while(examGrade<0||examGrade>40){
             printf("\nEnter updated exam grade : ");
             scanf("%d", &examGrade);
            }
            updateGrade(students, userID, examGrade);
            
            printf("\n\nExam grade updated\n");
            calcGrade(students);
            if(sortedByGrade==1){
                sort_complex_student_array(students, student_count, 3);
            }
            else if(sortedByGrade==2){
                sort_complex_student_array(students, student_count, 4);
            }
            
            char proceed;
            printf("\nPress 'c' or 'C' to continue ");
            do{
            scanf("%c", &proceed);
            } while ( (proceed != 'c') && (proceed != 'C'));

            }
            break;
        case 6:{
            printf("Current Mapping:\n");
            printf("A: >= %d\n", baseline_A);
            printf("B: >= %d\n", baseline_B);
            printf("C: >= %d\n", baseline_C);
            printf("D: >= %d\n", baseline_D);
            printf("F: < %d\n\n", baseline_D);
            printf("Enter new A baseline: ");
            scanf("%d", &baseline_A);
            printf("\nEnter new B baseline: ");
            scanf("%d", &baseline_B);
            printf("\nEnter new C baseline: ");
            scanf("%d", &baseline_C);
            printf("\nEnter new D baseline: ");
            scanf("%d", &baseline_D);

            printf("\n\nNew Mapping:\n");
            printf("A: >= %d\n", baseline_A);
            printf("B: >= %d\n", baseline_B);
            printf("C: >= %d\n", baseline_C);
            printf("D: >= %d\n", baseline_D);
            printf("F: < %d\n\n", baseline_D);
            char proceed;
            printf("\nPress 'c' or 'C' to continue ");
            do{
scanf("%c", &proceed);
            } while ( (proceed != 'c') && (proceed != 'C'));

        }
            break;
        case 7:{
            int ID;
            display_spreadsheet(students, student_count);
            printf("\nEnter Student ID: ");
            scanf("%d", &ID);
            remove_student(students, ID);
            printf("Student successfully deleted\n");
            

            char proceed;
            printf("\nPress 'c' or 'C' to continue ");
            do{
            scanf("%c", &proceed);
            } while ( (proceed != 'c') && (proceed != 'C'));

            }
            break;
        case 8:
            
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid selection. Please try again.\n");
            break;
    }}while(userInput!=8);
    
    
    
   
    for (int i = 0; i < student_count; i++) {
    free(students[i]);
    }
    free(students);

    
   
    return 0;
}

void display_spreadsheet(struct student* *students, int count) {
    system("clear");
    printf("COMP 348 GRADE SHEET\n\n");
    calcGrade(students);
    printf("%-10s %-15s %-15s %-5s %-5s %-5s %-8s %-5s %-12s %-12s\n", 
           "ID", "Last", "First", "A1", "A2", "A3", "Midterm", "Exam", "Total", "Letter");
    printf("%-10s %-15s %-15s %-5s %-5s %-5s %-8s %-5s %-12s %-12s\n", 
           "--", "----", "----", "--", "--", "--", "-------", "----", "-----", "-----");

    for (int i = 0; i < count; i++) {
        if(students[i]!= NULL)
        printf("%-10d %-15s %-15s %-5d %-5d %-5d %-8d %-5d %-12.2f %-12c\n",
            students[i]->id,
            students[i]->lastName,
            students[i]->firstName,
            students[i]->A1,
            students[i]->A2,
            students[i]->A3,
            students[i]->midterm,
            students[i]->exam,
            students[i]->total,
            students[i]->letter);
    }
}
