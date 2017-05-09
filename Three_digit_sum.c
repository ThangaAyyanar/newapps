/*

i/p:
asd111dfg222

o/p:
333

explanation:
111+222=>333

*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int count=0;
int main(){
	char str[200];
	scanf("%s",str);
	int i,count=0,sum=0,temp;
	for(i=0;i<strlen(str);i++){
		if(isdigit(str[i])){
			count++;
			if(i==(strlen(str)-1) && count==3){                               // check if i reach end of string
				temp=(str[i-2]-'0')*100+(str[i-1]-'0')*10+(str[i]-'0');         //convert string to number
				sum+=temp;                                                      //add to sum
				//printf("find digit %d\n",temp);
			}else
				continue;
		}
		if(isalpha(str[i]) && count==3){                                    //check if string contain alphabet and count=3 (3-digit number0
			count=0;
			temp=(str[i-3]-'0')*100+(str[i-2]-'0')*10+(str[i-1]-'0');         //convet string to number
			sum+=temp;                                                        //add to sum
			//printf("find digit %d\n",temp);
		}
		count=0;
	}
	printf("%d",sum);
	return 0;
}
