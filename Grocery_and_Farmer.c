/*
Farmers & Grocery Shop Owner Agreement

A group of farmers in a village and a grocery shop owner enter into an agreement containing the following conditions.
- The price of the item sold by farmers will be monitored over a period of N days.
- The grocery shop owner will pay the price P which was higher than or equal to the previous days pricing for the maximum consecutive days.
- If there are multiple such values for P, then the first occurring price will be considered for P.

The program must accept the input values and print the price P which is to be paid by the grocery shop owner to the farmers.

Note: You must optimize the program to complete it within the given time limit. Else "Timeout" will occur.

Input Format:
First line contains N.
Second line contains N positive integer values separated by a space.

Output Format:
First line contains the price to be paid.

Boundary Conditions:
3 <= N <= 1000000  

Example Input/Output 1:
Input:
7
90 70 60 72 65 75 85

Output:
85

Explanation:
90 was the highest price for 1 day (As there was no previous pricing)
70 was the highest price for just 1 day (As the previous day pricing 90 is more than 70).
60 was the highest price for just 1 day (As the previous day pricing 70 is more than 60 ).
72 was the highest price for 3 days (72 is higher than 70, 60).
Similarly 65 was the highest price for 1 day.
75 was the highest price for 5 days and
85 was the highest price for 6 days.
Hence 85 is printed as the output.

Example Input/Output 2:
Input:

100 80 90 95 90 82 93

Output:
95

Explanation:
Though 95 and 93 both were the highest price for 3 days, the first occurring price which is 95 is printed as the output.
 */
#include<stdio.h>
struct price{
	int index;
	int days;
};
int main(){
	int n,i,max,counter=0,j;
	struct price pay;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	max=a[0];
	pay.index=0;
	pay.days=1;
	for(i=0;i<n-1;i++){
		if(a[i]<a[i+1]){
			for(j=i;j>=0;j--){
				if(a[i+1]>a[j]){
					counter++;
				printf("Day %d and price %d %d\n",counter,a[i+1],a[j]);
				}else
					break;
			}	
			if(counter>pay.days){
				pay.index=i+1;
				pay.days=counter;
			}
			counter=0;
		}
	}
	printf("No of days %d and price %d",pay.days,a[pay.index]); 
	return 0;
}
