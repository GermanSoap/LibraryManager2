#ifndef BOOK
#define BOOK
#define maxBook 100
#define szISBN 10
#define szBookName 30
#define szAuthor 25
#define szProducer 25
#define szYearProducing 4 
#define szGenre 20
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

struct Book
{
	char ISBN[szISBN];
	char BookName[szBookName];
	char Author[szAuthor];
	char Producer[szProducer];
	char YearProducing[szYearProducing];
	char Genre[szGenre];
	int Pricing;
	int Amount;
};

// book buffering function declaration
int buffBook(FILE* bookdata, Book &book);
int buffAllBooks(FILE* bookdata, Book bookList[], int &bookcounter);
#endif // !BOOK
