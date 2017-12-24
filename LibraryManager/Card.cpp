#include "Card.h"
#include "Book.h"
#include "Student.h"
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
						if (strcmp(cardList[brcard].brList[j].brISBN, bookList[j].ISBN) == 0 && bookList[j].Amount>0)
						{
							flag = 1; // already in db
							cardList[brcard].brList[j].returned = false;
							bookList[j].Amount--;
							strcpy(cardList[brcard].brList[j].brBookName, bookList[j].BookName);
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
						getchar();
						gets_s(rtISBN[j]);
						for (int k = 0; k < bookcounter; k++)
						if (strcmp(rtISBN[j], bookList[k].ISBN) == 0)
						{
							bookList[k].Amount++;
							cardList[brlocation].brList[j].returned = true;
						}

					}
					printf("  -> Tra sach thanh cong ! \n");
					Sleep(1000);
				//	brcard--;
					rtcard++;
					break;
				}

			} while (true);
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
			else
			{
				printf("Lua chon khong hop le ! Vui long thu lai !\n");
				Sleep(500);
			}
		}
	}
void getReturningList(BorrowingCard cardList[]){
	system("cls");
	if (rtcard == 0) printf("  -> Hien tai khong co doc gia nao tra sach !\n");
	else
	{
		for (int i = 0; i < rtcard;i++)
		if (cardList[i].realReturn.day >= 0) // check real return day for filtered return list from borrow list
		{
			int flag = 0;
			printf("================== THONG TIN PHIEU TRA SACH =================\n");
			printf("\n");
			printf("   -> Ma so doc gia : ");
			puts(cardList[i].brID);
			printf("   -> Ten doc gia : ");
			puts(cardList[i].brName);
			printf("   -> Thoi diem muon sach : %d/%d/%d\n", cardList[i].timeBorrow.day, cardList[i].timeBorrow.month, cardList[i].timeBorrow.year);
			printf("   -> Thoi diem tra sach du kien : %d/%d/%d\n", cardList[i].esReturn.day, cardList[i].esReturn.month, cardList[i].esReturn.year);
			printf("   -> Thoi diem tra sach thuc te : %d/%d/%d\n", cardList[i].realReturn.day, cardList[i].realReturn.month, cardList[i].realReturn.year);
			printf("   -> Tong so cuon sach da muon : %d\n", cardList[i].brAmount);
			printf("   -> Danh sach cac sach da muon : \n");
			for (int j = 0; j < cardList[i].brAmount; j++)
			{
				printf("     -> ISBN Cuon sach thu %d : ", j + 1);
				puts(cardList[i].brList[j].brISBN);
				printf("     -> Ten cuon sach thu %d : ", j + 1);
				puts(cardList[i].brList[j].brBookName);
				printf("     -> Trang thai (tra hay chua) : ");
				if (cardList[i].brList[j].returned == true) printf(" Da tra\n");
				else printf(" Chua tra\n");

			}
			printf("   -> So tien phat phai tra : %d VND \n", PenaltyFee(cardList, cardList[i].esReturn, cardList[i].realReturn));
			printf("=========================================================\n");
			flag = 1; break;
		}
	}
	_getch();
}
