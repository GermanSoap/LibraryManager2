/*
Copyright™ Hieu Hoang Minh. The Library Manager Project.
See source code on https://github.com/hyperion0201/LibraryManager2
Free for personal and commercial use under the MIT license .
2017. Ho Chi Minh University of Science.
*/
#ifndef STUDENT
#define STUDENT
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "Time.h"
#include "StudentComponents.h"
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
 extern Student studentList[maxStudent];
int buffStudent(FILE* studentdata, Student &student);
void StudentFetching(FILE* studentdata, Student studentList[], int &studentcounter);
void StudentEditing(Student studentList[], int number);
void ESSubMenu(int number);
void StudentListing(Student studentList[]);
void StudentCreating(Student studentList[]);
void SeeLocalChanges(Student studentList[], int number);
void DayCreating();
void DayExpired();
void StudentDeclaration(Student studentList[]);
void StudentDeleting(Student studentList[], int number);
void FindByName(Student studentList[], char name[szName]);
void FindByID(Student studentList[], char id[szID]);
void StudentSaving(FILE* studentdata, Student studentList[], int studentcounter);
void StudentEditingENG(Student studentList[], int number);
void ESSubMenuENG(int number);
void StudentCreatingENG(Student studentList[]);
void SeeLocalChangesENG(Student studentList[], int number);
void DayCreatingENG();
void StudentDeclarationENG(Student studentList[]);
void StudentDeletingENG(Student studentList[], int number);
void FindByNameENG(Student studentList[], char name[szName]);
void FindByIDENG(Student studentList[], char id[szID]);
void StudentListingENG(Student studentList[]);

#endif // STUDENT