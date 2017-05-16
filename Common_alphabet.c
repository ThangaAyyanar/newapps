/*

i/p:
2
lion
iron

o/p

or(common occurance in ascending order)

*/

#include<stdio.h>
#include<string.h>
int n,j,count=0,global=0;
void sort(char *string){
	int i,j;
	char temp;
	for(i=0;i<strlen(string);i++){
		for(j=0;j<strlen(string);j++){
			if(string[i] < string[j]){
				temp=string[i];
				string[i]=string[j];
				string[j]=temp;
			}
		}
	}
}
int find_common_occurance(char str[n][20],char key,int k){
	int i,flag=0;
	//printf("k value %d\n",k);
	if(k>=n)
		return 1;
	for(i=0;i<strlen(str[k]);i++){
		if(str[k][i]==key){
			//printf("finded common occurance %s\n",str[k]);
			find_common_occurance(str,key,k+1);
			++count;
			if(count==n){
				count=0;
				printf("%c",key);
				global=1;
				return 1;
			}
			flag=1;
		}
	}
	if(flag)
		return 0;
}
int main(){
	int i,len,res=0;
	scanf("%d",&n);
	n=n-1;
	char str[n][20],trump[20];
	scanf("%s",trump);
	for(i=0;i<n;i++){
		scanf("%s",&str[i]);
	}
	//for(i=0;i<n;i++)
	//`	printf("%s\n",str[i]);
	len=strlen(trump);
	sort(trump);
	printf("%s\n",trump);
	for(i=0;i<len;i++){
		count=0;
		if(i!=0){
			if(trump[i]==trump[i-1]){
				continue;
			}
		}
		res=find_common_occurance(str,trump[i],0);
		//printf("Main Loop %c\n",trump[i]);
	}if(!global){
		printf("-1");
	}
	return 0;
}

/*

I know i make a quite messy program i am trying other solution when it work, i add the source with this

*/
