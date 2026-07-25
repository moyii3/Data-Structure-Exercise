#include "whole.h"

void PressAnyKey(){
    printf("按任意键继续...\n");
    getchar();
    getchar();
}

int Main_menu(){
    int choice;
    do{
        system("cls");
        printf("1. 顺序表操作\n");
        printf("2. 链表操作\n");
        printf("0. 退出\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                List_menu();
                break;
            case 2:
                LinkList_menu();
                break;
            case 0:
                break;
            default:
                printf("无效选择!\n");
                PressAnyKey();
        }
        
    }while(choice != 0);

    return 0;
}

int List_menu(){
    int choice;
    Class c;
    do{
        system("cls");
        printf("1. 班级初始化\n");
        printf("2. 销毁班级\n");
        printf("3. 班级人数\n");
        printf("4. ID查找学生\n");
        printf("5. 添加学生\n");
        printf("6. 删除学生\n");
        printf("0. 退出\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:

                if(InitClass(&c) == OK){
                    for(int i = 0; i < 5; i++){
                        c.students[i].id = i + 1;
                        sprintf(c.students[i].name, "Student%d", i + 1);
                        c.length++;
                    }
                    printf("班级初始化成功!\n");
                    PressAnyKey();
                }else{
                    printf("班级初始化失败!\n");
                    PressAnyKey();
                }
                break;
            case 2:
                DestroyClass(&c);
                printf("班级销毁成功!\n");
                PressAnyKey();
                break;
            case 3:
                printf("班级人数: %d\n", GetLength(&c));
                PressAnyKey();
                break;
            case 4:
                printf("输入要查找的学生ID: ");
                int id;
                scanf("%d", &id);
                Student *s = SearchStudent(&c, id);
                if(s != NULL){
                    printf("找到学生: ID=%d, Name=%s\n", s->id, s->name);
                    PressAnyKey();
                } else {
                    printf("未找到学生!\n");
                    PressAnyKey();
                }       
                break;
            case 5:
                printf("输入学生ID和姓名以添加: ");
                Student newStudent;
                scanf("%d %s", &newStudent.id, newStudent.name);
                printf("输入插入位置: ");
                int position;
                scanf("%d", &position);
                AddStudent(&c, newStudent, position);
                PressAnyKey();
                break;
            case 6:
                printf("输入要删除的学生ID: ");
                int deleteId;
                scanf("%d", &deleteId);
                Student* deleteStudent = SearchStudent(&c, deleteId);
                if(deleteStudent != NULL){
                    DeleteStudent(&c, deleteStudent);
                    printf("学生删除成功!\n");
                    PressAnyKey();
                } else {
                    printf("未找到学生!\n");
                    PressAnyKey();
                }
                break;
            case 0:
                break;
            default:
                printf("无效选择!\n");
                PressAnyKey();
        }
        
    }while(choice != 0);

    return 0;
}

int LinkList_menu(){
    int choice;
    LinkList L;
    do{
        system("cls");
        printf("1. 初始化链表\n");
        printf("2. 销毁链表\n");
        printf("3. 清空链表\n");
        printf("4. 获取链表长度\n");
        printf("5. 检查链表是否为空\n");
        printf("6. 显示链表\n");
        printf("7. 测试链表功能\n");
        printf("0. 退出\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                if(InitList(&L) == OK){
                    printf("链表初始化成功!\n");
                } else {
                    printf("链表初始化失败!\n");
                }
                PressAnyKey();
                break;
            case 2:
                DestroyList(&L);
                printf("链表销毁成功!\n");
                PressAnyKey();
                break;
            case 3:
                if(ClearList(L) == OK){
                    printf("链表清空成功!\n");
                } else {
                    printf("链表清空失败!\n");
                }
                PressAnyKey();
                break;
            case 4:
                printf("链表长度: %d\n", ListLength(L));
                PressAnyKey();
                break;
            case 5:
                if(IsEmpty(L)){
                    printf("链表为空.\n");
                } else {
                    printf("链表不为空.\n");
                }
                PressAnyKey();
                break;
            case 6:
                printf("链表内容: ");
                ShowList(L);
                PressAnyKey();
                break;
            case 7:
                Test(L);
                PressAnyKey();
                break;
            case 0:
                break;
            default:
                printf("无效选择!\n");
                PressAnyKey();
        }
        
    }while(choice != 0);

    return 0;
}