#include "CoreFunction.h"
#include "Student.h"

int buffStudent(FILE* studentdata, Student &student){
    int d, m, y;
	int dx, mx, yx;
	
    LineBuffering(studentdata, student.LibID, szLibID);
    LineBuffering(studentdata, student.Name, szName);
    LineBuffering(studentdata, student.ID, szID);
    LineBuffering(studentdata, student.Birth, szBirth);
    LineBuffering(studentdata, student.Sex, szSex);
    LineBuffering(studentdata, student.Email, szEmail);
    LineBuffering(studentdata, student.Address, szAddress);
   if ( fscanf(studentdata, "%d %d %d %d %d %d", &d, &m, &y, &dx, &mx, &yx) <=0) return 0;
    fgetc(studentdata);
	// buffering timeCreate
	student.timeCreate.day = d;
	student.timeCreate.month = m;
	student.timeCreate.year = y;
	// automatically caculating expired time
	student.timeExpired.day = dx;
	student.timeExpired.month = mx;
	student.timeExpired.year = yx;
	
    return 1;
}
void StudentFetching(FILE* studentdata, Student studentList[], int &studentcounter){
    Student student; 
	studentcounter = 0;
    while (!feof(studentdata))
    {
		if (studentcounter < maxStudent && buffStudent(studentdata, student))
		{
			studentList[studentcounter] = student;
			studentcounter++;
		}
		else return;
    }
}
void StudentEditing(Student studentList[],int number){
	while (true)
	{
		if (number> 0 && number <= studentcounter)
		{
			int choice;
			printf("================ MENU CHINH SUA DOC GIA ===============\n");
			printf("  -> 1. Chinh sua Ma thu vien                          \n");
			printf("  -> 2. Chinh sua ten doc gia                          \n");
			printf("  -> 3. Chinh sua CMND cua doc gia                     \n");
			printf("  -> 4. Chinh sua ngay thang nam sinh cua doc gia      \n");
			printf("  -> 5. Chinh sua gioi tinh                            \n");
			printf("  -> 6. Chinh sua email                                \n");
			printf("  -> 7. Chinh sua dia chi                              \n");
			printf("  -> 8. Chinh sua thoi gian tao the thu vien           \n");
			printf("  -> 0. Huy bo chinh sua                               \n");
			printf("=======================================================\n");
			printf("   Nhap lua chon cua ban : ");
			scanf_s("%d", &choice);
			if (choice == 0) break;
			switch (choice)
			{
			case 8: {
						system("cls");
						fflush(stdin);
						int dayedit, monthedit, yearedit;
						printf("============ NOI DUNG CHINH SUA =============\n");
						printf(" -> Nhap ngay muon sua : ");
						scanf_s("%d", &dayedit);
						printf(" -> Nhap thang muon sua : ");
						scanf_s("%d", &monthedit);
						printf(" -> Nhap nam muon sua : ");
						scanf_s("%d", &yearedit);
						studentList[number - 1].timeCreate.day = dayedit;
						studentList[number - 1].timeCreate.month = monthedit;
						studentList[number - 1].timeCreate.year = yearedit;
						// changing timeExpired
						studentList[number - 1].timeExpired.day = dayedit;
						studentList[number - 1].timeExpired.month = monthedit;
						studentList[number - 1].timeExpired.year = yearedit + 4;

			} break;
			case 1: {
						getchar();
						fflush(stdin);
						char LibIDNew[25];
						printf("Nhap vao ma thu vien moi : ");
						gets_s(LibIDNew);
						strcpy(studentList[number - 1].LibID, LibIDNew);
						Sleep(1000);
						printf("Chinh sua thanh cong !");
						Sleep(500);
			} break;
			case 2: {
						getchar();
						fflush(stdin);
						char NewName[25];
						printf("Nhap vao ten moi : ");
						gets_s(NewName);
						strcpy(studentList[number - 1].Name, NewName);
						Sleep(1000);
						printf("Chinh sua thanh cong !");
						Sleep(500);
			} break;
			case 3: {
						getchar();
						fflush(stdin);
						char NewID[25];
						printf("Nhap vao CMND moi : ");
						gets_s(NewID);
						strcpy(studentList[number - 1].ID, NewID);
						Sleep(1000);
						printf("Chinh sua thanh cong !");
						Sleep(500);
			} break;
			case 4: {
						getchar();
						fflush(stdin);
						char NewBirth[25];
						printf("Nhap vao ngay thang nam sinh moi : ");
						gets_s(NewBirth);
						strcpy(studentList[number - 1].Birth, NewBirth);
						Sleep(1000);
						printf("Chinh sua thanh cong !");
						Sleep(500);
			} break;
			case 5: {
						getchar();
						fflush(stdin);
						char NewSex[25];
						printf("Nhap vao gioi tinh moi : ");
						gets_s(NewSex);
						strcpy(studentList[number - 1].Sex, NewSex);
						Sleep(1000);
						printf("Chinh sua thanh cong !");
						Sleep(500);
			} break;
			case 6: {
						getchar();
						fflush(stdin);
						char NewEmail[25];
						printf("Nhap email moi : ");
						gets_s(NewEmail);
						strcpy(studentList[number - 1].Email, NewEmail);
						Sleep(1000);
						printf("Chinh sua thanh cong !");
						Sleep(500);
			} break;
			case 7: {
						getchar();
						fflush(stdin);
						char NewAddress[50];
						printf("Nhap dia chi moi : ");
						gets_s(NewAddress);
						strcpy(studentList[number - 1].Address, NewAddress);
						Sleep(1000);
						printf("Chinh sua thanh cong !");
						Sleep(500);
			} break;
			default:
			{
					   printf("Chuc nang ban nhap khong hop le! Vui long kiem tra lai.");
					   Sleep(1000);
					   break;
			}
			}
			system("cls");
		}
		else
		{
			printf("Du lieu hoc sinh khong ton tai hoac khong trung khop ! Vui long thoat ra va chon lai..\n");
			_getch();
			Sleep(1000);
		}
		break;
	}
}
void StudentDeclaration(Student studentList[]){
	while (true) {
		if (studentcounter >= maxStudent) printf("Khong du bo nho de tao hoac cap nhat doc gia !");
		else
		while (studentcounter < maxStudent)
		{
			printf(" ================= THONG TIN DOC GIA THU %d ===================\n", studentcounter + 1);
			// Clear the caches
			// Input the informations
			printf("  -> Ma so doc gia thu %d : ", studentcounter + 1);
			gets(studentList[studentcounter].LibID);
			printf("  -> Ten doc gia thu %d : ", studentcounter + 1);
			gets(studentList[studentcounter].Name);
			printf("  -> CMND doc gia thu %d : ", studentcounter + 1);
			gets(studentList[studentcounter].ID);
			printf("  -> Ngay thang nam sinh doc gia thu %d : ", studentcounter + 1);
			gets(studentList[studentcounter].Birth);
			printf("  -> Gioi tinh doc gia thu %d (Nam hoac Nu) : ", studentcounter + 1);
			gets(studentList[studentcounter].Sex);
			printf("  -> Email doc gia thu %d : ", studentcounter + 1);
			gets(studentList[studentcounter].Email);
			printf("  -> Dia chi doc gia thu %d (luu y khong dung dau cham hay dau phay) : ", studentcounter + 1);
			gets(studentList[studentcounter].Address);
			//Library card creating
			printf("  -> Nhap vao thoi gian lam the thu vien : \n");
			DayCreating();
			// Automatic evaluate expired time
			DayExpired();
			studentcounter++; break;
		}
		if (studentcounter >= 1) break;
	}
}

