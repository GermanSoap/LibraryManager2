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
	getchar();
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

				totalbook -= bookList[i].Amount;

				bookList[i].Amount = bookList[i + 1].Amount;

			}

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