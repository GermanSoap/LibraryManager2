#include "Book.h"
#include "CoreFunction.h"
#include "BookComponents.h"

int buffBook(FILE* bookdata, Book &book) {
	LineBuffering(bookdata, book.ISBN, szISBN);
	LineBuffering(bookdata, book.BookName, szBookName);
	LineBuffering(bookdata, book.Author, szAuthor);
	LineBuffering(bookdata, book.Producer, szProducer);
	LineBuffering(bookdata, book.YearProducing, szYearProducing);
	LineBuffering(bookdata, book.Genre, szGenre);
	fscanf(bookdata,"%d %d", &book.Pricing, &book.Amount);
	fgetc(bookdata);
	return 1;
}
void buffAllBooks(FILE* bookdata, Book bookList[], int &bookcounter) {
	Book book;
	bookcounter = 0;
	while (!feof(bookdata))
	{
		if (bookcounter < maxBook && buffBook(bookdata, book) == 1)
		{
			bookList[bookcounter] = book;
			bookcounter++;
		}
		else return;
	}
	printf("Import successfully !");
}
void BookListing(Book bookList[]){
	printf("\t\t============= DANH SACH CAC SACH CO TRONG THU VIEN =============\n\n");
	if (bookcounter <= 0) printf("Hien tai chua co cuon sach nao trong co so du lieu thu vien !\n Vui long them sach.. \n");
	for (int i = 0; i < bookcounter; i++)
	{
		printf("\n");
		printf(" ============ THONG TIN CUON SACH THU %d =======================\n", i + 1);
		printf("   -> Ma sach : ");
		puts(bookList[i].ISBN);
		printf("   -> Ten sach : ");
		puts(bookList[i].BookName);
		printf("   -> Tac gia : ");
		puts(bookList[i].Author);
		printf("   -> Nha xuat ban : ");
		puts(bookList[i].Producer);
		printf("   -> Nam xuat ban : ");
		puts(bookList[i].YearProducing);
		printf("   -> The loai : ");
		puts(bookList[i].Genre);
		printf("   -> Gia thanh : %d VND \n", bookList[i].Pricing);
		printf("   -> So luong co san : %d\n", bookList[i].Amount);
	}
	_getch();
}
void BookDeclaration(Book bookList[]){
	while (true)
	{
		if (bookcounter > maxBook) printf("Khong du bo nho de them sach !");
		else while (bookcounter<maxBook)
		{
			printf("================ THONG TIN CUON SACH THU %d ==============\n", bookcounter + 1);
			fflush(stdin);//clear caches
			getchar();
			printf("    -> ISBN cuon sach thu %d : ", bookcounter + 1);
			gets_s(bookList[bookcounter].ISBN);
			printf("    -> Ten cuon sach thu %d : ", bookcounter + 1);
			gets_s(bookList[bookcounter].BookName);
			printf("    -> Ten tac gia cuon sach thu %d : ", bookcounter + 1);
			gets_s(bookList[bookcounter].Author);
			printf("    -> Nha san xuat cuon sach thu %d : ", bookcounter + 1);
			gets_s(bookList[bookcounter].Producer);
			printf("    -> Nam san xuat cuon sach thu %d : ", bookcounter + 1);
			gets_s(bookList[bookcounter].YearProducing);
			printf("    -> The loai cuon sach thu %d : ", bookcounter + 1);
			gets_s(bookList[bookcounter].Genre);
			printf("    -> Gia thanh cuon sach thu %d : ", bookcounter + 1);
			scanf_s("%d", &bookList[bookcounter].Pricing);
			printf("    -> So luong cuon nhap ve : ");
			scanf_s("%d", &bookList[bookcounter].Amount);
			totalbook += bookList[bookcounter].Amount;
			readybook += bookList[bookcounter].Amount;
			bookcounter++; break;
		}
		if (bookcounter >= 1) break; //Declaring max 1 books
	}
}
void BookEditing(Book bookList[]){

}