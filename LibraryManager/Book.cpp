/*
Copyright™ Hieu Hoang Minh. The Library Manager Project.
See source code on https://github.com/hyperion0201/LibraryManager2
Free for personal and commercial use under the MIT license .
2017. Ho Chi Minh University of Science.
*/
#include "Book.h"
#include "CoreFunction.h"

int buffBook(FILE* bookdata, Book &book) {
	LineBuffering(bookdata, book.ISBN, szISBN);
	LineBuffering(bookdata, book.BookName, szBookName);
	LineBuffering(bookdata, book.Author, szAuthor);
	LineBuffering(bookdata, book.Producer, szProducer);
	LineBuffering(bookdata, book.YearProducing, szYearProducing);
	LineBuffering(bookdata, book.Genre, szGenre);
	if (fscanf(bookdata,"%d %d", &book.Pricing, &book.Amount)<=0) return 0;
	else
	{
		totalbook += book.Amount;
		readybook += book.Amount;
	}
	fgetc(bookdata);
	return 1;
}
void BookFetching(FILE* bookdata, Book bookList[], int &bookcounter) {
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
	//("Books data were imported successfully !");
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
			printf("================ NHAP THONG TIN CUON SACH THU %d ==============\n", bookcounter + 1);
			fflush(stdin);//clear caches
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
void BookEditing(Book bookList[], int number){
	if (number > 0 && number <= bookcounter)
	{
		int choice;
		printf("============== MENU CHINH SUA SACH ================\n");
		printf("    1. Chinh sua ISBN\n");
		printf("    2. Chinh sua ten sach \n");
		printf("    3. Chinh sua tac gia \n");
		printf("    4. Chinh sua nha xuat ban \n");
		printf("    5. Chinh sua nam xuat ban \n");
		printf("    6. Chinh sua the loai\n");
		printf("    7. Chinh sua gia\n");
		printf("    8. Chinh sua so luong\n");
		printf("==================================================\n");
		printf(" Nhap vao lua chon cua ban : ");
		scanf_s("%d", &choice);
		getchar();
		switch (choice)
		{
		case 1: {
					fflush(stdin);
					char NewISBN[25];
					printf("Nhap vao ISBN moi : ");
					gets_s(NewISBN);
					strcpy_s(bookList[number - 1].ISBN, NewISBN);
					Sleep(1000);
					printf("Chinh sua thanh cong !");
					Sleep(500);
		} break;
		case 2: {
					fflush(stdin);
					char NewBookName[25];
					printf(" Nhap vao ten moi : ");
					gets_s(NewBookName);
					strcpy_s(bookList[number - 1].BookName, NewBookName);
					Sleep(1000);
					printf("Chinh sua thanh cong !");
					Sleep(500);
		} break;
		case 3: {
					fflush(stdin);
					char NewAuthor[25];
					printf("Nhap vao tac gia moi : ");
					gets_s(NewAuthor);
					strcpy_s(bookList[number - 1].Author, NewAuthor);
					Sleep(1000);
					printf("Chinh sua thanh cong !");
					Sleep(500);
		} break;
		case 4: {
					fflush(stdin);
					char NewProducer[25];
					printf("Nhap vao nha xuat ban moi : ");
					gets_s(NewProducer);
					strcpy_s(bookList[number - 1].Producer, NewProducer);
					Sleep(1000);
					printf("Chinh sua thanh cong !");
					Sleep(500);
		} break;
		case 5: {
					fflush(stdin);
					char NewYearProducing[25];
					printf("Nhap vao nam san xuat moi : ");
					gets_s(NewYearProducing);
					strcpy_s(bookList[number - 1].YearProducing, NewYearProducing);
					Sleep(1000);
					printf("Chinh sua thanh cong !");
					Sleep(500);
		} break;
		case 6: {
					fflush(stdin);
					char NewGenre[25];
					printf(" Nhap vao the loai moi : ");
					gets_s(NewGenre);
					strcpy_s(bookList[number - 1].Genre, NewGenre);
					Sleep(1000);
					printf("Chinh sua thanh cong !");
					Sleep(500);
		} break;
		case 7: {
					fflush(stdin);
					int newcost;
					printf("Nhap vao gia moi : ");
					scanf_s("%d", &newcost);
					bookList[number - 1].Pricing = newcost;
					Sleep(1000);
					printf("Chinh sua thanh cong !");
					Sleep(500);
		} break;
		case 8:
		{
				  int sl;
				  readybook -= bookList[number - 1].Amount;
				  totalbook -= bookList[number - 1].Amount;
				  printf(" -> Nhap vao so luong moi : ");
				  scanf_s("%d", &sl);
				  bookList[number - 1].Amount = sl;
				  totalbook += bookList[number - 1].Amount;
				  readybook += bookList[number - 1].Amount;
				  printf(" -> Thay doi so luong thanh cong !\n");
				  Sleep(500);
				  break;
		}
		default:
		{
				   printf(" Lua chon khong hop le ! Vui long thu lai ..");
				   Sleep(500);
				   break;
		}
		}
	}
	else
	{
		printf("Co loi xay ra khi chinh sua! Vui long thoat ra menu chinh va thu lai..");
		Sleep(500);
	}
}
void BookCreating(Book bookList[]){
	while (true)
	{
		int choice;
		printf("===================== MENU TAO SACH ========================\n");
		printf("                 -> 1. Tao sach moi                         \n");
		printf("                 -> 2. Thoat                                   \n");
		printf("===============================================================\n");
		printf("      -> Nhap vao lua chon cua ban : ");
		scanf_s("%d", &choice);
		if (choice == 1)
		{
			if (bookcounter > maxBook) printf("Khong du bo nho de tao hay cap nhat sach !");
			else while (bookcounter < maxBook)
			{
				printf("============ THONG TIN CUON SACH THU %d ============\n", bookcounter + 1);
				fflush(stdin);
				printf("    -> Nhap ma sach : ");
				gets_s(bookList[bookcounter].ISBN);
				printf("    -> Nhap ten sach : ");
				gets_s(bookList[bookcounter].BookName);
				printf("    -> Nhap tac gia : ");
				gets_s(bookList[bookcounter].Author);
				printf("    -> Nhap ten nha san xuat : ");
				gets_s(bookList[bookcounter].Producer);
				printf("    -> Nhap nam san xuat : ");
				gets_s(bookList[bookcounter].YearProducing);
				printf("    -> Nhap the loai : ");
				gets_s(bookList[bookcounter].Genre);
				printf("    -> Nhap gia : ");
				scanf_s("%d", &bookList[bookcounter].Pricing);
				printf("    -> Nhap vao so luong sach nhap ve : ");
				scanf_s("%d", &bookList[bookcounter].Amount);
				totalbook += bookList[bookcounter].Amount;
				readybook += bookList[bookcounter].Amount;
				bookcounter++;
				Sleep(1000);
				printf("Tao sach moi thanh cong !\n");
				Sleep(500);
				break;
			}
		}
		else if (choice == 2) break;
		break;
	}
}
void BookDeleting(Book bookList[], int number){
	int flag = 0;
	char answer;
	fflush(stdin);
	printf("  -> Ban co chac chan muon xoa hay khong ? (Y) de xoa, (N) de huy bo. : ");
	answer = getchar();
	if (answer == 'y' || answer == 'Y')
	{
		if (number > 0 && number <= bookcounter) {
			for (int i = number - 1; i < bookcounter - 1; i++) {
				strcpy_s(bookList[i].ISBN, bookList[i + 1].ISBN);
				strcpy_s(bookList[i].BookName, bookList[i + 1].BookName);
				strcpy_s(bookList[i].Author, bookList[i + 1].Author);
				strcpy_s(bookList[i].Producer, bookList[i + 1].Producer);
				strcpy_s(bookList[i].YearProducing, bookList[i + 1].YearProducing);
				strcpy_s(bookList[i].Genre, bookList[i + 1].Genre);
				bookList[i].Pricing = bookList[i + 1].Pricing;
				bookList[i].Amount = bookList[i + 1].Amount;
			}
			totalbook -= bookList[number - 1].Amount;
			readybook -= bookList[number - 1].Amount;
			bookcounter--;
			flag = 1;
		}
	}
	else if (answer == 'n' || answer == 'N')
	{
	printf("  -> Da huy.");
		Sleep(1000);
		return;
	}
	if (flag == 1) {
		printf(" -> Xoa thanh cong !\n");
		printf("\n");
		Sleep(1000);
		BookListing(bookList);
	}
	else
	{
		printf("Co loi khi xoa, vui long thu lai..");
		Sleep(1000);
	}
}
void SeeBookChanges(Book bookList[], int number){
	printf("============ THONG TIN CUON SACH THU %d SAU KHI CHINH SUA ==============\n", number);
	printf("   -> Ma sach : ");
	puts(bookList[number - 1].ISBN);
	printf("   -> Ten sach : ");
	puts(bookList[number - 1].BookName);
	printf("   -> Tac gia : ");
	puts(bookList[number - 1].Author);
	printf("   -> Nha xuat ban : ");
	puts(bookList[number - 1].Producer);
	printf("   -> Nam xuat ban : ");
	puts(bookList[number - 1].YearProducing);
	printf("   -> The loai : ");
	puts(bookList[number - 1].Genre);
	printf("   -> Gia thanh : %d VND \n", bookList[number - 1].Pricing);
	printf("   -> So luong co san : %d\n", bookList[number - 1].Amount);
	_getch();
}
void EBSubMenu(int number){
	while (true)
	{
		if (number > 0 && number <= bookcounter)
		{
			system("cls");
			int choice;
			printf("==================== MENU CHINH SUA SACH ====================\n");
			printf("\n");
			printf("     -> 1. Tiep tuc chinh sua va cap nhat cuon sach thu %d\n", number);
			printf("     -> 2. Xem thong tin cuon sach thu %d sau khi chinh sua\n", number);
			printf("     -> 3. Thoat chinh sua\n");
			printf("=============================================================\n");
			printf("  Nhap vao lua chon cua ban : ");
			scanf_s("%d", &choice);
			if (choice == 3) break;
			switch (choice)
			{
			case 1: BookEditing(bookList, number); break;
			case 2: SeeBookChanges(bookList, number); break;
			default: printf("Lenh khong ton tai, xin thu lai..");
				break;
			}
		}
		else
		{
			printf("Du lieu sach khong ton tai trong thu vien ! Vui long thu lai ...\n");
			Sleep(1000);
			break;
		}
	}
	//_getch();
}
void FindByBookName(Book bookList[], char bname[szBookName]){
	int flag = 0;
	printf("============ KET QUA TIM KIEM ===========\n");
	for (int i = 0; i < bookcounter; i++) {
		if (strcmp(bname, bookList[i].BookName) == 0) {
			printf("\n");
			printf("    -> Ma sach : ");
			puts(bookList[i].ISBN);
			printf("    -> Ten sach : ");
			puts(bookList[i].BookName);
			printf("    -> Tac gia : ");
			puts(bookList[i].Author);
			printf("    -> Nha xuat ban : ");
			puts(bookList[i].Producer);
			printf("    -> Nam xuat ban : ");
			puts(bookList[i].YearProducing);
			printf("    -> The loai : ");
			puts(bookList[i].Genre);
			printf("    -> Gia(VND) : %d\n", bookList[i].Pricing);
			printf("    -> So luong hien co : %d\n", bookList[i].Amount);
			printf("==========================================\n");
			flag++;
		}
	}
	if (flag == 0) printf("Khong tim thay ket qua !");
	else
	{
		printf("\n");
		printf("   - > Tong cong co %d sach duoc tim thay.\n", flag);
	}
	_getch();
}
void FindByISBN(Book bookList[], char isbn[szISBN]){
	int flag = 0;
	printf("============ KET QUA TIM KIEM ===========\n");
	for (int i = 0; i < bookcounter; i++) {
		if (strcmp(isbn, bookList[i].ISBN) == 0) {
			printf("\n");
			printf("    -> Ma sach : ");
			puts(bookList[i].ISBN);
			printf("    -> Ten sach : ");
			puts(bookList[i].BookName);
			printf("    -> Tac gia : ");
			puts(bookList[i].Author);
			printf("    -> Nha xuat ban : ");
			puts(bookList[i].Producer);
			printf("    -> Nam xuat ban : ");
			puts(bookList[i].YearProducing);
			printf("    -> The loai : ");
			puts(bookList[i].Genre);
			printf("    -> Gia(VND) : %d\n", bookList[i].Pricing);
			printf("    -> So luong hien co : %d\n", bookList[i].Amount);
			printf("==========================================\n");
			flag++;
		}
	}
	if (flag == 0) printf("Khong tim thay ket qua !");
	else
	{
		printf("\n");
		printf("   - > Tong cong co %d sach duoc tim thay.\n", flag);
	}
	_getch();
}
void bookSaveInstance(FILE* bookdata, Book bookList[], int bookcounter){
	for (int i = 0; i < bookcounter; i++)
	{
		fputs(bookList[i].ISBN,bookdata);
		fprintf(bookdata, "\n");
		fputs(bookList[i].BookName, bookdata);
		fprintf(bookdata, "\n");
		fputs(bookList[i].Author, bookdata);
		fprintf(bookdata, "\n");
		fputs(bookList[i].Producer, bookdata);
		fprintf(bookdata, "\n");
		fputs(bookList[i].YearProducing, bookdata);
		fprintf(bookdata, "\n");
		fputs(bookList[i].Genre, bookdata);
		fprintf(bookdata, "\n");
		fprintf(bookdata, "%d %d", bookList[i].Pricing, bookList[i].Amount);
		fprintf(bookdata, "\n");
	}
}
void BookListingENG(Book bookList[]){
	printf("\t\t============= BOOKS LIST IN LIBRARY DATABASE =============\n\n");
	if (bookcounter <= 0) printf("There is no book available to show. Please add a book...\n");
	for (int i = 0; i < bookcounter; i++)
	{
		printf("\n");
		printf(" ==================== INFORMATION OF BOOK %d =======================\n", i + 1);
		printf("   -> ISBN : ");
		puts(bookList[i].ISBN);
		printf("   -> Book name : ");
		puts(bookList[i].BookName);
		printf("   -> Author : ");
		puts(bookList[i].Author);
		printf("   -> Producer : ");
		puts(bookList[i].Producer);
		printf("   -> Year producing : ");
		puts(bookList[i].YearProducing);
		printf("   -> Genre : ");
		puts(bookList[i].Genre);
		printf("   -> Pricing : %d VND \n", bookList[i].Pricing);
		printf("   -> Amount available for borrowing : %d\n", bookList[i].Amount);
	}
	_getch();
}
void BookDeclarationENG(Book bookList[]){
	while (true)
	{
		if (bookcounter > maxBook) printf("Not enough memory for declaring a book! Check database, or reset the app and try again.");
		else while (bookcounter<maxBook)
		{
			printf("================ BOOK %d INFORMATION INPUT ==============\n", bookcounter + 1);
			fflush(stdin);//clear caches
			printf("    -> ISBN of book %d : ", bookcounter + 1);
			gets_s(bookList[bookcounter].ISBN);
			printf("    -> Book name of book %d : ", bookcounter + 1);
			gets_s(bookList[bookcounter].BookName);
			printf("    -> Author of book %d : ", bookcounter + 1);
			gets_s(bookList[bookcounter].Author);
			printf("    -> Producer of book %d : ", bookcounter + 1);
			gets_s(bookList[bookcounter].Producer);
			printf("    -> Year producing of book %d : ", bookcounter + 1);
			gets_s(bookList[bookcounter].YearProducing);
			printf("    -> Genre of book %d : ", bookcounter + 1);
			gets_s(bookList[bookcounter].Genre);
			printf("    -> Pricing of book %d : ", bookcounter + 1);
			scanf_s("%d", &bookList[bookcounter].Pricing);
			printf("    -> Amount deliveried of book %d : ", bookcounter + 1);
			scanf_s("%d", &bookList[bookcounter].Amount);
			totalbook += bookList[bookcounter].Amount;
			readybook += bookList[bookcounter].Amount;
			bookcounter++; break;
		}
		if (bookcounter >= 1) break; //Declaring max 1 books
	}
}
void BookEditingENG(Book bookList[], int number){
	if (number > 0 && number <= bookcounter)
	{
		int choice;
		printf("================ BOOK MODIFYING MENU ================\n");
		printf("    1. Modify ISBN\n");
		printf("    2. Modify book name \n");
		printf("    3. Modify author  \n");
		printf("    4. Modify producer \n");
		printf("    5. Modify year producing \n");
		printf("    6. Modify genre \n");
		printf("    7. Modify pricing \n");
		printf("    8. Modify amount \n");
		printf("==================================================\n");
		printf(" Input your choice : ");
		scanf_s("%d", &choice);
		getchar();
		switch (choice)
		{
		case 1: {
					fflush(stdin);
					char NewISBN[25];
					printf("Input new ISBN : ");
					gets_s(NewISBN);
					strcpy_s(bookList[number - 1].ISBN, NewISBN);
					Sleep(1000);
					printf("ISBN modified successfully !");
					Sleep(500);
		} break;
		case 2: {
					fflush(stdin);
					char NewBookName[25];
					printf(" Input new book name : ");
					gets_s(NewBookName);
					strcpy_s(bookList[number - 1].BookName, NewBookName);
					Sleep(1000);
					printf("Book name modified successfully !");
					Sleep(500);
		} break;

		case 3: {
					fflush(stdin);
					char NewAuthor[25];
					printf("Input new author : ");
					gets_s(NewAuthor);
					strcpy_s(bookList[number - 1].Author, NewAuthor);
					Sleep(1000);
					printf("Author modified successfully !");
					Sleep(500);
		} break;
		case 4: {
					fflush(stdin);
					char NewProducer[25];
					printf("Input new producer : ");
					gets_s(NewProducer);
					strcpy_s(bookList[number - 1].Producer, NewProducer);
					Sleep(1000);
					printf("Producer modified successfully !");
					Sleep(500);
		} break;
		case 5: {
					fflush(stdin);
					char NewYearProducing[25];
					printf("Input new year producing : ");
					gets_s(NewYearProducing);
					strcpy_s(bookList[number - 1].YearProducing, NewYearProducing);
					Sleep(1000);
					printf("Year producing modified successfully !");
					Sleep(500);
		} break;
		case 6: {
					fflush(stdin);
					char NewGenre[25];
					printf("Input new genre : ");
					gets_s(NewGenre);
					strcpy_s(bookList[number - 1].Genre, NewGenre);
					Sleep(1000);
					printf("Genre modified successfully !");
					Sleep(500);
		} break;
		case 7: {
					fflush(stdin);
					int newcost;
					printf("Input new pricing : ");
					scanf_s("%d", &newcost);
					bookList[number - 1].Pricing = newcost;
					Sleep(1000);
					printf("Pricing modified successfully !");
					Sleep(500);
		} break;
		case 8:
		{
				  int sl;
				  readybook -= bookList[number - 1].Amount;
				  totalbook -= bookList[number - 1].Amount;
				  printf(" -> Input new amount : ");
				  scanf_s("%d", &sl);
				  bookList[number - 1].Amount = sl;
				  totalbook += bookList[number - 1].Amount;
				  readybook += bookList[number - 1].Amount;
				  printf(" -> Amount modified successfully !\n");
				  Sleep(500);
				  break;
		}
		default:
		{
				   printf(" Invalid choice, please try again...");
				   Sleep(500);
				   break;
		}
		}
	}
	else
	{
		printf("An unexpected error occurred. Please try again..");
		Sleep(500);
	}
}
void BookCreatingENG(Book bookList[]){
	while (true)
	{
		int choice;
		printf("===================== BOOK CREATING MENU ========================\n");
		printf("                 -> 1. Create a book                             \n");
		printf("                 -> 2. Go back                                   \n");
		printf("=================================================================\n");
		printf("      -> Input your choice : ");
		scanf_s("%d", &choice);
		if (choice == 1)
		{
			if (bookcounter > maxBook) printf("Not enough memory for creating a book !");
			else while (bookcounter < maxBook)
			{
				printf("============ BOOK %d INFORMATIONS INPUT ============\n", bookcounter + 1);
				fflush(stdin);
				printf("    -> Input ISBN : ");
				gets_s(bookList[bookcounter].ISBN);
				printf("    -> Input book name : ");
				gets_s(bookList[bookcounter].BookName);
				printf("    -> Input author : ");
				gets_s(bookList[bookcounter].Author);
				printf("    -> Input producer : ");
				gets_s(bookList[bookcounter].Producer);
				printf("    -> Input year producing : ");
				gets_s(bookList[bookcounter].YearProducing);
				printf("    -> Input genre : ");
				gets_s(bookList[bookcounter].Genre);
				printf("    -> Input pricing : ");
				scanf_s("%d", &bookList[bookcounter].Pricing);
				printf("    -> Input amount deliveried : ");
				scanf_s("%d", &bookList[bookcounter].Amount);
				totalbook += bookList[bookcounter].Amount;
				readybook += bookList[bookcounter].Amount;
				bookcounter++;
				Sleep(1000);
				printf("Book created successfully !\n");
				Sleep(500);
				break;
			}
		}
		else if (choice == 2) break;
		break;
	}
}
void BookDeletingENG(Book bookList[], int number){
	int flag = 0;
	char answer;
	fflush(stdin);
	printf("  -> Confirm delete? (Y/N) : ");
	answer = getchar();
	if (answer == 'y' || answer == 'Y')
	{
		if (number > 0 && number <= bookcounter) {
			for (int i = number - 1; i < bookcounter - 1; i++) {
				strcpy_s(bookList[i].ISBN, bookList[i + 1].ISBN);
				strcpy_s(bookList[i].BookName, bookList[i + 1].BookName);
				strcpy_s(bookList[i].Author, bookList[i + 1].Author);
				strcpy_s(bookList[i].Producer, bookList[i + 1].Producer);
				strcpy_s(bookList[i].YearProducing, bookList[i + 1].YearProducing);
				strcpy_s(bookList[i].Genre, bookList[i + 1].Genre);
				bookList[i].Pricing = bookList[i + 1].Pricing;
				bookList[i].Amount = bookList[i + 1].Amount;
			}
			totalbook -= bookList[number - 1].Amount;
			readybook -= bookList[number - 1].Amount;
			bookcounter--;
			flag = 1;
		}
	}
	else if (answer == 'n' || answer == 'N')
	{
		printf("  -> Cancelled.");
		Sleep(1000);
		return;
	}
	if (flag == 1) {
		printf(" -> Deleted successfully !\n");
		printf("\n");
		Sleep(1000);
		BookListing(bookList);
	}
	else
	{
		printf("An error occurred when delete this book. Please try again...");
		Sleep(1000);
	}
}
void SeeBookChangesENG(Book bookList[], int number){
	printf("============ BOOK %d INFORMATION AFTER MODIFIED ==============\n", number);
	printf("   -> ISBN : ");
	puts(bookList[number - 1].ISBN);
	printf("   -> Book name : ");
	puts(bookList[number - 1].BookName);
	printf("   -> Author : ");
	puts(bookList[number - 1].Author);
	printf("   -> Producer : ");
	puts(bookList[number - 1].Producer);
	printf("   -> Year producing : ");
	puts(bookList[number - 1].YearProducing);
	printf("   -> Genre : ");
	puts(bookList[number - 1].Genre);
	printf("   -> Pricing : %d VND \n", bookList[number - 1].Pricing);
	printf("   -> Amount available for borrowing : %d\n", bookList[number - 1].Amount);
	_getch();
}
void EBSubMenuENG(int number){
	while (true)
	{
		if (number > 0 && number <= bookcounter)
		{
			system("cls");
			int choice;
			printf("==================== BOOK MODIFYING MENU ====================\n");
			printf("\n");
			printf("     -> 1. Continue to modify book %d\n", number);
			printf("     -> 2. See informations of book %d after/before modifying\n", number);
			printf("     -> 3. Go back\n");
			printf("=============================================================\n");
			printf("  Input your choice : ");
			scanf_s("%d", &choice);
			if (choice == 3) break;
			switch (choice)
			{
			case 1: BookEditingENG(bookList, number); break;
			case 2: SeeBookChangesENG(bookList, number); break;
			default: printf("Invalid choice, please try again...");
				break;
			}
		}
		else
		{
			printf("Book is not exist in database, please try again...\n");
			Sleep(1000);
			break;
		}
	}
	//_getch();
}
void FindByBookNameENG(Book bookList[], char bname[szBookName]){
	int flag = 0;
	printf("============ SEARCHING RESULT ===========\n");
	for (int i = 0; i < bookcounter; i++) {
		if (strcmp(bname, bookList[i].BookName) == 0) {
			printf("\n");
			printf("    -> ISBN : ");
			puts(bookList[i].ISBN);
			printf("    -> Book name : ");
			puts(bookList[i].BookName);
			printf("    -> Author : ");
			puts(bookList[i].Author);
			printf("    -> Producer : ");
			puts(bookList[i].Producer);
			printf("    -> Year producing : ");
			puts(bookList[i].YearProducing);
			printf("    -> Genre : ");
			puts(bookList[i].Genre);
			printf("    -> Pricing (VND) : %d\n", bookList[i].Pricing);
			printf("    -> Amount available : %d\n", bookList[i].Amount);
			printf("==========================================\n");
			flag++;
		}
	}
	if (flag == 0) printf("No result !");
	else
	{
		printf("\n");
		printf("   - > Searched end with %d results.\n", flag);
	}
	_getch();
}
void FindByISBNENG(Book bookList[], char isbn[szISBN]){
	int flag = 0;
	printf("============ SEARCHING RESULT ===========\n");
	for (int i = 0; i < bookcounter; i++) {
		if (strcmp(isbn, bookList[i].ISBN) == 0) {
			printf("\n");
			printf("    -> ISBN : ");
			puts(bookList[i].ISBN);
			printf("    -> Book name : ");
			puts(bookList[i].BookName);
			printf("    -> Author : ");
			puts(bookList[i].Author);
			printf("    -> Producer : ");
			puts(bookList[i].Producer);
			printf("    -> Year producing : ");
			puts(bookList[i].YearProducing);
			printf("    -> Genre : ");
			puts(bookList[i].Genre);
			printf("    -> Pricing (VND) : %d\n", bookList[i].Pricing);
			printf("    -> Amount available : %d\n", bookList[i].Amount);
			printf("==========================================\n");
			flag++;
		}
	}
	if (flag == 0) printf("No result !");
	else
	{
		printf("\n");
		printf("   - > Searched end with %d results.\n", flag);
	}
	_getch();
}
