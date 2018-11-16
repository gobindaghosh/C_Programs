/**
* print 1 to 5 using recusion
*/
#include<stdio.h>
void main(){
	int recurs();
	recurs();
}

int recurs()
{
	static int i=1;
	if(i > 5){
		return 0;
	}
	else{
		printf("%d ", i);
		recurs(i++);
	}
	return 0;
}