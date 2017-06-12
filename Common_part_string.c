/*

Common part in string values

Two string values S1 and S2 are passed as input. The last portion of S1 will be the first portion of S2. The program must print this common part in S1 and S2.

Input Format:
The first line contains S1.
The second line contains S2.

Output Format:
The first line contains the common part.

Boundary Conditions:
Length of S1 and S2 will be from 3 to 100.

Example Input/Output 1:
Input:
mayday
daybreak

Output:
day

Example Input/Output 2:
Input:
bridge
gear

Output:
ge

*/
#include<stdio.h>
#include<string.h>
int count[256]={0};
int main(){
        char str[100],str1[100];
        scanf("%s",str);
        scanf("%s",str1);
        int i,flag=1,flag2=0;;
        for(i=0;i<strlen(str);i++){
                count[str[i]]++;
        }
        for(i=0;i<strlen(str1);i++){
                if(count[str1[i]]!=0 && flag==1){
                        printf("%c",str1[i]);
                        count[str1[i]]--;
                        flag2=1;

                }else{
                        if(flag2==1)
                                flag=0;
                }
        }
        return 0;
}
