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
struct BorrowingCard
{
	char brID[szID];
	char brName[szName];
	int brAmount;
	Time timeBorrow;
	Time esReturn;
	Time realReturn;
};
extern BorrowingCard card[maxCard];

struct CardDetail
{
	char brISBN[szISBN];
	char brBookName[szBookName];
	bool returned;
};
extern CardDetail cardList[maxCard];
int PenaltyFee(Time es, Time realReturn);
#endif // !CARD
