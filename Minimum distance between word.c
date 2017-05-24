/*
Minimum Distance Between Words [AMAZON]

A string S is passed as the input. Two words W1 and W2 which are present in the string S are also passed as the input. The program must find the minimum distance D between W1 and W2 in S (in forward or reverse order) and print D as the output.

Input Format:
The first line will contain S.
The second line will contain W1.
The third line will contain W2.

Output Format:
The first line will contain D - the minimum distance between W1 and W2 in S.

Boundary Conditions:
Length of S is from 5 to 200.

Example Input/Output 1:
Input:
the brown quick frog quick the
the
quick

Output:
1

Explanation:
quick and the are adjacent as the last two words. Hence distance between them is 1.

Example Input/Output 2:
Input:
the quick the brown quick brown the frog
quick
frog

Output:
3
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int strcheck(int s,int e,char *str,char *k){
        int i=0,l=s;
        for(i=0;i<strlen(k);i++,l++){
                if(k[i]!=str[l]){
                        return 0;
                }
        }
        return 1;
}
int main(){
        char str[1000],key1[50],key2[50];
        int distance=0,count=0,start=0,end=0,flag=0;
        int i,j,n,s=0;
        scanf("%[^\n]s",str);
        scanf("%s",key1);
        scanf("%s",key2);
        printf("%s\n",str);
        if(strcmp(key1,key2)==0)
                flag=1;
        printf("%d flg \n",flag);
        for(i=0;i<strlen(str);i++){
                if(str[i]==' ' || i==(strlen(str)-1)){
                        printf("string found\n");
                        count++;
                        if(flag==0){
                        if(strcheck(s,i,str,key1)){
                                start=count;
                                printf("Found %d start %s\n",start,key1);
                        }
                        if(strcheck(s,i,str,key2)){
                                end=count;
                                printf("Found %d end %s\n",end,key2);
                        }
                        }else{                                                    //if both word to searched are same
                                if(strcheck(s,i,str,key1)){
                                        if(start==0)
                                                start=count;
                                        else
                                                end=count;
                                }
                        }
                        if(start!=0 && end!=0){
                                if(start!=end && (distance>abs(end-start) || distance==0)){
                                        distance=abs(end-start);
                                        printf("Distance %d\n",distance);
                                }if(flag){
                                        start=end;
                                }else{
                                start=0;
                                //end=0;
                                }
                        }
                        s=i+1;
                }
        }
        printf("\nThe minimum distance is %d",distance);
        return 0;
}
