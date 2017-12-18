#include "Book.h"
#include "CoreFunction.h"
#include "Student.h"
#include "BookComponents.h"
#include "StudentComponents.h"

void main() {
	Student studentList[maxStudent];
	Book bookList[maxBook];
	FILE* studentdata = fopen("Student.txt", "rt");
	buffAllStudents(studentdata, studentList, studentcounter);
	FILE* bookdata = fopen("Book.txt", "rt");
	buffAllBooks(bookdata, bookList, bookcounter);
	//Book bookList[maxBook];
	
//	StudentDeclaration();
	//FILE* studentdata = fopen("Student.txt", "wt");
	//FileTransfer(studentdata);
	StudentListing(studentList);
	BookListing(bookList);
		_getch();
	
	
}