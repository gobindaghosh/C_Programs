/**
* A five digit positive integer is entered through keybord, write a recursive function to  calculate
* the sum of digits of the 5 digits number
*/
#include <stdio.h>
 int main()
 {
 	int num, sum =0, intSize = 5;
 	int sumOfDigits(int);
 	printf("\nEnter any five digits nos: ");
 	scanf("%d",&num);

 	sum =  sumOfDigits(num);

 	printf("\n The sum of digits is = %d", sum);
 }

 int sumOfDigits(n)
 int n;
 {
 	static int s;

 	if (n <= 0)
 	{
 		return 0;
 	}
 	else
 	{
  		s = s + (n % 10); //eg 12345 will come out as 5, 4, 3, 2 and 1
  		//printf(" %d", (n / 10));
  		sumOfDigits(n / 10); // eg 12345 will become 1234, 123, 12, 1 and 0  accordingly
 	}
 	return s;
 }