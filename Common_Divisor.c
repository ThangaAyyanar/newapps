/*

i/p:
3
10
20
30

o/p:
2

//2,5 -> common divisor for all given numbers

*/
#include<stdio.h>
int main(){
	int n,min,i,j,count=0,commonDivisor=0;
	scanf("%d",&n);
	int a[n];
	scanf("%d",&a[0]);
	min=a[0];
	for(i=1;i<n;i++){
		scanf("%d",&a[i]);
		if(min>a[i]){
			min=a[i];
		}
	}
	for(i=2;i<=min;i++){
		for(j=0;j<n;j++){
			if(a[j]%i==0){
				count++;
			}
		}
		if(count==n)
			commonDivisor++;
		count=0;
	}
	printf("%d",commonDivisor);
	return 0;
}
