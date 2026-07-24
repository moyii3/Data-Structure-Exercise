#include "whole.h"
//顺序表
int InitClass(Class *c){
    c->students = (Student *)malloc(MAXSIZE * sizeof(Student));
    if(!c->students){
        return MYOVERFLOW;
    }
    c->length = 0;
    return OK;
}

void DestroyClass(Class *c){
    free(c->students);
    c->students = NULL;
    c->length = 0;
}

int GetLength(Class *c){
    return c->length;
}

//查找
Student *SearchStudent(Class *c, int id){
    for(int i = 0; i < c->length; i++){
        if(((c->students)+i)->id == id){
            return (c->students)+i;
        }
    }
    return NULL;
}

//插入
int AddStudent(Class *c, Student s, int position){
    if(c->length == MAXSIZE || position < 0 || position > c->length + 1){
        return ERROR;
    }
    for(int i = c->length; i >= position; i--){
        *((c->students) + i) = *((c->students) + i - 1);
    }
    *((c->students) + position - 1) = s;
    c->length++;
    return OK;
    
}

//删除
int DeleteStudent(Class *c, Student *s){
    if(s == NULL){
        return ERROR;
    }
    for(int i = s - c->students; i < c->length - 1; i++){
        *((c->students) + i) = *((c->students) + i + 1);
    }
    c->length--;
    return OK;
}