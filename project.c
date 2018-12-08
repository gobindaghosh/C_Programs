 //A menu driven project in C
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void main(){

	FILE *fp, *ft;
	char another, choice;

	struct emp{
		char name[40];
		int age;
		float bs;
	};//End of Structure

	struct emp e;
	char empname[40];

	fp = fopen("EMP.DAT", "rb+");
		
	if (fp  == NULL){ // Chacking if the file EMP.DAT already exists or not 

		fp = fopen("EMP.DAT","wb+"); // File does not exists, hence opening EMP.DAT in write mode for first time

		if(fp == NULL){
			puts("Can't Open File.");
			exit(0);
		}//End of inner IF
	}//End of first IF 
	 

	while(1){

		printf("\n\n1. Add Record.");
		printf("\n2. List Record.");
		printf("\n3. Modify Record.");
		printf("\n4. Delete Record.");
		printf("\n0. Exit.");
		printf("\n\nYour Choice (0 to 4):- ");

		fflush(stdin); // Add this here

		choice = getchar(); // use getchar() instead of getche(). to Get the user input, from keyboard

		switch(choice){

			case '1': // New Data Entry
				fseek(fp, 0, SEEK_END); // Move the file pointer in the end of the file 
				another = 'Y';

				while(another == 'Y' || another == 'y'){
					printf("\nEnter name, age and basic salary:-");
					scanf("%s %d %f", &e.name, &e.age, &e.bs);

					fwrite(&e, sizeof(e), 1, fp);

					printf("\nAdd Another Record?  (y/n):");
					fflush(stdin);
					another = getchar(); // Use this insted of getche()
				}//End while of case 1

				break;

			case '2':

				rewind(fp);

				while(fread(&e, sizeof(e),1, fp) == 1){
					printf("\nName: %s Age: %d and Basic: %.2f", e.name, e.age, e.bs );
				}//End while of Case 2

				break;



			case '3': // Modification of Record

				another = 'Y';

				while(another == 'Y' || another == 'y'){

					printf("\nEnter the name of the Employee to modify: ");
					scanf("%s", empname);

					rewind(fp);

					while(fread(&e, sizeof(e), 1, fp) == 1){// Reading all record one by one

						if (strcmp(e.name, empname) == 0) // 0 when both strings are equal
						{
							printf("\nEnter new name, age and salary:-");
							scanf("%s %d %f", &e.name, &e.age, &e.bs);

							fseek(fp, -sizeof(e), SEEK_CUR);
							fwrite(&e, sizeof(e), 1, fp);

							break; // fread while loop break
						}

					}// End of fread while

					printf("\nModify another record? (y/n):- ");
					fflush(stdin);
					another = getchar(); // use instead of getche() or getch();

				}// End while of Case 3
				break; // Break of case 2

			case '4':

				another = 'Y';

				while(another == 'Y' || another == 'y'){

					printf("\nEnter the name of the Employee to delete:- ");
					scanf("%s", &empname);

					ft = fopen("TEMP.DAT", "wb"); // Opening Temporary file to copy Data 

					rewind(fp);

					while(fread(&e, sizeof(e), 1, fp) == 1){
						if(strcmp(e.name, empname) != 0){
							// IF employee name given, does not match copy the data in TEMP.DAT file
							fwrite(&e, sizeof(e), 1, ft); //** note it it ft not fp
						}//End if
					}// End of fread while

					fclose(fp);
					fclose(ft);

					remove("EMP.DAT");
					rename("TEMP.DAT", "EMP.DAT");

					fp = fopen("EMP.DAT", "rb+");

					printf("\nDelete another record? (y/n): -");
					fflush(stdin);
					another = getchar();

				}//End While of case 4
				break; //Break of case 4
				

			case '0': //Exit Code
				fclose(fp);
				exit(0);
		}//End of Switch

	}// End of While (1), the most outer and the first while in this program

}//End of main()