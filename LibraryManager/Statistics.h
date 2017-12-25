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
int StudentStatisticsENG(); // Calculating and statisting students in library's database
void StatsBasedSex(Student studentList[]);
void StatsBasedSexENG(); // Calculating and statisting students based sex type
void BookRemaining(Book bookList[]);
void BookRemainingENG();  // return total books in db
void BookStatsByGenre(Book bookList[]);
void BookStatsByGenreENG(); // stats by book's genre
void TotalBookInUse(Book bookList[]);
void TotalBookInUseENG(); // stats books in-use, not available for lending
void LateStats(BorrowingCard cardList[]);
void LateStatsENG(); // stats students who are in out of time
void statSaveInstance(FILE *statdata);
void StatFetching(FILE* statdata);
#endif // !STATISTICS_