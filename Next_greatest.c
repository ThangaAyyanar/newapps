/*


Find next greater number with same set of digits

Given a number n, find the smallest number that has same set of digits as n and is greater than n

i/p:
1234

o/p:
1243

*/

#include<stdio.h>
#include<string.h>
void correct_last_numbers(char *a,int s,int n){
	int j,i;
	char temp;
	for(i=s;i<=n;i++){
		for(j=i;j<=n;j++){
			if(a[i]>a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
int main(){
	char s[10000],temp;
	scanf("%s",s);
	int i,j,k,mark,flag=0,tmp,lit;
	k=strlen(s)-1;
	printf("the value of k is %d\n",k);
	for(i=k;i>0;){
		if(s[i]>=s[i-1]){
			mark=i-1;
			printf("in loop %d\n",mark);
			flag=1;
			break;
		}
		else{
			i--;
		}
	}
	printf("the value of mark is %d\n",mark);
	tmp=mark+1;
	for(i=mark+1;i<=k;i++){
		if(s[i] < s[tmp] && s[i] > s[mark])
			tmp=i;
	}
	printf("the tmp is %d\n",tmp);
	if(flag){
		temp=s[mark];
		s[mark]=s[tmp];
		s[tmp]=temp;
		printf("after swap %s\n",s);
		correct_last_numbers(s,mark+1,k);
	}
	printf("the mark and tmp is %d and %d %s",mark,tmp,s);
	return 0;
}


/*

Logic is simple 

if the given number is 23964 to calculate the next greatest element first we are going to replace the samllest digit with 
next greatest digit in given digits and sort the digits after the swaped region to get next greater value see below procedure

first: from right->left 
                        6>4 9>6 3>9(false)  hence mark=(location of 3)
                        
second: after the mark to the last left->right find smallest element
      
                    4<6<9 hence the small value is 4
                    
third: swap small and mark hence result will be 24963

four: sort the number after mark to the end of the string

        result will be 24369

*/
