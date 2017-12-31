/*
Copyright™ Hieu Hoang Minh. The Library Manager Project.
See source code on https://github.com/hyperion0201/LibraryManager2
Free for personal and commercial use under the MIT license .
2017. Ho Chi Minh University of Science.
*/
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