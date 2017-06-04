/*

Chars To Remove For Same String Value

N string values S1, S2, S3, SN are passed as input to the program. Values of S1, S2, S3, SN are such that if one character is removed from each of these string values, then the resulting string values are equal (same).
The characters to be removed from the string values named C1, C2, C3, CN  will be different for each string.


Input Format:
The first line will contain the value of N.
The next N lines will contain the values of strings S1 to SN.

Boundary Conditions:
2 <= N <= 10
Length of string SN is from 2 to 200

Output Format:
The first line will contain the characters C1, C2, C3, .. CN to be removed from each of these string without any space between them.


Example Input/Output 1:

Input:
2
bmanabgerb
manasgsesr

Output:
bs

Explanation:
If the character b is removed from the first string, it becomes manager.
If the character s is removed from the second string, it becomes manager.
Hence bs is printed as output.


Example Input/Output 2:

Input:
5
abcdef
ambcde
qabcdqe
kkakbkckdke
zabczdzzze

Output:
fmqkz

*/

#include<stdio.h>
#include<string.h>
int alpha[26]={0},n,l=1;
char dis[100];
void counting(char *s){
        int i;
        for(i=0;i<strlen(s);i++){
                alpha[s[i]-'a']++;
        }
}
void check(char *s,int flag){
        int i,f=0;
        if(flag==0){
                for(i=0;i<strlen(s);i++){
                        if(alpha[s[i]-'a']==0){
                                //printf("from check %c\n",s[i]);
                                dis[l++]=s[i];
                                break;
                        }
                }
        }else{
                for(i=0;i<strlen(s);i++){
                        if(alpha[s[i]-'a']!=0){
                                --alpha[s[i]-'a'];
                                //printf("from flag %c\n",s[i]);
                        }else{
                                //printf("from check %c\n",s[i]);
                                if(!f){
                                        dis[l++]=s[i];
                                        f=1;
                                }
                        }
                }
        }
}
int main(){
        scanf("%d",&n);
        char str[n][200];
        int i;
        scanf("%s",str[0]);
        counting(str[0]);
        for(i=1;i<n;i++){
                scanf("%s",str[i]);
                if(i==n-1)
                        check(str[i],1);
                else
                        check(str[i],0);
        }
        for(i=0;i<26;i++){
                if(alpha[i]!=0){
                        dis[0]=i+'a';
                        break;
                }
                //printf("%c -> %d\n",('a'+i),alpha[i]);
        }
        dis[l]='\0';
        printf("%s",dis);
        return 0;
}
