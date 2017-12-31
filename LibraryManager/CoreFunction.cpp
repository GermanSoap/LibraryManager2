/*
Copyright™ Hieu Hoang Minh. The Library Manager Project.
See source code on https://github.com/hyperion0201/LibraryManager2
Free for personal and commercial use under the MIT license .
2017. Ho Chi Minh University of Science.
*/
#include "CoreFunction.h"

char* LineBuffering(FILE* fp, char* str, int maxSize)
{
    int ch, len;
    if (feof(fp)) return NULL;
    str[0] = 0; len = 0;
    do 
    {
        ch = fgetc(fp);
        if (ch == '\n' || ch == EOF) break;
        if (len < maxSize-1) 
        {
            str[len] = ch;
            len++;
        }
    }
    while (true);
    str[len] = 0;
    return str;
}
int fileChecking(const char* filename){
	FILE* file;
	if (file = fopen(filename, "r"))
	{
		fclose(file);
		return 1;
	}
	return 0;
}
void TimingBreak(){
	for (int i = 0; i < 3; i++)
	{
		Sleep(500);
		printf(".");
	}
	printf("\n");
}