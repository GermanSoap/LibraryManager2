/*
Copyright™ Hieu Hoang Minh. The Library Manager Project.
See source code on https://github.com/hyperion0201/LibraryManager2
Free for personal and commercial use under the MIT license .
2017. Ho Chi Minh University of Science.
*/
#include "Card.h"
#include "Book.h"
#include "Student.h"
#include "CoreFunction.h"
BorrowingCard cardList[maxCard];
int brcard = 0;
int rtcard = 0;
int PenaltyFee(BorrowingCard cardList[], Time esReturn, Time realReturn){
	// Initiating variables : daysover(days over rules), fee(money for paying), distance1(between 2 returning time),
	int daysover, distance1, distance2;
	int fee = 0;
	// In-condition : esReturn.year = realReturn.year, esReturn.month = realReturn.month
	if (esReturn.year == realReturn.year) // Same year
	{
		if (esReturn.month == realReturn.month)  // Same month
		{
			if (esReturn.day >= realReturn.day) return 0;
			else
			{
			daysover = realReturn.day - esReturn.day;
			fee = daysover * 5000;
				return fee;
			}
		}
		// In-condition: esReturn.month != realReturn.month
		else if (esReturn.month < realReturn.month)
		{
			// If esReturn.month = 2
			if (esReturn.month == 2)
			{
				// Check if leap year
				if ((esReturn.year % 4 == 0 && esReturn.year % 100 != 0) || esReturn.year % 400 == 0)
				{
					// Caculating distance from	realReturn.day of realReturn.month to esReturn.day of esReturn.month
					distance1 = realReturn.day;
					int i = realReturn.month - 1;
					for (i; i > esReturn.month; i--)
					{
						if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) distance1 = distance1 + 31;
						else distance1 = distance1 + 30;
					}
					// Nam nhuan nen so ngay qua han bang distance + (29 - esReturn.day)
					daysover = distance1 + (29 - esReturn.day);
					fee = 5000 * daysover;
					return fee;
				}
				else // Not a leap year
				{
					distance1 = realReturn.day;
					int i = realReturn.month - 1;
					for (i; i > esReturn.month; i--)
					{
						if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) distance1 += 31;
						else distance1 += 30;
					}
					// Nam khong nhuan nen so ngay qua han bang distance + (28-esReturn.day)
					daysover = distance1 + (28 - esReturn.day);
					fee = 5000 * daysover;
				return fee;
				}
			}
			else //esReturn.month != 2
			{
				// if returning month in 1,3,5,7,8,10,12 which has 31 days
				if (esReturn.month == 1 || esReturn.month == 3 || esReturn.month == 5 || esReturn.month == 7 || esReturn.month == 8 || esReturn.month == 10 || esReturn.month == 12)
				{
					// Check if leap year
					if ((esReturn.year % 4 == 0 && esReturn.year % 100 != 0) || esReturn.year % 400 == 0)
					{
						distance1 = realReturn.day;
						int i = realReturn.month - 1;
						for (i; i > esReturn.month; i--)
						{
						if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) distance1 += 31;
							else if (i == 2) distance1 += 29;
							else distance1 += 30;
						}
						daysover = distance1 + (31 - esReturn.day);
						fee = 5000 * daysover;
						return fee;
					}
					else // not a leap year
					{
						distance1 = realReturn.day;
						int i = realReturn.month - 1; // check next month
						for (i; i > esReturn.month; i--)
						{
							if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) distance1 += 31;
							else if (i == 2) distance1 += 28;
							else distance1 += 30;
						}
						daysover = distance1 + (31 - esReturn.day);
						fee = daysover * 5000;
						return fee;
					}
				}
				else // if in month 4,6,9,11  which has 30 days
				{
					if ((esReturn.year % 4 == 0 && esReturn.year % 100 != 0) || esReturn.year % 400 == 0)
					{
						distance1 = realReturn.day;
						int i = realReturn.month - 1;
						for (i; i > esReturn.month; i--)
						{
							if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) distance1 += 31;
							else if (i == 2) distance1 += 29;
							else distance1 += 30;
						}
						daysover = distance1 + (30 - esReturn.day);
						fee = 5000 * daysover;
						return fee;
					}
					else // not leap year
					{
						distance1 = realReturn.day;
						int i = realReturn.month - 1;
						for (i; i > esReturn.month; i--)
						{
							if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) distance1 += 31;
							else if (i == 2) distance1 += 28;
							else distance1 += 30;
						}
						daysover = distance1 + (30 - esReturn.day);
						fee = 5000 * daysover;
						return fee;
					}
				}
			}
		}
		return fee;
	}
	else// In-condition : esReturn.year < realReturn.year
	{
		distance2 = 0;
		// calculating distance from esReturn.day, esReturn.month to 31/12/esReturn.year.
		if (esReturn.month == 2) // if esReturn.month = 2
		{
			//check leap year

			if ((esReturn.year % 4 == 0 && esReturn.year % 100 != 0) || esReturn.year % 400 == 0)

			{

				// calculating distance from realReturn.day of realReturn.month to esReturn.day of esReturn.month

				int i = esReturn.month + 1;

				for (i; i <= 12; i++)

				{

					if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) distance2 += 31;

					else if (i == 2) distance2 += 29;

					else distance2 += 30;

				}

				daysover = distance2 + (29 - esReturn.day);

			}

			else // not a leap year

			{

				int i = esReturn.month + 1;

				for (i; i <= 12; i++)

				{

					if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) distance2 += 31;

					else if (i == 2) distance2 += 28;

					else distance2 += 30;

				}

				daysover = distance2 + (28 - esReturn.day);

			}

		}

		else // if esReturn.month != 2

		{

			// if esReturn.month in 1,3,5,7,8,10,12

			if (esReturn.month == 1 || esReturn.month == 3 || esReturn.month == 5 || esReturn.month == 7 || esReturn.month == 8 || esReturn.month == 10 || esReturn.month == 12)

			{

				// check leap year

				if ((esReturn.year % 4 == 0 && esReturn.year % 100 != 0) || esReturn.year % 400 == 0)

				{

					int i = esReturn.month + 1;

					for (i; i <= 12; i++)

					{

						if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) distance2 += 31;

						else if (i == 2) distance2 += 29;

						else distance2 += 30;

					}

					daysover = distance2 + (31 - esReturn.day);

				}

				else // not a leap year

				{

					int i = esReturn.month + 1;

					for (i; i <= 12; i++)

					{

						if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) distance2 += 31;

						else if (i == 2) distance2 += 28;

						else distance2 += 30;

					}

					daysover = distance2 + (31 - esReturn.day);

				}

			}

			else // esReturn.month in 4,6,9,11

			{

				// check leap year

				if ((esReturn.year % 4 == 0 && esReturn.year % 100 != 0) || esReturn.year % 400 == 0)

				{

					int i = esReturn.month + 1;

					for (i; i <= 12; i++)

					{

						if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) distance2 += 31;

						else if (i == 2) distance2 += 29;

						else distance2 += 30;

					}

					daysover = distance2 + (30 - esReturn.day);

				}

				else //not a leap year

				{

					int i = esReturn.month + 1;

					for (i; i <= 12; i++)

					{

						if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) distance2 += 31;

						else if (i == 2) distance2 += 28;

						else distance2 += 30;

					}

					daysover = distance2 + (30 - esReturn.day);

				}

			}

		}

		// calculating distance from 1/1/realReturn.year to realReturn.day/realReturn.month/realReturn.year

		int daysover2 = 0;

		// check leap year

		if ((realReturn.year % 4 == 0 && realReturn.year % 100 != 0) || realReturn.year % 400 == 0)

		{

			if (realReturn.month == 1) daysover2 = realReturn.day; // Jan

			else if (realReturn.month == 2) daysover2 = 31 + realReturn.day; // Feb 

			else // all except Jan, Feb

			{

				daysover2 = realReturn.day;

				int i = realReturn.month - 1;

				for (i; i > 0; i--)

				{

					if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) daysover2 += 31;

					else if (i == 2) daysover2 += 29;

					else daysover2 += 30;

				}

			}

		}

		else // not a leap year

		{

			if (realReturn.month == 1) daysover2 = realReturn.day;

			else if (realReturn.month == 2) daysover2 = 31 + realReturn.day;

			else // except Jan, Feb

			{

				daysover2 = realReturn.day;

				int i = realReturn.month - 1;

				for (i; i > 0; i--)

				{

					if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) daysover2 += 31;

					else if (i == 2) daysover2 += 28;

					else daysover2 += 30;

				}

			}

		}

		// calculating  days between esReturn.year -> realReturn.year

		int daysover3 = 0;

		for (int i = realReturn.year; i > esReturn.year; i--)

		{

			// if leap year

			if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) daysover3 += 366;

			else daysover3 += 365;

		}

		// Total days over :

		int totaldaysover = daysover + daysover2 + daysover3;

		fee = 5000 * totaldaysover;

		return fee;

	}


}
void BorrowingInput(BorrowingCard cardList[], Book bookList[]){
	system("cls");
	while (true)
	{
		if (brcard >= maxCard) printf("Khong du bo nho de tao the muon moi !");
		else while (brcard < maxCard)
		{
			fflush(stdin); //Clear caches
			do {
				int flag = 0;
				printf("\t============ NHAP THONG TIN DOC GIA MUON ============\n");
				printf("\t-> Nhap ma doc gia can muon : ");
				gets_s(cardList[brcard].brID);
				for (int i = 0; i<studentcounter; i++)
				if (strcmp(studentList[i].LibID, cardList[brcard].brID) == 0)
				{
					strcpy(cardList[brcard].brName, studentList[i].Name);
					flag = 1; // already in db
					break;
				}
				if (flag == 1) break;
				else if (flag == 0) {
					printf(" -> Chua co thong tin doc gia trong thu vien ! Vui long tao hoac cap nhat ! \n");
					Sleep(1000);
					system("cls");
					continue;
				}
			} while (true);

			// input borrowing day	
			printf("\n");
			printf("\t=============== NHAP NGAY MUON ========================\n");
			printf("\t  -> Nhap ngay muon : ");
			scanf_s("%d", &cardList[brcard].timeBorrow.day);
			printf("\t  -> Nhap thang muon : ");
			scanf_s("%d", &cardList[brcard].timeBorrow.month);
			printf("\t  -> Nhap nam muon : ");
			scanf_s("%d", &cardList[brcard].timeBorrow.year);
			printf("\n");
			cardList[brcard].esReturn.day = EstimatedTime(cardList[brcard].timeBorrow).day;
			cardList[brcard].esReturn.month = EstimatedTime(cardList[brcard].timeBorrow).month;
			cardList[brcard].esReturn.year = EstimatedTime(cardList[brcard].timeBorrow).year;
			printf("\t=============== NHAP THONG TIN SACH MUON ==============\n");
			do
			{
				printf("\n");
				printf("\t  -> Nhap so luong sach doc gia can muon : ");
				scanf_s("%d", &cardList[brcard].brAmount);
				if (cardList[brcard].brAmount > bookcounter)
				{
					printf("  -> So sach muon vuot qua du lieu thu vien ! Vui long thu lai !\n");
					Sleep(1000);
					continue;
				}
				else
				{
					readybook -= cardList[brcard].brAmount;
					borrowedbook += cardList[brcard].brAmount;
					//remainingbook = bookInATime[brcard];
					break;
				}
			} while (true);

			getchar();
			for (int i = 0; i < cardList[brcard].brAmount; i++) {
				fflush(stdin);
				do
				{
					int flag = 0;
					printf("\t  -> Nhap ma sach thu %d :  ", i + 1);
					gets_s(cardList[brcard].brList[i].brISBN);
					for (int j = 0; j < bookcounter; j++)
					{
						if (strcmp(cardList[brcard].brList[i].brISBN, bookList[j].ISBN) == 0 && bookList[j].Amount>0)
						{
							flag = 1; // already in db
							cardList[brcard].brList[i].returned = 0;
							bookList[j].Amount--;
							strcpy(cardList[brcard].brList[i].brBookName, bookList[j].BookName);
							break;
						}
					}
					if (flag == 1)
					{
						printf(" -> Them sach vao the muon thanh cong ! \n");
						Sleep(1000);
						break;
					}

					else if (flag == 0)
					{
						printf(" -> Thong tin sach khong ton tai trong thu vien ! Vui long tao moi hoac cap nhat !\n");
						Sleep(1000);
						system("cls");
						continue;
					}

				} while (true);
			}
			brcard++; break;
		}
		break;
	}
}
Time EstimatedTime(Time timeBorrow){
	Time estTime = { 0 };
	int realreturnday;
	switch (timeBorrow.month)
	{
	case 1: case 3: case 5:case 7: case 8: case 10: case 12: realreturnday = 31; break;
	case 4: case 6: case 9:case 11: realreturnday = 30; break;
	case 2: if (timeBorrow.year % 400 == 0 || (timeBorrow.year % 4 == 0 && timeBorrow.year % 100 != 0))
		realreturnday = 29;
			else realreturnday = 28; break;
	default: realreturnday = NULL;
		break;
	}
	// Determining Estimated time
	if (timeBorrow.day == realreturnday) // Mean if borrows in last day of a month
	{
		estTime.day = 7; // Maximum days for borrowing are 7 days
		estTime.month = timeBorrow.month + 1;
		estTime.year = timeBorrow.year;
	}
	else {
		estTime.day = timeBorrow.day + 7;
		if (estTime.day > realreturnday)
		{
			estTime.day = estTime.day - realreturnday;
			estTime.month = timeBorrow.month + 1;
		}
		else estTime.month = timeBorrow.month;
		estTime.year = timeBorrow.year;
	}
	// Processing for days approx. the end of a year
	if (estTime.month > 12)
	{
		estTime.month = 1;
		estTime.year = timeBorrow.year + 1;
	}
	return estTime;
}
void getBorrowingList(BorrowingCard cardList[]){
	system("cls");
	if (brcard == 0) printf("  -> Hien tai khong co doc gia nao muon sach ! Vui long kiem tra lai..\n");
	else
	{
		printf("  -> Tong so co : %d phieu muon\n\n ", brcard);
		printf("=================== PHIEU MUON SACH CUA DOC GIA  ==================\n");
		printf("\n");
		for (int i = 0; i < brcard; i++)
		{
			printf("================ THONG TIN PHIEU MUON DOC GIA THU %d ================\n", i + 1);
			printf("   -> Ma so doc gia : ");
			puts(cardList[i].brID);
			printf("   -> Ten doc gia : ");
			puts(cardList[i].brName);
			printf("   -> Thoi gian muon sach gan nhat la : %d/%d/%d\n",cardList[i].timeBorrow.day, cardList[i].timeBorrow.month, cardList[i].timeBorrow.year);
			printf("   -> Thoi gian tra sach du kien : %d/%d/%d\n", EstimatedTime(cardList[i].timeBorrow).day, EstimatedTime(cardList[i].timeBorrow).month, EstimatedTime(cardList[i].timeBorrow).year);
			printf("   -> So sach da muon : %d\n", cardList[i].brAmount);
			printf("   -> DANH SACH CAC CUON SACH DA MUON :\n");
			for (int k = 0; k < cardList[i].brAmount; k++)
			{
				printf("              -> ISBN cuon sach thu %d : ", k + 1);
				puts(cardList[i].brList[k].brISBN);
				printf("              -> Ten cuon sach thu %d  : ", k + 1);
				puts(cardList[i].brList[k].brBookName);
				printf("              -> Trang thai : ");
				if (cardList[i].brList[k].returned == 0) printf("Chua tra\n");
				else printf("Da tra\n");
			}
			printf("\n");
			printf("====================================================================\n");
		}
		printf("===================== DOC GIA CAN LUU Y : ========================= \n");
		printf(" -> Chi duoc phep muon sach toi da 7 ngay.\n");
		printf(" -> Neu tre han thi phat 5000VND/1 ngay/1 sach.\n");
		printf(" -> Neu mat sach thi phai boi thuong 200 phan tram gia tri cuon sach do.\n");
		printf(" Mong doc gia thuc hien nghiem tuc.\n");
		printf("===================================================================\n");
	}
	_getch();
}
void ReturningInput(BorrowingCard cardList[]){
	while (true)
	{
		int brlocation;
		system("cls");
		while (true)
		{
			fflush(stdin); // clear caches
			printf("=============== NHAP THONG TIN DOC GIA TRA SACH ============\n ");
			do
			{
				char returnID[szLibID];
				int flag = 0;
				printf("     -> Nhap ma doc gia can tra sach : ");
				gets_s(returnID);
				for (int i = 0; i < brcard; i++)
				{
					if (strcmp(returnID, cardList[i].brID) == 0)
					{
						flag = 1; // already in db
						brlocation = i;  // point the borrower location
						break;
					}
				}
				if (flag == 1)
				{
					break;
				}
				else
				{
					printf("  -> Doc gia nay chua muon sach nen khong co trong du lieu cua thu vien !\n");
					Sleep(1000);
					system("cls");
					continue;
				}
			} while (true);

			printf("     -> Nhap ngay tra sach thuc te : ");
			scanf_s("%d", &cardList[brlocation].realReturn.day);
			printf("     -> Nhap thang tra sach thuc te : ");
			scanf_s("%d", &cardList[brlocation].realReturn.month);
			printf("     -> Nhap nam tra sach thuc te : ");
			scanf_s("%d", &cardList[brlocation].realReturn.year);
			do
			{
				printf("\n");
				
				int rtbook;
				printf("     -> Nhap so sach can tra : ");
				scanf_s("%d", &rtbook);
				if (rtbook > cardList[brlocation].brAmount)
					continue;
				else if (rtbook == cardList[brlocation].brAmount) // return all books in a time
				{
					borrowedbook -= rtbook;
					readybook += rtbook;
					char rtISBN[10][szISBN];
					for (int j = 0; j < rtbook; j++)
					{
						printf("   -> Nhap ma sach can tra thu %d : ", j + 1);
						
						fflush(stdin);
						gets_s(rtISBN[j]);
						for (int k = 0; k < cardList[brlocation].brAmount; k++)
						{
							if (strcmp(rtISBN[j], cardList[brlocation].brList[k].brISBN) == 0 )
							{
								for (int g = 0; g < bookcounter;g++)
								if (strcmp(bookList[g].ISBN, rtISBN[j]) == 0)
								{
									bookList[g].Amount++;
										break;
								}
								cardList[brlocation].brList[k].returned = 1;
								break;
							}
						}
						printf("  -> Tra sach thanh cong ! \n");
						Sleep(500);
					}
					
					Sleep(1000);
				//	brcard--;
					break;
				}

			} while (true);
			rtcard++;
			break;
		}
		break;
	}
}
void CardMenu(){
		while (true)
		{
			system("cls");
			printf("================ MENU PHIEU THU VIEN ==============\n");
			printf("   -> 1. Lap phieu muon sach \n");
			printf("   -> 2. Lap phieu tra sach \n");
			printf("   -> 3. Xem danh sach phieu muon \n");
			printf("   -> 4. Xem danh sach phieu tra \n");
			printf("   -> 5. Xoa lich su phieu muon \n");
			printf("   -> 6. Xoa lich su phieu tra \n");
			printf("   -> 0. Thoat                \n");
			printf("===================================================\n");
			int choice;
			printf("   -> Nhap vao lua chon : ");
			scanf_s("%d", &choice);
			getchar();
			if (choice == 0) break;
			else if (choice == 1)
			{
				BorrowingInput(cardList, bookList);
				break;
			}
			else if (choice == 2)
			{
				ReturningInput(cardList);
				// EstimatedReturnTime(); no need
				break;
			}
			else if (choice == 3)
			{
				getBorrowingList(cardList); break;
			}
			else if (choice == 4)
			{
			getReturningList(cardList); break;
			}
			else if (choice == 5) {
				printf("   -> Ban co muon xoa lich su phieu muon ? (Y/N) : ");
				char answer;
				fflush(stdin);
				scanf(" %c", &answer);
				if (answer == 'y' || answer == 'Y') {
					Sleep(500);
					printf("  -> Xoa thanh cong !");
					Sleep(500);
					brcard = 0;
				}
				else if (answer == 'N' || answer == 'n'){
					Sleep(500);
					continue;
				}
			}
			else if (choice == 6){
				
				printf("   -> Ban co muon xoa lich su phieu tra ? (Y/N) : ");
				fflush(stdin);
				char answer;
				scanf(" %c", &answer);
				if (answer == 'Y' || answer	== 'y') {
					Sleep(500);
					printf("  -> Xoa thanh cong !");
					Sleep(500);
					rtcard = 0;
				}
				else if (answer	 == 'N' || answer == 'n'){
					Sleep(500);
					continue;
				}
			}
			else
			{
				printf("Lua chon khong hop le ! Vui long thu lai !\n");
				Sleep(500);
			}
		}
	}
