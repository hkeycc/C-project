#include <stdio.h>
#include <stdlib.h>
#include "ordering.h"
#include "data.h"
#include <string.h>


static int compare_by_total(const void* a, const void* b){
    
   
    const struct student *struct_a = *(const struct student **)a;
    const struct student *struct_b = *(const struct student **)b;
    
    if (struct_a->total < struct_b->total) return 1;
    if (struct_a->total > struct_b->total) return -1;
    return 0; 
}

static int compare_by_id(const void* a, const void* b){
    
   
    const struct student *struct_a = *(const struct student **)a;
    const struct student *struct_b = *(const struct student **)b;
    
    if (struct_a->id < struct_b->id) return -1;
    if (struct_a->id > struct_b->id) return 1;
    return 0; 
}

static int compare_by_last(const void* a, const void* b){
    
   
    const struct student *struct_a = *(const struct student **)a;
    const struct student *struct_b = *(const struct student **)b;
    int comp = strcmp(struct_a->lastName, struct_b->lastName);
    if (comp<0) return -1;
    if (comp>0) return 1;
    return 0; 
}

static int compare_by_exam(const void* a, const void* b){
    
   
    const struct student *struct_a = *(const struct student **)a;
    const struct student *struct_b = *(const struct student **)b;
    
    if (struct_a->exam < struct_b->exam) return 1;
    if (struct_a->exam > struct_b->exam) return -1;
    return 0; 
}

void sort_complex_student_array(struct student* *students, int count, int sorting){
    if(sorting==1)
    qsort(students, count, sizeof(struct student *), compare_by_id);
    else if(sorting==2){
        qsort(students, count, sizeof(struct student *), compare_by_last);
    }
    else if(sorting==3){
        qsort(students, count, sizeof(struct student *), compare_by_exam);
    }
    else if(sorting==4){
        qsort(students, count, sizeof(struct student *), compare_by_total);
    }
}

