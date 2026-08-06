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
        printf("3. 双链表\n");
        printf("0. 退出\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                List_menu();
                break;
            case 2:
                LinkList_menu();
                break;
            case 3:
                DuList_menu();
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
        printf("7. 通过位置查找节点\n");
        printf("8. 通过值查找节点\n");
        printf("9. 插入节点\n");
        printf("10. 删除节点\n");
        printf("11. 加入测试节点\n");
        printf("12. 头插法建立链表\n");
        printf("13. 尾插法建立链表\n");
        printf("14. 反转链表\n");
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
                printf("输入要查找的节点位置: ");
                int pos;
                scanf("%d", &pos);
                LinkList nodeByPos = searchListByLocation(L, pos);
                if(nodeByPos != NULL && nodeByPos != L){
                    printf("找到节点: %d\n", nodeByPos->data);
                } else {
                    printf("未找到节点!\n");
                }
                PressAnyKey();
                break;
            case 8:
                printf("输入要查找的节点值: ");
                int value;
                scanf("%d", &value);
                LinkList nodeByValue = searchListByValue(L, value);
                if(nodeByValue != NULL){
                    printf("找到节点: %d\n", nodeByValue->data);
                } else {
                    printf("未找到节点!\n");
                }
                PressAnyKey();
                break;
            case 9:
                printf("输入要插入的节点位置和值: ");
                int insertPos, insertValue;
                scanf("%d %d", &insertPos, &insertValue);
                if(insertList(L, insertPos, insertValue) == OK){
                    printf("节点插入成功!\n");
                } else {
                    printf("节点插入失败!\n");
                }
                PressAnyKey();
                break;
            case 10:
                printf("输入要删除的节点位置: ");
                int deletePos;
                scanf("%d", &deletePos);
                if(deleteList(L, deletePos) == OK){
                    printf("节点删除成功!\n");
                } else {
                    printf("节点删除失败!\n");
                }
                PressAnyKey();
                break;
            case 11:
                Test(L);
                printf("测试节点已加入!\n");
                PressAnyKey();
                break;
            case 12:
                createListHead(&L,5);
                break;
            case 13:
                createListR(&L,5);
                break;
            case 14:
                L->next = reverseList(L->next);
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

int DuList_menu(){
    int choice;
    duLinkList D1;
    duLinkList D2;
    do{
        system("cls");
        printf("1.建立双向链表\n");
        printf("2.显示双向链表\n");
        printf("3.双链表节点查找\n");
        printf("4.双链表节点插入\n");
        printf("5.双链表节点删除\n");
        printf("6.两个非递减双链表合并\n");
        printf("7.倒序输出双链表\n");
        printf("8.迭代合并两个非递减双链表\n");
        printf("0.退出\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                CreateDuList(&D1, 5);
                if(D1) printf("创建成功！\n");
                else printf("创建失败\n");
                PressAnyKey();
                break;
            case 2:
                ShowDuList(D1);
                PressAnyKey();
                break;
            case 3:
                printf("请输入节点位置：");
                int position;
                scanf("%d", &position);
                duLinkList p = searchDuListByLocation(D1, position);
                if(!p || p == D1) printf("未找到节点！\n");
                else printf("找到节点%d,数据为：%d", position, p->data);
                PressAnyKey();
                break;
            case 4:
                printf("请输入插入节点位置及数据：");
                int insert_pos,value;
                scanf("%d %d", &insert_pos, &value);
                if(insertDuListNode(D1, insert_pos, value) == OK) printf("节点插入成功！\n");
                else printf("失败！\n");
                PressAnyKey();
                break;
            case 5:
                printf("请输入删除节点位置：");
                int delete_pos;
                scanf("%d", &delete_pos);
                if(deleteDulistNode(D1, delete_pos) == OK) printf("节点删除成功！\n");
                else printf("失败！\n");
                PressAnyKey();
                break;
            case 6:
                printf("1.短链表\n2.长链表\n");
                int choice2;
                scanf("%d", &choice2);
                if(choice2 == 1){
                printf("第一链表\n");
                CreateDuList(&D1, 5);
                if(D1) printf("创建成功\n");
                else printf("失败\n");
                printf("创建第二链表\n");
                CreateDuList(&D2, 6);
                if(D2) printf("创建成功！\n");
                else printf("创建失败\n");
                /*D1->next = sortDuList(D1->next);
                D1->next->prior = D1;
                D2->next = sortDuList(D2->next);
                D2->next->prior = D2;*/
                D1->next = unionDuList(D1->next, D2->next);
                printf("合并成功\n");
                ShowDuList(D1);
                }else{
                    D1 = CreateLongDuList(D1);
                    D2 = CreateLongDuList(D2);
                    D1->next = unionDuList(D1->next, D2->next);
                    printf("合并完成\n");
                    ShowDuList(D1);
                }
                
                PressAnyKey();
                break;
            case 7:
                ShowReverseDuList(D1);
                PressAnyKey();
                break;
            case 8:
                printf("1.短链表\n2.长链表\n");
                int choice3;
                scanf("%d", &choice3);
                if(choice3 == 1){
                printf("第一链表\n");
                CreateDuList(&D1, 5);
                if(D1) printf("创建成功\n");
                else printf("失败\n");
                printf("创建第二链表\n");
                CreateDuList(&D2, 6);
                if(D2) printf("创建成功！\n");
                else printf("创建失败\n");
                D1->next = MergeDuList(D1->next, D2->next);
                printf("合并成功\n");
                ShowDuList(D1);
                }else{
                    D1 = CreateLongDuList(D1);
                    D2 = CreateLongDuList(D2);
                    D1->next = MergeDuList(D1->next, D2->next);
                    printf("合并完成\n");
                    ShowDuList(D1);
                }
                
                PressAnyKey();
                break;
            case 0:
                break;
            default:
                printf("选择错误，请重新选择\n");
                PressAnyKey();
        }
    }while(choice != 0);
    return OK;
}