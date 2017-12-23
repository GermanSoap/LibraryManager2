#ifndef CARD
#define CARD
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>
#include <stdbool.h>
#define maxCard 100
#include "Time.h"
#include "BookComponents.h"
#include "StudentComponents.h"
#include "Book.h"
extern int brcard;
struct CardDetail
{
	char brISBN[szISBN];
	char brBookName[szBookName];
	bool returned;
};
struct BorrowingCard
{
	char brID[szID];
	char brName[szName];
	int brAmount;
	Time timeBorrow;
	Time esReturn;
	Time realReturn;
	CardDetail brList[10];
};
extern BorrowingCard cardList[maxCard];

int PenaltyFee(Time es, Time realReturn);
void BorrowingInput(BorrowingCard cardList[], Book bookList[]);
Time EstimatedTime(Time timeBorrow);
void getBorrowingList(BorrowingCard cardList[]);
void ReturningInput(BorrowingCard cardList[]);
void getReturningList(BorrowingCard cardList[]);
void CardMenu();
#endif // !CARD
