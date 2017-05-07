/*

i/p:
CRY

3 and middle is 1 //this is for debugging

o/p:
**R
*RY
RYC


*/

#include<stdio.h>
#include<string.h>
int main(){
	char str[1000];
	scanf("%s",&str);
	int i,j,n=strlen(str),middle,k,temp;
  
	middle=n/2;                                             //find the middle element
  
	//printf("%d and middle is %d\n",n,middle);
	
  for(i=0;i<n;i++){
		
    for(k=0;k<(n-i-1);k++){                              //for loop which is used to print star
			printf("*");
		}
		
    temp=middle;                                         //start from middle element (CRY => start with R)
		for(j=0;j<=i;j++){
			printf("%c",str[temp%n]);                          // temp%n => to restrict to array bounds
			temp++;
		}
		printf("\n");
	}
	return 0;
}
