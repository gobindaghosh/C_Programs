//Writing to a file line by line

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main(int argc, char const *argv[])
{
	FILE *fp;
	char input[100];
I 
	fp = fopen("afile.txt","w");
	if (fp == NULL)
	{
		exit(0);
	}

	puts("Insert some text lines....\n");

	while(strlen(gets(input)) > 0 ) {
		fputs(input,fp);
		fputs("\n", fp);
	}

	fclose(fp);
	return 0;
}
