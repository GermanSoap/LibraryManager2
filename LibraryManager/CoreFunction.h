#ifndef COREFUNCTION
#define COREFUNCTION
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>
char* LineBuffering(FILE* fp, char* str, int maxSize);
int fileChecking(const char* filename);
void TimingBreak();
#endif //COREFUNCTION