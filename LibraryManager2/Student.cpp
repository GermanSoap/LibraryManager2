#include "CoreFunction.h"
#include "Student.h"
int buffStudent(FILE* studentdata, Student &student){
    int d, m, y;

    LineBuffering(studentdata, student.LibID, szLibID);
    LineBuffering(studentdata, student.Name, szName);
    LineBuffering(studentdata, student.ID, szID);
    LineBuffering(studentdata, student.Birth, szBirth);
    LineBuffering(studentdata, student.Sex, szSex);
    LineBuffering(studentdata, student.Email, szEmail);
    LineBuffering(studentdata, student.Address, szAddress);
    fscanf(studentdata, "%d %d %d", &d, &m, &y);
    fgetc(studentdata);
	// buffering timeCreate
	student.timeCreate.day = d;
	student.timeCreate.month = m;
	student.timeCreate.year = y;
	// automatically caculating expired time
	student.timeExpired.day = d;
	student.timeExpired.month = m;
	student.timeExpired.year = y + 4;
    return 1;
}
void buffAllStudents(FILE* studentdata, Student studentList[], int &studentcounter){
    Student student; 
	studentcounter = 0;
    while (!feof(studentdata))
    {
		if (studentcounter < maxStudent && buffStudent(studentdata, student))
		{
			studentList[studentcounter] = student;
			studentcounter++;
		}
		else break;
    }
}