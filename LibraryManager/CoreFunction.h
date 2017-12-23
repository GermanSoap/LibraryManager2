#ifndef COREFUNCTION
#define COREFUNCTION
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>
char* LineBuffering(FILE* fp, char* str, int maxSize);
void StudentDataOpening();

int fileChecking(const char* filename);
#endif //COREFUNCTION