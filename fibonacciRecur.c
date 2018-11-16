/**
*  Write a recursive function to obtain first 11 numbers of fibonacci sequence
* in Fibonacci sequence the sum of two successive terms gives the third term 
* for example 1 1 2 3 5 8 13 21 34 55 89 .....
*/
#include "stdio.h"
void main()
{
	int nos = 1;
	int fiboRec(int);
	printf("1 ");
	fiboRec(nos);

}

int fiboRec(n)
int n;
{
	static int first = 1; static int last = 0;

	int s=0;
	if(n > 10){
		return 1;
	}
	else{
		
		if (n == 1){
			s = first + last; 
			last = s; 
			printf("%d ", s);
			fiboRec(n + 1);
		}
		else{
			s = first + last; 
			first = last;
			last = s; 
			printf("%d ", s);
			fiboRec(n + 1);
		}
		
	}
	return 1; 
}