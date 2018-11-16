/* Reading a file */
#include "stdio.h"
#include "stdlib.h"
int main()
{
	int noft=0, nol=0, nos=0, noc=0;
	FILE *fp;
	char ch;

	fp = fopen("factorial.c", "r");

	if(fp == NULL){
		printf("\n Unable to open file" );
		exit(0);
	}

	while (1){
		ch = getc(fp);

		if (ch == EOF)
		{
			break;
		}
		noc++;

		if (ch == '\n')
		{
			nol++;
		}
		if (ch == '\t')
		{
			noft++;
		}
		if (ch == ' ')
		{
			nos++;
		}
	}
	fclose(fp);

	printf("\nNumber of characters: %d", noc);
	printf("\nNumber of Tabs: %d", noft);
	printf("\nNumber of Newlines: %d", nol);
	printf("\nNumber of Spaces: %d", nos);

	return 0;
} 