#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"parsexec.h"
static char input[100];
static int getInput(void)
{
	printf("\n--> ");
	return fgets(input, sizeof input, stdin)!=NULL;//stdinÊÇÊäÈëµÄ×Ö·û´®
}

int main()
{
	printf("Welcome to Little Cave Adventure.\n");
	printf("It is very dark in here.\n");
	while (parseAndExecute(input) && getInput());
	printf("\nBye!\n");
	return 0;
}