/* Starting EditStudent SubMenu
Input : ESSubMenu		 choice
Output: choice
*/
void ESSubMenu(int number) {
	//system("cls");
	int choice;
	while (true)
	{
		if (number > 0 && number <= maxStudent)
		{
			system("cls");
			printf("\n");
			printf("=================== TUY CHON CHINH SUA DOC GIA ==================\n");
			printf("           1. Tiep tuc chinh sua doc gia thu %d                  \n", number);
			printf("           2. Xem thong tin da chinh sua cua doc gia thu %d      \n", number);
			printf("           3. Thoat chinh sua                                    \n");
			printf("=================================================================\n");
			printf("    Nhap vao lua chon cua ban : ");
			scanf_s("%d", &choice);
			if (choice == 3) break;
			switch (choice)
			{
			case 1: StudentEditing(studentList,number); break;
			case 2: SeeLocalChanges(studentList, number); break;
			default: printf("Chuc nang ban nhap vao khong hop le ! \n");
				break;
			}
		}
		else
		{
			printf("Du lieu hoc sinh khong ton tai trong thu vien ! Vui long thu lai ..\n");
			Sleep(1000);
			break;
		}
	}
	//_getch();
}
void SeeLocalChanges(Student studentList[], int number){
	printf("\n");
	printf("============== THONG TIN DOC GIA THU %d SAU KHI CHINH SUA =============\n", number);
	printf("\n");
	printf(" -> Ma thu vien la : ");
	puts(studentList[number - 1].LibID);
	printf(" -> Ten cua doc gia : ");
	puts(studentList[number - 1].Name);
	printf(" -> So CMND : ");
	puts(studentList[number - 1].ID);
	printf(" -> Ngay thang nam sinh : ");
	puts(studentList[number - 1].Birth);
	printf(" -> Gioi tinh : ");
	puts(studentList[number - 1].Sex);
	printf(" -> Email : ");
	puts(studentList[number - 1].Email);
	printf(" -> Dia chi : ");
	puts(studentList[number - 1].Address);
	printf(" -> Thoi gian lam the thu vien : %d/%d/%d\n", studentList[number - 1].timeCreate.day, studentList[number - 1].timeCreate.month, studentList[number - 1].timeCreate.year);
	printf(" -> Ngay het han  : %d/%d/%d\n", studentList[number - 1].timeExpired.day, studentList[number - 1].timeExpired.month, studentList[number - 1].timeExpired.year);
	Sleep(1000);
	_getch();
}
void StudentCreating(Student studentList[]){
	while (true)
	{
		system("cls");
		fflush(stdin);
		int choice;
		printf("===================== MENU TAO DOC GIA ========================\n");
		printf("                 -> 1. Tao doc gia moi                         \n");
		printf("                 -> 2. Thoat                                   \n");
		printf("===============================================================\n");
		printf("      -> Nhap vao lua chon cua ban : ");
		scanf_s("%d", &choice);
		if (choice == 1)
		{
			if (studentcounter > maxStudent) printf("Khong du bo nho de tao hoac cap nhat doc gia !");
			else
			{
				printf(" ============== THONG TIN DOC GIA THU  %d =============\n", studentcounter + 1);
				fflush(stdin);
				// Clear the caches
				// Input the informations
				printf("  -> Ma so doc gia thu %d : ", studentcounter + 1);
				gets(studentList[studentcounter].LibID);
				printf("  -> Ten doc gia thu %d : ", studentcounter + 1);
				gets(studentList[studentcounter].Name);
				printf("  -> CMND doc gia thu %d : ", studentcounter + 1);
				gets(studentList[studentcounter].ID);
				printf("  -> Ngay thang nam sinh doc gia thu %d : ", studentcounter + 1);
				gets_s(studentList[studentcounter].Birth);
				printf("  -> Gioi tinh doc gia thu %d : ", studentcounter + 1);
				gets_s(studentList[studentcounter].Sex);
				printf("  -> Email doc gia thu %d : ", studentcounter + 1);
				gets_s(studentList[studentcounter].Email);
				printf("  -> Dia chi doc gia thu %d (luu y khong dung dau cham hay dau phay) : ", studentcounter + 1);
				gets_s(studentList[studentcounter].Address);
				//Library card creating
				printf("  -> Nhap vao thoi gian lam the thu vien : \n");
				DayCreating();
				// Automatic evaluate expired time
				DayExpired();
				studentcounter++;
				Sleep(1000);
				printf("Tao doc gia moi thanh cong !");
				Sleep(500);
				break;
			}
			//	continue;
		}
		else if (choice == 2) break;
		else
		{
			printf("Lua chon khong phu hop ! Vui long thu lai !");
			Sleep(1000);
			continue;
		}
	}
}
void DayCreating(){
	printf("\n");
	printf("  -> Nhap ngay lap the : ");
	scanf("%d", &studentList[studentcounter].timeCreate.day);
	printf("  -> Nhap thang lap the : ");
	scanf("%d", &studentList[studentcounter].timeCreate.month);
	printf("  -> Nhap nam lap the : ");
	scanf("%d", &studentList[studentcounter].timeCreate.year);
}
void DayExpired(){
	studentList[studentcounter].timeExpired.day = studentList[studentcounter].timeCreate.day;
	studentList[studentcounter].timeExpired.month = studentList[studentcounter].timeCreate.month;
	studentList[studentcounter].timeExpired.year = studentList[studentcounter].timeCreate.year + 4;
}
void StudentListing(Student studentList[]){
	printf("\t\t================ DANH SACH CAC DOC GIA THU VIEN ================\n\n");
	if (studentcounter <= 0) printf("Hien tai chua co hoc sinh nao trong du lieu thu vien. Vui long cap nhat hoac them doc gia !\n");
	else {
		for (int i = 0; i < studentcounter; i++) {
			printf("=============== THONG TIN DOC GIA THU %d ============= \n", i + 1);
			printf("\n");
			printf(" -> Ma thu vien la : ");
			puts(studentList[i].LibID);
			printf(" -> Ten cua doc gia : ");
			puts(studentList[i].Name);
			printf(" -> So CMND : ");
			puts(studentList[i].ID);
			printf(" -> Ngay thang nam sinh : ");
			puts(studentList[i].Birth);
			printf(" -> Gioi tinh : ");
			puts(studentList[i].Sex);
			printf(" -> Email : ");
			puts(studentList[i].Email);
			printf(" -> Dia chi : ");
			puts(studentList[i].Address);
			printf(" -> Thoi gian lam the thu vien : %d/%d/%d\n", studentList[i].timeCreate.day, studentList[i].timeCreate.month, studentList[i].timeCreate.year);
			printf(" -> Ngay het han  : %d/%d/%d\n", studentList[i].timeExpired.day, studentList[i].timeExpired.month, studentList[i].timeExpired.year);
			printf("\n");
		}
	}
	_getch();
}
void StudentDeleting(Student studentList[],int number){
	int flag = 0;
	if (number > 0 && number <= studentcounter)
	{
		char answer;
		fflush(stdin);
		printf("  -> Ban co chac chan muon xoa hay khong ? (Y) de xoa, (N) de huy bo. : ");
		answer = getchar();
		if (answer == 'y' || answer == 'Y')
		{
			for (int i = number - 1; i < studentcounter - 1; i++)
			{
				strcpy(studentList[i].LibID, studentList[i + 1].LibID);
				strcpy(studentList[i].Name, studentList[i + 1].Name);
				strcpy(studentList[i].ID, studentList[i + 1].ID);
				strcpy(studentList[i].Birth, studentList[i + 1].Birth);
				strcpy(studentList[i].Sex, studentList[i + 1].Sex);
				strcpy(studentList[i].Email, studentList[i + 1].Email);
				strcpy(studentList[i].Address, studentList[i + 1].Address);
				//Timing library card
				studentList[i].timeCreate.day = studentList[i + 1].timeCreate.day;
				studentList[i].timeCreate.month = studentList[i + 1].timeCreate.month;
				studentList[i].timeCreate.year = studentList[i + 1].timeCreate.year;
				// Timing expired card
				studentList[i].timeExpired.day = studentList[i + 1].timeExpired.day;
				studentList[i].timeExpired.month = studentList[i + 1].timeExpired.month;
				studentList[i].timeExpired.year = studentList[i + 1].timeExpired.year;
			}
			studentcounter--; flag = 1;
		}
		else if (answer == 'n' || answer == 'N') return;
	}
	if (flag == 1) {
		printf("Xoa thanh cong !\n");
		printf("\n");
		Sleep(1000);
		StudentListing(studentList);
	}
	else
	{
		printf("Co loi khi xoa, vui long thu lai..");
		Sleep(1000);
	}
}
void FindByName(Student studentList[], char name[szName]){
	int flag = 0;
	printf("================ KET QUA TIM KIEM ==================\n");
	for (int i = 0; i < studentcounter; i++) {
		printf("\n");
		if (strcmp(name, studentList[i].Name) == 0) {
			printf("   -> Ma doc gia : ");
			puts(studentList[i].LibID);
			printf("   -> Ten doc gia : ");
			puts(studentList[i].Name);
			printf("   -> CMND doc gia : ");
			puts(studentList[i].ID);
			printf("   -> Ngay thang nam sinh : ");
			puts(studentList[i].Birth);
			printf("   -> Gioi tinh : ");
			puts(studentList[i].Sex);
			printf("   -> Email : ");
			puts(studentList[i].Email);
			printf("   -> Dia chi : ");
			puts(studentList[i].Address);
			printf("   -> Thoi gian lap the thu vien : %d/%d/%d\n", studentList[i].timeCreate.day, studentList[i].timeCreate.month, studentList[i].timeCreate.year);
			printf("   -> Ngay het han : %d/%d/%d\n", studentList[i].timeExpired.day, studentList[i].timeExpired.month, studentList[i].timeExpired.year);
			printf("====================================================\n");
			flag++;
		}
	}
	if (flag == 0) printf("Khong tim thay ket qua !");
	else
	{
		printf("\n");
		printf("   - > Tong cong co %d hoc sinh duoc tim thay.\n", flag);
	}
	_getch();
}
void FindByID(Student studentList[], char id[szID]){
	int flag = 0;
	printf("================ KET QUA TIM KIEM ==================\n");
	for (int i = 0; i < studentcounter; i++) {
		printf("\n");
		if (strcmp(id, studentList[i].ID) == 0) {
			printf("   -> Ma doc gia : ");
			puts(studentList[i].LibID);
			printf("   -> Ten doc gia : ");
			puts(studentList[i].Name);
			printf("   -> CMND doc gia : ");
			puts(studentList[i].ID);
			printf("   -> Ngay thang nam sinh : ");
			puts(studentList[i].Birth);
			printf("   -> Gioi tinh : ");
			puts(studentList[i].Sex);
			printf("   -> Email : ");
			puts(studentList[i].Email);
			printf("   -> Dia chi : ");
			puts(studentList[i].Address);
			printf("   -> Thoi gian lap the thu vien : %d/%d/%d\n", studentList[i].timeCreate.day, studentList[i].timeCreate.month, studentList[i].timeCreate.year);
			printf("   -> Ngay het han : %d/%d/%d\n", studentList[i].timeExpired.day, studentList[i].timeExpired.month, studentList[i].timeExpired.year);
			printf("====================================================\n");
			flag++;
		}
	}
	if (flag == 0) printf("Khong tim thay ket qua !");
	else
	{
		printf("\n");
		printf("   - > Tong cong co %d hoc sinh duoc tim thay.\n", flag);
	}
	_getch();
}
void StudentSaving(FILE* studentdata, Student studentList[], int studentcounter){
	for (int i = 0; i < studentcounter; i++)
	{
		fputs(studentList[i].LibID, studentdata);
		fprintf(studentdata, "\n");
		fputs(studentList[i].Name, studentdata);
		fprintf(studentdata, "\n");
		fputs(studentList[i].ID, studentdata);
		fprintf(studentdata, "\n");
		fputs(studentList[i].Birth, studentdata);
		fprintf(studentdata, "\n");
		fputs(studentList[i].Sex, studentdata);
		fprintf(studentdata, "\n");
		fputs(studentList[i].Email, studentdata);
		fprintf(studentdata, "\n");	
		fputs(studentList[i].Address, studentdata);
		fprintf(studentdata, "\n");
		fprintf(studentdata, "%d %d %d %d %d %d", studentList[i].timeCreate.day, studentList[i].timeCreate.month, studentList[i].timeCreate.year, studentList[i].timeExpired.day, studentList[i].timeExpired.month, studentList[i].timeExpired.year);
		fprintf(studentdata, "\n");
	}
}