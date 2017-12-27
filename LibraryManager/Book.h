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
void BookListingENG(Book bookList[]); // See books
void BookCreating(Book bookList[]);
void BookCreatingENG(Book bookList[]); //Create a new book
void BookDeclaration(Book bookList[]);
void BookDeclarationENG(Book bookList[]);    // Declares the book's default value
void BookEditing(Book bookList[], int number);
void BookEditingENG(Book bookList[], int number);         // Edit a books
void BookDeleting(Book bookList[], int number);
void BookDeletingENG(Book bookList[], int number);     // Delete a book with its position
void SeeBookChanges(Book bookList[], int number);
void SeeBookChangesENG(Book bookList[], int number); // See the changes
void EBSubMenu(int number);
void EBSubMenuENG(int number); //Edit book submenu
void FindByBookName(Book bookList[], char bname[szBookName]);
void FindByBookNameENG(Book bookList[], char bname[szBookName]);
void FindByISBN(Book bookList[], char isbn[szISBN]);
void FindByISBNENG(Book bookList[], char isbn[szISBN]);
void bookSaveInstance(FILE* bookdata, Book bookList[], int bookcounter);
void bookSaveInstanceENG(FILE* bookdata, Book bookList[], int bookcounter);
#endif // !BOOK
