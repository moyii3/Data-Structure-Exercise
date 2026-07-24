#include "lib.h"
#include "whole.h"

int main(){
    Class c;
    
    if(InitClass(&c) == OK){
        for(int i = 0; i < 5; i++){
            c.students[i].id = i + 1;
            sprintf(c.students[i].name, "Student%d", i + 1);
            c.length++;
        }
    }
    printf("Hello, World!\n");
    DestroyClass(&c);
    return 0;
}