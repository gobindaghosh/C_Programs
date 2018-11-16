/**
* A five digit positive integer is entered through keybord, write a function to  calculate
* the sum of digits of the 5 digits number
*/
#include <stdio.h>
 int main()
 {
 	int num, sum =0;
 	int sumOfDigits(int);
 	printf("\nEnter and five digits nos: ");
 	scanf("%d",&num);

 	sum =  sumOfDigits(num);

 	printf("\n The sum of digits is = %d", sum);
 }

 int sumOfDigits(int n)
 {
 		int s = 0;
 		while (n > 0)
 		{
 			s = s + (n % 10);
 			n = n / 10 ;
 			
 		}

 		return s;
 }