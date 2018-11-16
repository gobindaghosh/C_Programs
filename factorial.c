/**
* Write a program using recursion to find a factorial of  a number which is entered through Keyboard
* For Example 3 factorial is  3 * 2 * 1 = 6
*/
#include<stdio.h>
void main()
{
	int a, fact;
	int rec(int);
	printf("\nEnter Any Number: ");
	scanf("%d", &a);

	fact = rec (a);
	printf("\nFactorial Value = %d", fact);
}

int rec(x)
int x; 
{
	int f;

	if(x==1){
		return 1;
	}
	else{
		f = x * rec(x -1);
	}

	return f;
}
