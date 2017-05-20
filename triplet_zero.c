#include<stdio.h>
#include<stdlib.h>
void sort(int *a,int n){
	int temp,i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(a[i]<a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
int main(){
	int n=1,*a=(int *)malloc(n*sizeof(int)),i,l,r,flag=1,current;
	char ch;
	for(i=0;;i++){
		if(scanf("%d%c",&a[i],&ch)==2){
			if(ch=='\n')
				break;
			else
				n++;
		}
	}
	sort(a,n);
	for(i=0;i<n-2;i++){
		if(current==a[i])
			continue;
		else
			current=a[i];
		l=i+1;
		r=n-1;
		while(l<r){
			if(current+a[l]+a[r]==0){
				printf("%d %d %d\n",current,a[l],a[r]);
				l++;
				r--;
				flag=0;
			}else if(current+a[l]+a[r]<0)
				l++;
			else
				r--;
		}
	}
	if(flag)
		printf("No triplet found");
	return 0;
}
