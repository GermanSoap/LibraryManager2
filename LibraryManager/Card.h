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
extern int rtcard;
struct CardDetail
{
	char brISBN[szISBN];
	char brBookName[szBookName];
	int returned;
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

int PenaltyFee(BorrowingCard cardList[], Time esReturn, Time realReturn);
void BorrowingInput(BorrowingCard cardList[], Book bookList[]);
Time EstimatedTime(Time timeBorrow);
void getBorrowingList(BorrowingCard cardList[]);
void ReturningInput(BorrowingCard cardList[]);
void getReturningList(BorrowingCard cardList[]);
void CardMenu();
int buffCard(FILE* carddata, BorrowingCard &card);
void CardFetching(FILE* carddata, BorrowingCard cardList[], int &brcard);
void cardSaveInstance(FILE* carddata, BorrowingCard cardList[], int brcard);
int PenaltyFeeENG(BorrowingCard cardList[], Time esReturn, Time realReturn);
void BorrowingInputENG(BorrowingCard cardList[], Book bookList[]);

#endif // !CARD
