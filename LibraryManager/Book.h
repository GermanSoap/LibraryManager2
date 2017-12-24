#ifndef BOOK
#define BOOK
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "BookComponents.h"
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
 extern Book bookList[maxBook];
// book buffering function declaration
int buffBook(FILE* bookdata, Book &book);
void BookFetching(FILE* bookdata, Book bookList[], int &bookcounter);
void BookListing(Book bookList[]);
void BookListingENG(); // See books
void BookCreating(Book bookList[]);
void BookCreatingENG(); //Create a new book
void BookDeclaration(Book bookList[]);
void BookDeclarationENG();    // Declares the book's default value
void BookEditing(Book bookList[], int number);
void BookEditingENG(int number);         // Edit a books
void BookDeleting(Book bookList[], int number);
void BookDeletingENG(int number);     // Delete a book with its position
void SearchByBookName(Book bookList[], char name[30]);
void SearchByBookNameENG(char name[30]); // Search the book with its name
void SearchByISBN(Book bookList[], char isbn[30]);
void SearchByISBNENG(char isbn[30]); // Search the book with ISBN
void SeeBookChanges(Book bookList[], int number);
void SeeBookChangesENG(int number); // See the changes
void EBSubMenu(int number);
void EBSubMenuENG(int number); //Edit book submenu
void FindByBookName(Book bookList[], char bname[szBookName]);
void FindByISBN(Book bookList[], char isbn[szISBN]);
#endif // !BOOK
