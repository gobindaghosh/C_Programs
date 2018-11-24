//copying a file content into another file 
//Normal method
//Lets check it out
#include "stdio.h"
#include "stdlib.h" 

int main()
{
	FILE *fs, *ft;
	char ch;
	// opeing source file
	fs = fopen("factorial.c","r");

	if(fs == NULL){
		exit(0);
	}
	//opening target file
	ft = fopen("afile.txt", "w");

	if(ft == NULL){
		fclose(fs);
		exit(0);
	}


	while((ch = getc(fs)) != EOF){
		putc(ch,ft);
	}

	fclose(fs);
	fclose(ft);
	return 0;
}