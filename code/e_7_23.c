#include "lib.h"
#include "e_7_23.h"

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