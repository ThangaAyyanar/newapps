/*

i/p:
4a5

o/p:
9

explain:

a,A -> addition
s,S -> subtraction
m,M -> Multiplication
d,D -> Division

*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main(){
	char str[100],*start,*end;
	scanf("%s",str);
	int n,i,a1,b1;
	n=strlen(str);
	for(i=0;i<n;i++){
		if(isalpha(str[i])){
			char a[2];
			a[0]=str[i];
			a[1]='\0';
			a1=atoi(strtok(str,a));
			b1=atoi(strtok(NULL,a));
			printf("%d %d\n",a1,b1);
			switch(a[0]){
				case 'a':
				case 'A':printf("Result %d",a1+b1);
					 break;
				case 's':
				case 'S':printf("Result %d",a1-b1);
					 break;
				case 'm':
				case 'M':printf("Result %d",a1*b1);
					 break;
				case 'd':
				case 'D':printf("Result %d",a1/b1);
					 break;
			}
			//printf("\ncharacter is %c",str[i]);
			break;
		}
	}
	return 0;
}
