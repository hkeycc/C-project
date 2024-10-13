#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "ordering.h"
#include "calc.h"
int student_count = 0;

#define ROW_LENGTH 256 

struct student* *create_student_arr(int size){

    struct student* *studentArr = malloc(size*sizeof(struct student*));
    for(int i=0; i<size; i++){
        studentArr[i] = malloc(size*sizeof(struct student));
    }
    return studentArr;
}

int read_students_from_file(struct student* *students, int max_students) {
    FILE *file_ptr = fopen("students.txt", "r");
    if (file_ptr == NULL) {
        perror("Error opening file");
        return 0;
    }

    char row_buffer[ROW_LENGTH];
    int count = 0;

    while (fgets(row_buffer, sizeof(row_buffer), file_ptr) != NULL) {
        
        row_buffer[strcspn(row_buffer, "\n")] = '\0';

        
        if (sscanf(row_buffer, "%d|%[^|]|%[^|]|%d|%d|%d|%d|%d",
                   &students[count]->id,
                   students[count]->lastName,
                   students[count]->firstName,
                   &students[count]->A1,
                   &students[count]->A2,
                   &students[count]->A3,
                   &students[count]->midterm,
                   &students[count]->exam) == 8) { 
            
            

            count++; 
        }
    }

    fclose(file_ptr);
    
    student_count = count;
    return count; 
}
