/*

i/p:
4

o/p:
5

1,1,1,1
2,1,1
1,2,1
1,1,2
2,2

pay using 1's and 2's

*/
//concept is simple using fibonacci sequence
#include<stdio.h>
int main(){
	int n,i;
	long long unsigned int f1=1,f2=1,f3=1;
	scanf("%d",&n);
	for(i=1;i<n;i++){
		f3=f1+f2;
		f1=f2;
		f2=f3;
	}
	printf("%lld",f3);
	return 0;
}
