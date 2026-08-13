#include "whole.h"
//顺序表
/*输入班级地址，为其学生顺序表申请空间，输出申请状态*/
int InitClass(Class *c){
    c->students = (Student *)malloc(MAXSIZE * sizeof(Student));
    if(!c->students){
        return MYOVERFLOW;
    }
    c->length = 0;
    return OK;
}

/*输入班级地址，释放学生顺序表空间并置空，将长度设为零，无输出*/
void DestroyClass(Class *c){
    free(c->students);
    c->students = NULL;
    c->length = 0;
}

/*输入班级地址，输出学生数*/
int GetLength(Class *c){
    return c->length;
}

//查找
/*输入班级地址以及查找学生ID，输出该学生存储地址否则输出空，核心：依次遍历顺序表，输出ID符合的学生*/
Student *SearchStudent(Class *c, int id){
    for(int i = 0; i < c->length; i++){
        if(((c->students)+i)->id == id){
            return (c->students)+i;
        }
    }
    return NULL;
}

//插入
/*输入班级地址，学生数据以及插入位置，输出插入状态。核心：从顺序表末尾依次将每个元素后移一位，一直到将插入位置空出来，将新数据插入*/
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
/*输入班级存储地址以及学生存储地址，输出删除状态。核心：从删除位置开始依次将后一个元素前移一位*/
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

//显示所有学生
/*输入班级指针，无输出。核心：依次遍历顺序表并调用打印函数打印学生信息*/
void ShowAllStudents(Class *c){
    for(int i = 0; i < c->length; i++){
        ShowStudent((c->students) + i);
    }
}

//显示单个学生信息
void ShowStudent(Student *s){
    printf("ID: %d, 名字: %s\n", s->id, s->name);
}