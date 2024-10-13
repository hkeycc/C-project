#ifndef DATA_H
#define DATA_H


extern int student_count;

struct student

{
    int id;
    char lastName[70];
    char firstName[70];
    int A1;
    int A2; 
    int A3; 
    int midterm;
    int exam;
    float total;
    char letter;
    
};

struct student* *create_student_arr(int size);
int read_students_from_file(struct student* *students, int max_students);


#endif