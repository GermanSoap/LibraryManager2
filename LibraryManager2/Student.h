#ifndef STUDENT
#define STUDENT
#define maxStudent 100
#define szLibID 10
#define szName 25
#define szID 10
#define szBirth 15
#define szSex 6
#define szEmail 25
#define szAddress 30
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

struct Time {
    int day;
    int month;
    int year;
};
struct Student {
    char LibID[szLibID];
    char Name[szName];
    char ID[szID];
    char Birth[szBirth];
    char Sex[szSex];
    char Email[szEmail];
    char Address[szAddress];
    Time timeCreate;
    Time timeExpired;
};
int buffStudent(FILE* studentdata, Student &student);
void buffAllStudents(FILE* studentdata, Student studentList[], int &studentcounter);

#endif // STUDENT