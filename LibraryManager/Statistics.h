/*
Copyright™ Hieu Hoang Minh. The Library Manager Project.
See source code on https://github.com/hyperion0201/LibraryManager2
Free for personal and commercial use under the MIT license .
2017. Ho Chi Minh University of Science.
*/
#ifndef STATISTICS_
#define STATISTICS_
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>
#include "Book.h"
#include "Student.h"
#include "Card.h"
int StudentStatistics();
 // Calculating and statisting students in library's database
void StatsBasedSex(Student studentList[]);
void StatsBasedSexENG(Student studentList[]); // Calculating and statisting students based sex type
void BookRemaining(Book bookList[]);
void BookRemainingENG(Book bookList[]);  // return total books in db
void BookStatsByGenre(Book bookList[]);
void BookStatsByGenreENG(Book bookList[]); // stats by book's genre
void TotalBookInUse(Book bookList[]);
void TotalBookInUseENG(Book bookList[]); // stats books in-use, not available for lending
void LateStats(BorrowingCard cardList[]);
void LateStatsENG(BorrowingCard cardList[]); // stats students who are in out of time
void statSaveInstance(FILE *statdata);
void StatFetching(FILE* statdata);
#endif // !STATISTICS_