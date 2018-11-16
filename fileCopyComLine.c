//copying a file content into another from ccommand line 
#include "stdio.h"
#include "stdlib.h" 

int main(int argc, char const *argv[])
{
	FILE *fs, *ft;
	char ch;
	//Count the number of arguments

	if(argc != 3){
		
		puts("\nLess argumets given");
		exit(0);
	}

	// opeing source file
	fs = fopen(argv[1],"r");

	if(fs == NULL){
		exit(0);
	}
	//opening target file
	ft = fopen(argv[2], "w");

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