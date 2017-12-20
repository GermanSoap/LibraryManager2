#include "Statistics.h"
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
void TotalBookInUse() {
	printf(" ================= THONG KE SACH DANG MUON =================\n");
	printf("   -> Co %d sach dang duoc muon \n", borrowedbook);
	
	_getch();
}
/* Starting LateStats function
Type : void
Input : none
Output : print info about students in late
*/
void LateStats() {
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
			//printf("  -> Hien tai dang muon cac sach : ");
			/*for (int j = 0; j < bookInATime[i]; i++)
			{
			printf("  -> Ma sach : ");
			puts(BorrowingISBN[j]);
			printf("  -> Ten sach : ");
			puts(BookName[j]);
			printf("\n");
			}*/
		}
	}
	printf("   -> Tong cong co %d doc gia dang tre han !\n", late);
	printf("=================================================================");
	_getch();
}