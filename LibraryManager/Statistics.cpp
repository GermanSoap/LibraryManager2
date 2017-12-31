#include "Statistics.h"
/*
Copyright™ Hieu Hoang Minh. The Library Manager Project.
See source code on https://github.com/hyperion0201/LibraryManager2
Free for personal and commercial use under the MIT license .
2017. Ho Chi Minh University of Science.
*/
#include "Card.h"
/* Starting StudentStatistics function
Type : int
Input : none
Output : Return the total students in database
*/
int StudentStatistics() {
	return studentcounter;
}
/* Starting StatsBasedSex function
Type : void
Input : none
Output : Return total students based sex
*/
void StatsBasedSex(Student studentList[]) {
	system("cls");
	int totalmale = 0;
	int totalfemale = 0;
	for (int i = 0; i < studentcounter; i++)
	{
		if (strcmp("Nam", studentList[i].Sex) == 0)  totalmale++;
		else if (strcmp("Nu", studentList[i].Sex) == 0) totalfemale++;
	}
	printf("============== THONG KE DOC GIA THEO GIOI TINH ===============\n");
	printf("\n");
	printf("Co %d doc gia la nam trong thu vien \n", totalmale);
	printf("Co %d doc gia la nu trong thu vien \n", totalfemale);
	_getch();
}
/* Starting BookStatistics fucntion
Type : void
Input : none
Output : return remaining book in db
*/
void BookRemaining(Book bookList[]) {
	printf(" -> Tong so sach nhap ve thu vien la : %d\n\n", totalbook);
	printf(" -> Tong so sach san sang cho muon : %d\n", readybook);
	_getch();
}
/* Starting BookStatsByGenre function
Type : void
Input : none
Output : listing books by genre
*/
void BookStatsByGenre(Book bookList[]) {
	printf("================== THONG KE SACH THEO THE LOAI ==================\n");
	printf("\n");
	int dem;
	for (int i = 0; i < bookcounter; i++)
	{
		dem = 0;
		for (int j = 0; j < bookcounter; j++)
		{
			if (strcmp(bookList[i].Genre, bookList[j].Genre) == 0)
			{
				if (i <= j) dem += bookList[j].Amount;
				else break;
			}
		}
		if (dem != 0) printf(" -> The loai %s co so luong sach la : %d\n", bookList[i].Genre, dem);
	}
	printf("=================================================================\n");
	_getch();
}
/* Starting BookInUse function
Type : void
Input : none
Output : print informations about books which are in-use
*/
void TotalBookInUse(Book bookList[]) {
	printf(" ================= THONG KE SACH DANG MUON =================\n");
	printf("   -> Co %d sach dang duoc muon \n", borrowedbook);
	if (borrowedbook != 0){
		printf("   -> Danh sach : \n");
		for (int i = 0; i < brcard; i++)
		for (int j = 0; j < borrowedbook; j++)
		{
			puts(cardList[i].brList[j].brBookName);
		}
	}
	_getch();
}
/* Starting LateStats function
Type : void
Input : none
Output : print info about students in late
*/
void LateStats(BorrowingCard cardList[]) {
	system("cls");
	printf("================== THONG KE DOC GIA DANG TRE HAN =================\n");
	printf("\n");
	int late = 0;
	for (int i = 0; i < studentcounter; i++)
	{
		if (cardList[i].realReturn.day > cardList[i].esReturn.day || cardList[i].realReturn.month > cardList[i].esReturn.month || cardList[i].realReturn.year > cardList[i].esReturn.year)
		{
			late++;
			printf("  -> Ma doc gia : "); puts(cardList[i].brID);
			printf("  -> Ten doc gia : "); puts(cardList[i].brName);
			for (int j = 0; j < cardList[i].brAmount; j++)
			{
				printf("     -> ISBN : ");
				puts(cardList[i].brList[j].brISBN);
				printf("     -> Book name : ");
				puts(cardList[i].brList[j].brBookName);
			}
		}
	}
	printf("   -> Tong cong co %d doc gia dang tre han !\n", late);
	printf("=================================================================");
	_getch();
}
void statSaveInstance(FILE* statdata){
	fprintf(statdata, "%d %d %d", totalbook, readybook, borrowedbook);
}
void StatFetching(FILE* statdata){
	fscanf(statdata, "%d %d %d", &totalbook, &readybook, &borrowedbook);
}
void StatsBasedSexENG(Student studentList[]) {
	system("cls");
	int totalmale = 0;
	int totalfemale = 0;
	for (int i = 0; i < studentcounter; i++)
	{
		if (strcmp("Male", studentList[i].Sex) == 0)  totalmale++;
		else if (strcmp("Female", studentList[i].Sex) == 0) totalfemale++;
	}
	printf("============== STUDENT STATS BY SEX ===============\n");
	printf("\n");
	printf("There are %d male students in library. \n", totalmale);
	printf("There are %d female students in library. \n", totalfemale);
	_getch();
}
void BookRemainingENG(Book bookList[]) {
	printf(" -> Total book deliveried to library : %d\n\n", totalbook);
	printf(" -> Total book available for borrowing : %d\n", readybook);
	_getch();
}
void BookStatsByGenreENG(Book bookList[]) {
	printf("================== BOOK STATS BY GENRE ==================\n");
	printf("\n");
	int dem;
	for (int i = 0; i < bookcounter; i++)
	{
		dem = 0;
		for (int j = 0; j < bookcounter; j++)
		{
			if (strcmp(bookList[i].Genre, bookList[j].Genre) == 0)
			{
				if (i <= j) dem += bookList[j].Amount;
				else break;
			}
		}
		if (dem != 0) printf(" -> Genre %s has %d books.\n", bookList[i].Genre, dem);
	}
	printf("=================================================================\n");
	_getch();
}
void TotalBookInUseENG(Book bookList[]) {
	printf(" ================= IN-BORROWING STATUS STATS =================\n");
	printf("   -> There are %d book(s) which are being borrowed. \n", borrowedbook);
	if (borrowedbook != 0)
	{
		printf("   -> List : \n");
		for (int i = 0; i < brcard; i++)
		for (int j = 0; j < borrowedbook; j++)
		{
			puts(cardList[i].brList[j].brBookName);
		}
	}
	_getch();
}
void LateStatsENG(BorrowingCard cardList[]) {
	system("cls");
	printf("================== STUDENT IN-LATE STATUS STATS =================\n");
	printf("\n");
	int late = 0;
	for (int i = 0; i < studentcounter; i++)
	{
		if (cardList[i].realReturn.day > cardList[i].esReturn.day || cardList[i].realReturn.month > cardList[i].esReturn.month || cardList[i].realReturn.year > cardList[i].esReturn.year)
		{
			late++;
			printf("  -> Library ID : "); puts(cardList[i].brID);
			printf("  -> Name: "); puts(cardList[i].brName);
			printf("  -> Book borrowed : ");
			for (int j = 0; j < cardList[i].brAmount; j++)
			{
				printf("     -> ISBN : ");
				puts(cardList[i].brList[j].brISBN);
				printf("     -> Book name : ");
				puts(cardList[i].brList[j].brBookName);
			}
		}
	}
	printf("   -> Total students in-late : %d !\n", late);
	printf("=================================================================");
	_getch();
}
