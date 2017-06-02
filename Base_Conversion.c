/*

i/p:
2 
111 11


o/p:
10

Explanation:
conversion of 111 base 2 is 7 and 11 is 3 and 7+3 is 10

for base conversion

111 => 1*2^2+1*2^1+1*2^0

base^powers

*/
#include<stdio.h>
#include<math.h>
int convert(int base,int num){
        int dig,sum=0,i;
        for(i=0;num!=0;i++){
                dig=num%10;
                num=num/10;
                sum+=dig*(int)pow(base,i);
        }
        return sum;
}
int main(){
        int base,num1,num2,temp=0;
        scanf("%d",&base);
        scanf("%d %d",&num1,&num2);
        temp+=convert(base,num1);
        temp+=convert(base,num2);
        printf("%d",temp);
        return 0;
}


If you are using gcc compiler use -lm flag for compilation (pow function) 

-lm => math library
