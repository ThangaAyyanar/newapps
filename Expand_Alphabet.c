/*

i/p:
4a6b

o/p:
aaaabbbbbb

*/

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int main(){
	char str[100],character,tmp[2];
	scanf("%s",str);
	int n=strlen(str),i,cnt=0,j;
	for(i=0;i<n;i++){
		if(isalpha(str[i])){
			character=str[i];
			for(j=0;j<cnt;j++)
				printf("%c",character);
			cnt=0;
		}
		else{
			if(isdigit(str[i])){
				tmp[0]=str[i];
				tmp[1]='\0';
				cnt=cnt*10+atoi(tmp);
			}
		}
	}
	
	return 0;
}
