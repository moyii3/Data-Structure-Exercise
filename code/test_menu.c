#include "whole.h"

int menu(){
    int choice;
    Class c;
    do{
        printf("1. Initialize Class\n");
        printf("2. Destroy Class\n");
        printf("3. Get Length of Class\n");
        printf("4. Search Student by ID\n");
        printf("5. Add Student\n");
        printf("6. Delete Student\n");
        printf("0. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:

                if(InitClass(&c) == OK){
                    for(int i = 0; i < 5; i++){
                        c.students[i].id = i + 1;
                        sprintf(c.students[i].name, "Student%d", i + 1);
                        c.length++;
                    }
                    printf("Class initialized successfully!\n");
                }else{
                    printf("Failed to initialize class!\n");
                }
                break;
            case 2:
                DestroyClass(&c);
                printf("Class destroyed successfully!\n");
                break;
            case 3:
                printf("Length of class: %d\n", GetLength(&c));
                break;
            case 4:
                printf("Enter student ID to search: ");
                int id;
                scanf("%d", &id);
                Student *s = SearchStudent(&c, id);
                if(s != NULL){
                    printf("Student found: ID=%d, Name=%s\n", s->id, s->name);
                } else {
                    printf("Student not found!\n");
                }       
                break;
            case 5:
                printf("Enter student ID and name to add: ");
                Student newStudent;
                scanf("%d %s", &newStudent.id, newStudent.name);
                printf("Enter position to insert: ");
                int position;
                scanf("%d", &position);
                AddStudent(&c, newStudent, position);
                break;
            case 6:
                printf("Enter student ID to delete: ");
                int deleteId;
                scanf("%d", &deleteId);
                Student* deleteStudent = SearchStudent(&c, deleteId);
                if(deleteStudent != NULL){
                    DeleteStudent(&c, deleteStudent);
                    printf("Student deleted successfully!\n");
                } else {
                    printf("Student not found!\n");
                }
                break;
            case 0:
                break;
            default:
                printf("Invalid choice!\n");
        }
        system("cls");
    }while(choice != 0);

    return 0;
}
