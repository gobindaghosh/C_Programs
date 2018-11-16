/**
*  Write a program to obtain first 11 numbers of fibonacci sequence
*/
#include<stdio.h>
void main(){
	int n, i, first=1;
	int sum, last =0 ;
	printf("%d ", first);
	for(i=1; i<=10;i++){
		if(i == 1){
			sum = first + last;
			printf("%d ", sum);
			last = sum;
		}
		else{
			sum = first + last;
			printf("%d ", sum);
			first = last; 
			last = sum;
		}
		
	}

}