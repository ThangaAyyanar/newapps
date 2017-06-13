/*

i/p:
everest

o/p:
2

explain:
eve
ere

two possible palindrome
*/
#include<stdio.h>
#include<string.h>
int palindrome(char *a,int start,int end){
        int n=end;
        printf("\nin function %d %d",start,end);
        for(;start<=end;start++,end--){
                if(a[start]!=a[end]){
                        return 0;
                }
        }
        return 1;
}
int main(){
        char str[100];
        scanf("%s",str);
        int cnt=0,i,j,n=strlen(str);
        for(i=0;i<n;i++){
                for(j=i+1;j<n;j++){
                        printf("\nin loop: %d %d",i,j);
                        if(palindrome(str,i,j)){
                                cnt++;
                        }
                }
        }
        printf("\ncount %d",cnt);
        return 0;
}
