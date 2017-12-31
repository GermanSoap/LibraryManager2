/*
Copyright™ Hieu Hoang Minh. The Library Manager Project.
See source code on https://github.com/hyperion0201/LibraryManager2
Free for personal and commercial use under the MIT license .
2017. Ho Chi Minh University of Science.
*/
#include "Book.h"
#include "Card.h"
#include "CoreFunction.h"
#include "Statistics.h"
#include "Student.h"
#include "MenuLists.h"
void main() {
	int locale;
	locale = LanguageSelection();
	if (locale == 1)
	{
		Sleep(500);
		printf("\n\t\t\t\t    -> Dang thiet lap ngon ngu");
		TimingBreak();
		Sleep(500);
		system("cls");
		int menuchoice, smchoice, bmchoice, statschoice;
		// Initialising components as waiting for avoiding interupt
		InitializingComponents();
		system("cls");
		while (true)
		{
			menuchoice = MainMenu();
			switch (menuchoice) // main menu choice
			{
			case 1: // student manager
			{
						while (true) // Student Menu
						{
							smchoice = StudentManagementMenu();
							if (smchoice == 0) break;
							switch (smchoice)
							{
							case 1:

							{
									  system("cls");
									  StudentListing(studentList); break;
							}
							case 2:
							{
									  system("cls");
									  StudentCreating(studentList); break;
							}
							case 3:
							{
									  system("cls");
									  fflush(stdin);
									  int location;
									  printf("  -> Nhap vao so thu tu hoc sinh can sua : ");
									  scanf_s("%d", &location);
									  ESSubMenu(location);
									  system("cls");
									  break;
							}
							case 4:
							{
									  system("cls");
									  fflush(stdin);
									  int location;
									  printf(" -> Nhap so thu tu hoc sinh can xoa : ");
									  scanf_s("%d", &location);
									  StudentDeleting(studentList, location);
									  break;
							}
							case 5:
							{
									  system("cls");
									  fflush(stdin);
									  char cmnd[szID];
									  printf("  -> Nhap CMND doc gia can tim kiem : ");

									  gets_s(cmnd);
									  FindByID(studentList, cmnd);
									  break;
							}
							case 6:
							{
									  system("cls");
									  fflush(stdin);
									  char name[szName];
									  printf("  -> Nhap ten doc gia can tim kiem : ");

									  gets_s(name);
									  FindByName(studentList, name);
									  break;
							}
							default:
							{
									   fflush(stdin);
									   printf("Lua chon khong hop le ! Vui long thu lai..\n");
									   Sleep(1000);
									   break;
							}
							}
						}
			} break;
			case 2: // book manager
			{
						while (true) // Book Menu
						{
							bmchoice = BookManagementMenu();
							if (bmchoice == 0) break;
							switch (bmchoice)
							{
							case 1:
							{
									  system("cls");
									  BookListing(bookList); break;
							}
							case 2:
							{
									  getchar();
									  system("cls");
									  BookCreating(bookList);
									  break;
							}
							case 3:
							{
									  system("cls");
									  fflush(stdin);
									  int location;
									  printf("  -> Nhap so thu tu sach can sua : ");
									  scanf_s("%d", &location);
									  EBSubMenu(location);
									  break;
							}
							case 4:
							{
									  system("cls");
									  fflush(stdin);
									  int location;
									  printf("  -> Nhap so thu tu sach can xoa : ");
									  scanf_s("%d", &location);
									  BookDeleting(bookList, location);
									  break;
							}
							case 5:
							{
									  system("cls");
									  fflush(stdin);
									  char isbn[szISBN];
									  printf(" -> Nhap ma sach(ISBN) can tim : ");
									  gets_s(isbn);
									  FindByISBN(bookList, isbn);
									  break;
							}
							case 6:
							{
									  system("cls");
									  fflush(stdin);
									  char bookname[szBookName];
									  printf(" -> Nhap vao ten sach can tim : ");
									  gets_s(bookname);
									  FindByBookName(bookList, bookname);
									  break;
							}
							default:
								break;
							}
						}
			} break;
			case 3:  // card menu
			{
						 system("cls");
						 fflush(stdin);
						 CardMenu();
						 break;
			} break;
			case 4: // statistics menu 
			{
						while (true)
						{
							statschoice = StatisticsMenu();
							if (statschoice == 0) break;
							switch (statschoice)
							{
							case 1:
							{
									  system("cls");
									  printf("\n\n");
									  printf("============ THONG KE SO SACH TRONG THU VIEN ==============\n");
									  BookRemaining(bookList);
									  break;
							}
							case 2:
							{
									  system("cls");
									  BookStatsByGenre(bookList);
									  break;
							}
							case 3:
							{
									  system("cls");
									  printf("=================== THONG KE SO LUONG DOC GIA ===================\n");
									  printf("\n");
									  printf("  -> Tong so doc gia trong thu vien la : %d", StudentStatistics());
									  _getch();
									  break;
							}
							case 4:
							{
									  system("cls");
									  StatsBasedSex(studentList);
									  break;
							}
							case 5:
							{
									  system("cls");
									  TotalBookInUse(bookList);
									  break;
							}
							case 6:
							{
									  system("cls");
									  LateStats(cardList);
									  break;
							}
							default:
								break;
							}
						}
			} break;
			case 0:
			{
					  char answer;
					  system("cls");
					  printf("   -> Ban co muon luu du lieu ? (Y de luu, N de thoat, C de quay lai) : ");
					  scanf(" %c", &answer);
					  if (answer == 'y' || answer == 'Y')
					  {
						  Sleep(500);
						  printf("   -> Dang luu du lieu");
						  TimingBreak();
						  char* NewDir = "AppData";
						  CreateDirectory(NewDir, NULL); // create directory for catch saving error
						  FILE* studentdata = fopen("./AppData/Student.txt", "wt");
						  StudentSaving(studentdata, studentList, studentcounter);
						  fclose(studentdata);
						  FILE* bookdata = fopen("./AppData/Book.txt", "wt");
						  bookSaveInstance(bookdata, bookList, bookcounter);
						  fclose(bookdata);
						  FILE* carddata = fopen("./AppData/Card.txt", "wt");
						  cardSaveInstance(carddata, cardList, brcard);
						  fclose(carddata);
						  FILE* statdata = fopen("./AppData/Stat.txt", "wt");
						  statSaveInstance(statdata);
						  fclose(statdata);
						  printf("   -> Luu du lieu thanh cong !.");
						  Sleep(500);
					  }
					  else if (answer == 'n' || answer == 'N')
						  return;
					  else if (answer == 'c' || answer == 'C')
						  continue;
			} break;
			case 5: // about author
			{
						system("cls");
						Introduction();
						break;
			} break;
			default:
			{
					   printf(" -> Lua chon khong hop le !");
					   Sleep(1000);
			}
				break;
			}
		}

	
	}
	else if (locale == 2)
	{
		Sleep(500);
		printf("\n\t\t\t\t    -> Setting language");
		TimingBreak();
		Sleep(500);
		system("cls");
		int menuchoice, smchoice, bmchoice, statschoice;
		// Initialising components as waiting for avoiding interupt
		InitializingComponentsENG();
		system("cls");
		while (true)
		{
			menuchoice = MainMenuENG();
			switch (menuchoice) // main menu choice
			{
			case 1: // student manager
			{
						while (true) // Student Menu
						{
							smchoice = StudentManagementMenuENG();
							if (smchoice == 0) break;
							switch (smchoice)
							{
							case 1:

							{
									  system("cls");
									  StudentListingENG(studentList); break;
							}
							case 2:
							{
									  system("cls");
									  StudentCreatingENG(studentList); break;
							}
							case 3:
							{
									  system("cls");
									  fflush(stdin);
									  int location;
									  printf("  -> Input the student position to edit : ");
									  scanf_s("%d", &location);
									  ESSubMenuENG(location);
									  system("cls");
									  break;
							}
							case 4:
							{
									  system("cls");
									  fflush(stdin);
									  int location;
									  printf(" -> Input student position to delete : ");
									  scanf_s("%d", &location);
									  StudentDeletingENG(studentList, location);
									  break;
							}
							case 5:
							{
									  system("cls");
									  fflush(stdin);
									  char cmnd[szID];
									  printf("  -> Input student ID to begin searching : ");

									  gets_s(cmnd);
									  FindByIDENG(studentList, cmnd);
									  break;
							}
							case 6:
							{
									  system("cls");
									  fflush(stdin);
									  char name[szName];
									  printf("  -> Input student name to begin searching : ");

									  gets_s(name);
									  FindByNameENG(studentList, name);
									  break;
							}
							default:
							{
									   printf("Invalid choice, please try again...\n");
									   Sleep(1000);
									   break;
							}
							}
						}
			} break;
			case 2: // book manager
			{
						while (true) // Book Menu
						{
							bmchoice = BookManagementMenuENG();
							if (bmchoice == 0) break;
							switch (bmchoice)
							{
							case 1:
							{
									  system("cls");
									  BookListingENG(bookList); break;
							}
							case 2:
							{
									  getchar();
									  system("cls");
									  BookCreatingENG(bookList);
									  break;
							}
							case 3:
							{
									  system("cls");
									  fflush(stdin);
									  int location;
									  printf("  -> Input book position to edit : ");
									  scanf_s("%d", &location);
									  EBSubMenuENG(location);
									  break;
							}
							case 4:
							{
									  system("cls");
									  fflush(stdin);
									  int location;
									  printf("  -> Input book position to delete : ");
									  scanf_s("%d", &location);
									  BookDeletingENG(bookList, location);
									  break;
							}
							case 5:
							{
									  system("cls");
									  fflush(stdin);
									  char isbn[szISBN];
									  printf(" -> Input ISBN to begin searching : ");
									  gets_s(isbn);
									  FindByISBNENG(bookList, isbn);
									  break;
							}
							case 6:
							{
									  system("cls");
									  fflush(stdin);
									  char bookname[szBookName];
									  printf(" -> Input book name to begin searching : ");
									  gets_s(bookname);
									  FindByBookNameENG(bookList, bookname);
									  break;
							}
							default:
								break;
							}
						}
			} break;
			case 3:  // card menu
			{
						 system("cls");
						 fflush(stdin);
						 CardMenuENG();
						 break;
			} break;
			case 4: // statistics menu 
			{
						while (true)
						{
							statschoice = StatisticsMenuENG();
							if (statschoice == 0) break;
							switch (statschoice)
							{
							case 1:
							{
									  system("cls");
									  printf("\n\n");
									  printf("============ BOOKS STATISTICS IN LIBRARY DATABASE ==============\n");
									  BookRemainingENG(bookList);
									  break;
							}
							case 2:
							{
									  system("cls");
									  BookStatsByGenreENG(bookList);
									  break;
							}
							case 3:
							{
									  system("cls");
									  printf("=================== STUDENT STATISTICS IN LIBRARY ===================\n");
									  printf("\n");
									  printf("  -> Total student in library database : %d", StudentStatistics());
									  _getch();
									  break;
							}
							case 4:
							{
									  system("cls");
									  StatsBasedSexENG(studentList);
									  break;
							}
							case 5:
							{
									  system("cls");
									  TotalBookInUseENG(bookList);
									  break;
							}
							case 6:
							{
									  system("cls");
									  LateStatsENG(cardList);
									  break;
							}
							default:
								break;
							}
						}
			} break;
			case 0:
			{
					  char answer;
					  system("cls");
					  printf("   -> Do you want to save data ? (Y for Yes, N for No, C for Cancel) : ");
					  scanf(" %c", &answer);
					  if (answer == 'y' || answer == 'Y')
					  {
						  Sleep(500);
						  printf("   -> Saving data");
						  TimingBreak();
						  char* NewDir = "AppData";
						  CreateDirectory(NewDir, NULL); // create directory for catch saving error
						  FILE* studentdata = fopen("./AppData/Student.txt", "wt");
						  StudentSaving(studentdata, studentList, studentcounter);
						  fclose(studentdata);
						  FILE* bookdata = fopen("./AppData/Book.txt", "wt");
						  bookSaveInstance(bookdata, bookList, bookcounter);
						  fclose(bookdata);
						  FILE* carddata = fopen("./AppData/Card.txt", "wt");
						  cardSaveInstance(carddata, cardList, brcard);
						  fclose(carddata);
						  FILE* statdata = fopen("./AppData/Stat.txt", "wt");
						  statSaveInstance(statdata);
						  fclose(statdata);
						  printf("   -> Successfully saved data to directory : ./AppData/ ! Check it.");
						  Sleep(500);
					  }
					  else if (answer == 'n' || answer == 'N')
						  return;
					  else if (answer == 'c' || answer == 'C')
						  continue;
			} break;
			case 5: // about author
			{
						system("cls");
						IntroductionENG();
						break;
			} break;
			default:
			{
					   fflush(stdin);
					   printf(" -> Invalid choice !");
					   Sleep(1000);
			}
				break;
			}
		}
	}
	_getch();
}