void getReturningList(BorrowingCard cardList[]){
	system("cls");
	if (brcard == 0) printf("Khong co doc gia muon/tra sach !");
	else
	{
		printf("=================== THONG TIN TRA SACH CUA DOC GIA  ==================\n");
		printf("\n");
		for (int i = 0; i < brcard; i++)
		{
			printf("================ THONG TIN PHIEU MUON DOC GIA THU %d ================\n", i + 1);
			printf("   -> Ma so doc gia : ");
			puts(cardList[i].brID);
			printf("   -> Ten doc gia : ");
			puts(cardList[i].brName);
			printf("   -> Thoi gian muon sach gan nhat la : %d/%d/%d\n", cardList[i].timeBorrow.day, cardList[i].timeBorrow.month, cardList[i].timeBorrow.year);
			printf("   -> Thoi gian tra sach du kien : %d/%d/%d\n", EstimatedTime(cardList[i].timeBorrow).day, EstimatedTime(cardList[i].timeBorrow).month, EstimatedTime(cardList[i].timeBorrow).year);
			printf("   -> So sach da muon : %d\n", cardList[i].brAmount);
			printf("   -> DANH SACH CAC CUON SACH DA MUON :\n");
			for (int k = 0; k < cardList[i].brAmount; k++)
			{
				printf("              -> ISBN cuon sach thu %d : ", k + 1);
				puts(cardList[i].brList[k].brISBN);
				printf("              -> Ten cuon sach thu %d  : ", k + 1);
				puts(cardList[i].brList[k].brBookName);
				printf("              -> Trang thai : ");
				if (cardList[i].brList[k].returned == 0) printf("Chua tra");
				else {
					printf("Da tra\n");
					printf("       -> Thoi diem tra sach : %d/%d/%d\n", cardList[i].realReturn.day, cardList[i].realReturn.month, cardList[i].realReturn.year);
					printf("       -> So tien phat phai tra : %d\n	", PenaltyFee(cardList, cardList[i].esReturn, cardList[i].realReturn));
					printf("\n");
				}
			}
			printf("\n");
			printf("====================================================================\n");
		}
		
	}
	_getch();

	}
