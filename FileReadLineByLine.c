//Reading a file line by line

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main(int argc, char const *argv[])
{
	FILE *fp;
	char input[100];

	fp =  fopen("afile.txt","r");

	if (fp == NULL){
		puts("\nUnable to open file...\n\n");
		exit(0);
	}

	while(fgets(input, 99, fp) != NULL){
		puts(input);
	}
	fclose(fp);
	return 0;
}