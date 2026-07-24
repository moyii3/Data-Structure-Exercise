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

Student *SearchStudent(Class *c, int id);

int AddStudent(Class *c, Student s, int position);

int DeleteStudent(Class *c, Student *s);