int buffCard(FILE* carddata, BorrowingCard &card){
	LineBuffering(carddata, card.brID, szID);
	LineBuffering(carddata, card.brName, szName);
	if (fscanf(carddata, "%d", &card.brAmount) <= 0) return 0;
	else
	{
		fscanf(carddata, "%d %d %d", &card.timeBorrow.day, &card.timeBorrow.month, &card.timeBorrow.year);
		fscanf(carddata, "%d %d %d", &card.esReturn.day, &card.esReturn.month, &card.esReturn.year);
		fscanf(carddata, "%d %d %d", &card.realReturn.day, &card.realReturn.month, &card.realReturn.year);
		fgetc(carddata);
		for (int i = 0; i < card.brAmount; i++)
		{
			LineBuffering(carddata, card.brList[i].brISBN,szISBN);
			LineBuffering(carddata, card.brList[i].brBookName,szBookName);
			fscanf(carddata, "%d", &card.brList[i].returned);
			fgetc(carddata);
		}
	}
	return 1;
}
void CardFetching(FILE* carddata, BorrowingCard cardList[], int &brcard){
	BorrowingCard card;
	brcard = 0;
	while (!feof(carddata))
	{
		if (brcard < maxCard && buffCard(carddata, card) == 1)
		{
			cardList[brcard] = card;
			brcard++;
		}
		else return;
	}
}
void cardSaveInstance(FILE* carddata, BorrowingCard cardList[], int brcard){
	for (int i = 0; i < brcard; i++)
	{
		fputs(cardList[i].brID,carddata);
		fprintf(carddata, "\n");
		fputs(cardList[i].brName, carddata);
		fprintf(carddata, "\n");
		fprintf(carddata, "%d", cardList[i].brAmount);
		fprintf(carddata, "\n");
		fprintf(carddata, "%d %d %d", cardList[i].timeBorrow.day, cardList[i].timeBorrow.month, cardList[i].timeBorrow.year);
		fprintf(carddata, "\n");
		fprintf(carddata, "%d %d %d", cardList[i].esReturn.day, cardList[i].esReturn.month, cardList[i].esReturn.year);
		fprintf(carddata, "\n");
		fprintf(carddata, "%d %d %d", cardList[i].realReturn.day, cardList[i].realReturn.month, cardList[i].realReturn.year);
		fprintf(carddata, "\n");
		for (int j = 0; j < cardList[i].brAmount; j++)
		{
			fputs(cardList[i].brList[j].brISBN, carddata);
			fprintf(carddata, "\n");
			fputs(cardList[i].brList[j].brBookName, carddata);
			fprintf(carddata, "\n");
			fprintf(carddata, "%d", cardList[i].brList[j].returned);
			fprintf(carddata, "\n");
		}
		//fprintf(carddata, "\n");
	}
}
void BorrowingInputENG(BorrowingCard cardList[], Book bookList[]){
	system("cls");
	while (true)
	{
		if (brcard >= maxCard) printf("Not enough memory to create a card !");
		else while (brcard < maxCard)
		{
			fflush(stdin); //Clear caches
			do {
				int flag = 0;
				printf("\t============ BORROWING INFORMATIONS INPUT ============\n");
				printf("\t-> Input borrower's LibID: ");
				gets_s(cardList[brcard].brID);
				for (int i = 0; i<studentcounter; i++)
				if (strcmp(studentList[i].LibID, cardList[brcard].brID) == 0)
				{
					strcpy(cardList[brcard].brName, studentList[i].Name);
					flag = 1; // already in db
					break;
				}
				if (flag == 1) break;
				else if (flag == 0) {
					printf(" -> The user you've typed is not exist in database, please try again ! \n");
					Sleep(1000);
					system("cls");
					continue;
				}
			} while (true);

			// input borrowing day	
			printf("\n");
			printf("\t=============== TIME BORROWING INPUT ========================\n");
			printf("\t  -> Input borrowing time : ");
			scanf_s("%d", &cardList[brcard].timeBorrow.day);
			printf("\t  -> Input borrowing month : ");
			scanf_s("%d", &cardList[brcard].timeBorrow.month);
			printf("\t  -> Input borrowing year : ");
			scanf_s("%d", &cardList[brcard].timeBorrow.year);
			printf("\n");
			cardList[brcard].esReturn.day = EstimatedTime(cardList[brcard].timeBorrow).day;
			cardList[brcard].esReturn.month = EstimatedTime(cardList[brcard].timeBorrow).month;
			cardList[brcard].esReturn.year = EstimatedTime(cardList[brcard].timeBorrow).year;
			printf("\t=============== BOOK BORROWING INFORMATIONS INPUT ==============\n");
			do
			{
				printf("\n");
				printf("\t  -> Input amount for borrowing : ");
				scanf_s("%d", &cardList[brcard].brAmount);
				if (cardList[brcard].brAmount > bookcounter)
				{
					printf("  -> You can't borrow more than book amount in library database !\n");
					Sleep(1000);
					continue;
				}
				else
				{
					readybook -= cardList[brcard].brAmount;
					borrowedbook += cardList[brcard].brAmount;
					//remainingbook = bookInATime[brcard];
					break;
				}
			} while (true);

			getchar();
			for (int i = 0; i < cardList[brcard].brAmount; i++) {
				fflush(stdin);
				do
				{
					int flag = 0;
					printf("\t  -> Input ISBN of book %d :  ", i + 1);
					gets_s(cardList[brcard].brList[i].brISBN);
					for (int j = 0; j < bookcounter; j++)
					{
						if (strcmp(cardList[brcard].brList[i].brISBN, bookList[j].ISBN) == 0 && bookList[j].Amount>0)
						{
							flag = 1; // already in db
							cardList[brcard].brList[i].returned = 0;
							bookList[j].Amount--;
							strcpy(cardList[brcard].brList[i].brBookName, bookList[j].BookName);
							break;
						}
					}
					if (flag == 1)
					{
						printf(" -> Added to borrowing card list ! \n");
						Sleep(1000);
						break;
					}

					else if (flag == 0)
					{
						printf(" -> Book data is not exist in database, please try again !\n");
						Sleep(1000);
						system("cls");
						continue;
					}

				} while (true);
			}
			brcard++; break;
		}
		break;
	}
}
void getBorrowingListENG(BorrowingCard cardList[]){
	system("cls");
	if (brcard == 0) printf("  -> There is no student in borrowing status now...\n");
	else
	{
		printf("  -> Total of borrowing card : %d \n\n ", brcard);
		printf("=================== LiSTING OF BORROWING CARDS  ==================\n");
		printf("\n");
		for (int i = 0; i < brcard; i++)
		{
			printf("================ INFORMATIONS OF BORROWING CARD %d ================\n", i + 1);
			printf("   -> Library ID : ");
			puts(cardList[i].brID);
			printf("   -> Name : ");
			puts(cardList[i].brName);
			printf("   -> Recently borrowed time : %d/%d/%d\n", cardList[i].timeBorrow.day, cardList[i].timeBorrow.month, cardList[i].timeBorrow.year);
			printf("   -> Estimated returning time : %d/%d/%d\n", EstimatedTime(cardList[i].timeBorrow).day, EstimatedTime(cardList[i].timeBorrow).month, EstimatedTime(cardList[i].timeBorrow).year);
			printf("   -> Amount borrowed : %d\n", cardList[i].brAmount);
			printf("   -> LISTING BOOKS BORROWED :\n");
			for (int k = 0; k < cardList[i].brAmount; k++)
			{
				printf("              -> ISBN of book %d : ", k + 1);
				puts(cardList[i].brList[k].brISBN);
				printf("              -> Name of book %d  : ", k + 1);
				puts(cardList[i].brList[k].brBookName);
				printf("              -> Returning status : ");
				if (cardList[i].brList[k].returned == 0) printf("Not return\n");
				else printf("Returned\n");
			}
			printf("\n");
			printf("====================================================================\n");
		}
		printf("===================== ATTENTION : ========================= \n");
		printf(" -> Time borrowing can be up to 7 days max.\n");
		printf(" -> If returned late than estimated time, the penalty fee are 5000VND/day.\n");
		printf(" -> If lost a book, penaty fee are up to 200 percents of book's value .\n");
		printf(" Please follow the library rule. Thanks.                        \n");
		printf("===========================================================\n");
	}
	_getch();
}
void ReturningInputENG(BorrowingCard cardList[]){
	while (true)
	{
		int brlocation;
		system("cls");
		while (true)
		{
			fflush(stdin); // clear caches
			printf("=============== RETURNING INFORMATIONS INPUT ============\n ");
			do
			{
				char returnID[szLibID];
				int flag = 0;
				printf("     -> Input returning ID : ");
				gets_s(returnID);
				for (int i = 0; i < brcard; i++)
				{
					if (strcmp(returnID, cardList[i].brID) == 0)
					{
						flag = 1; // already in db
						brlocation = i;  // point the borrower location
						break;
					}
				}
				if (flag == 1)
				{
					break;
				}
				else
				{
					printf("  -> This student isn't in borrowing list. Please try again !\n");
					Sleep(1000);
					system("cls");
					continue;
				}
			} while (true);

			printf("     -> Input real returning day : ");
			scanf_s("%d", &cardList[brlocation].realReturn.day);
			printf("     -> Input real returning month : ");
			scanf_s("%d", &cardList[brlocation].realReturn.month);
			printf("     -> Input real returning year : ");
			scanf_s("%d", &cardList[brlocation].realReturn.year);
			do
			{
				printf("\n");

				int rtbook;
				printf("     -> Input the book amount to be returned : ");
				scanf_s("%d", &rtbook);
				if (rtbook > cardList[brlocation].brAmount)
					continue;
				else if (rtbook == cardList[brlocation].brAmount) // return all books in a time
				{
					borrowedbook -= rtbook;
					readybook += rtbook;
					char rtISBN[10][szISBN];
					for (int j = 0; j < rtbook; j++)
					{
						printf("   -> Input ISBN of book %d : ", j + 1);

						fflush(stdin);
						gets_s(rtISBN[j]);
						for (int k = 0; k < cardList[brlocation].brAmount; k++)
						{
							if (strcmp(rtISBN[j], cardList[brlocation].brList[k].brISBN) == 0)
							{
								for (int g = 0; g < bookcounter; g++)
								if (strcmp(bookList[g].ISBN, rtISBN[j]) == 0)
								{
									bookList[g].Amount++;
									break;
								}
								cardList[brlocation].brList[k].returned = 1;
								break;
							}
						}
						printf("  -> Returned successfully ! \n");
						Sleep(300);
					}

					Sleep(1000);
					//	brcard--;
					break;
				}

			} while (true);
			rtcard++;
			break;
		}
		break;
	}
}
void CardMenuENG(){
	while (true)
	{
		system("cls");
		printf("================ CARD MENU ==============\n");
		printf("   -> 1. Create borrowing card \n");
		printf("   -> 2. Create returning card \n");
		printf("   -> 3. See borrowing list \n");
		printf("   -> 4. See returning list \n");
		printf("   -> 5. Clear borrowing history \n");
		printf("   -> 6. Clear returning history \n");
		printf("   -> 0. Go back                \n");
		printf("=========================================\n");
		int choice;
		printf("   -> Input your choice : ");
		scanf_s("%d", &choice);
		getchar();
		if (choice == 0) break;
		else if (choice == 1)
		{
			BorrowingInputENG(cardList, bookList);
			break;
		}
		else if (choice == 2)
		{
			ReturningInputENG(cardList);
			// EstimatedReturnTime(); no need
			break;
		}
		else if (choice == 3)
		{
			getBorrowingListENG(cardList); break;
		}
		else if (choice == 4)
		{
			getReturningListENG(cardList); break;
		}
		else if (choice == 5) {
			printf("   -> Confirm clear borrowing history ? (Y/N) : ");
			char answer;
			fflush(stdin);
			scanf(" %c", &answer);
			if (answer == 'y' || answer == 'Y') {
				Sleep(500);
				printf("  -> Cleared !");
				Sleep(500);
				brcard = 0;
			}
			else if (answer == 'N' || answer == 'n'){
				Sleep(500);
				continue;
			}
		}
		else if (choice == 6){

			printf("   -> Confirm clear returning history? (Y/N) : ");
			fflush(stdin);
			char answer;
			scanf(" %c", &answer);
			if (answer == 'Y' || answer == 'y') {
				Sleep(500);
				printf("  -> Cleared !");
				Sleep(500);
				rtcard = 0;
			}
			else if (answer == 'N' || answer == 'n'){
				Sleep(500);
				continue;
			}
		}
		else
		{
			printf("Invalid choice, please try again !\n");
			Sleep(500);
		}
	}
}
void getReturningListENG(BorrowingCard cardList[]){
	system("cls");
	if (brcard == 0) printf("There is no student who returning now. !");
	else
	{
		printf("=================== LISTING OF RETURNING CARDS ==================\n");
		printf("\n");
		for (int i = 0; i < brcard; i++)
		{
			printf("================ INFORMATIONS OF RETURNING CARD %d ================\n", i + 1);
			printf("   -> Library ID : ");
			puts(cardList[i].brID);
			printf("   -> Name : ");
			puts(cardList[i].brName);
			printf("   -> Time borrowed : %d/%d/%d\n", cardList[i].timeBorrow.day, cardList[i].timeBorrow.month, cardList[i].timeBorrow.year);
			printf("   -> Estimated returning time : %d/%d/%d\n", EstimatedTime(cardList[i].timeBorrow).day, EstimatedTime(cardList[i].timeBorrow).month, EstimatedTime(cardList[i].timeBorrow).year);
			printf("   -> Amount borrowed : %d\n", cardList[i].brAmount);
			printf("   -> LISTING BOOK BORROWED :\n");
			for (int k = 0; k < cardList[i].brAmount; k++)
			{
				printf("              -> ISBN of book %d : ", k + 1);
				puts(cardList[i].brList[k].brISBN);
				printf("              -> Name of book %d  : ", k + 1);
				puts(cardList[i].brList[k].brBookName);
				printf("              -> Returning status : ");
				if (cardList[i].brList[k].returned == 0) printf("Not return\n");
				else {
					printf("Returned\n");
					printf("       -> Real returning time : %d/%d/%d\n", cardList[i].realReturn.day, cardList[i].realReturn.month, cardList[i].realReturn.year);
					printf("       -> Penalty fee : %d\n", PenaltyFee(cardList, cardList[i].esReturn, cardList[i].realReturn));
					printf("\n");
				}
			}
			printf("\n");
			printf("====================================================================\n");
		}

	}
	_getch();

}
