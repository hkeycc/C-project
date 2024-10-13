#ifndef CALC_H
#define CALC_H
extern int baseline_A;
extern int baseline_B;
extern int baseline_C;
extern int baseline_D;
#include "data.h"

void bellCurve(struct student* *students);
void updateLastName(struct student* *students, int ID, char* lastName);
void calcGrade(struct student* *students);
void updateGrade(struct student* *students, int ID, int examGrade);
void remove_student(struct student* *students, int ID);
#endif
