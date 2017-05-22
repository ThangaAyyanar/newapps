//count no of 1's in binary sequence of given integer
#include<stdio.h>
int bincnt(int n){
	if(n==0)
		return 0;
	else if(n==1)
		return 1;
	else
		return bincnt(n/2)+bincnt(n%2);
}
int main(){
	int num;
	scanf("%d",&num);
	printf("No of one is %d",bincnt(num));
	return 0;
}
