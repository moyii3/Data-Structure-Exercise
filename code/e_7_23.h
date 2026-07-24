#define MAXSIZE 100
#define ERROR 0
#define OK 1
#define MYOVERFLOW -1

typedef struct{
    int id;
    char name[20];

}Student;

typedef struct{
    Student *students;
    int length;
}Class;

int InitClass(Class *c);

void DestroyClass(Class *c);

int GetLength(Class *c);