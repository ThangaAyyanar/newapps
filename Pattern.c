/*

i/p:
5

o/p:
1 6 10 13 15 
2 7 11 14 
3 8 12 
4 9 
5 

*/

#include<stdio.h>
int main(){
	int n,i,j,tmp;
	scanf("%d",&n);
  
	for(i=1;i<=n;i++){
		printf("%d ",i);                      //print the first value in pattern
		
    tmp=i+n;                              //next value is calculated using i+n i.e 1+5=>6
    
		for(j=0;j<n-i;j++){
    
			printf("%d ",tmp);                  //other value are calculated by n-j-1 i.e 6+5-0-1=>11-1=>10 (previously tmp is '6')    
 			tmp=tmp+n-j-1;                      //like this temp value get generated
      
		}
    
		printf("\n");
	}
	return 0;
}
