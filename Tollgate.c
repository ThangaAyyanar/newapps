Toll Gates - Max Fee Collection

There is a national highway which is of length N kilometers. K toll gates are currently present in the highway. But due to a recent court order, the government can collect fee only at toll gates which are separated by more than D kilometers. The distance of these K toll gates from the starting point and the fee collected in each of these K toll gates are passed as input. The program must print the maximum revenue that the government can collect in a one way trip (from start to ending point).

Input Format:
The first line will contain N and D separated by a space.
The second line will contain the value of K.
The third line will contain the distance in kilometers from the starting point for the K toll gates, with the values separated by a space.
The fourth line will contain the fee collected at the K toll gates, with the values separated by a space.

Output Format:
The first line will contain the the maximum revenue that can be collected from start to end.

Boundary Conditions:
5 <= N <= 1000
1 <= D <= 1000
2 <= K <= 100
Fee collected will be from 1 to 500.

Example Input/Output 1:
Input:
200 50
5
60 70 120 130 140
50 70 50 30 20

Output:
100

Explanation:
There are 5 tollgates present at 60, 70, 120, 130 and 140 kms respectively.
As the tollgates should be separated by more than 50kms, the maximum revenue will be obtained when the tollgates at 60th km and 120th km are selected as the total revenue is 50+50 = Rs.100.
The tollgates at 70th and 120th kms cannot be chosen to give 70+50 = Rs.120 revenue as they are not separated by more than 50 kms.

Example Input/Output 2:
Input:
200 40
5
60 70 120 130 180
50 70 50 30 20

Output:
140

Explanation:
There are 5 tollgates present at 60, 70, 120, 130 and 140 kms respectively.
As the tollgates should be separated by more than 50 kms, the maximum revenue will be obtained when the tollgates at 70th km, 120th km and 180th km are selected as the total revenue is 70+50+20 = Rs.140.

#include<stdio.h>
int main(){
	int i,j,N,D,n,tempi,sum,ruppee,max=0,pri,tempj,cnt;
	scanf("%d",&N);
	scanf("%d",&D);
	scanf("%d",&n);
	int tollgate[n],price[n];
	for(i=0;i<n;i++)
		scanf("%d",&tollgate[i]);
	for(i=0;i<n;i++)
		scanf("%d",&price[i]);
	//main logic of the program
	for(i=0;i<n;i++){
		tempi=i;
		sum=tollgate[i];
		ruppee=price[i];
		for(j=i+1;j<n;j++){
			if((tollgate[j]-tollgate[tempi]) > D){
				//if(sum+tollgate[j] < N){
					pri=price[j];
					tempj=j+1;
					cnt=0;
					for(;tempj<n;tempj++){
						//printf("%d -- %d\n",(tollgate[tempj]-tollgate[j]),price[tempj]);
						if(price[tempj] > pri && (tollgate[tempj]-tollgate[j]) < D ){
							pri=price[tempj];
							//printf("price decision : %d\n",pri);
							cnt++;
						}
					}
					j+=cnt;	
					sum+=tollgate[j];
					printf("%d\n",pri);
					ruppee+=pri;
					tempi=j;
				//}
			}	
		}
		printf("Total %d\n",ruppee);
		if(ruppee > max)
			max=ruppee;
	}
	printf("%d",max);
	return 0;
}


this program works for above test case when the test case is complicated the program didnot work as expected that's why it is 
droped in building branch

so i am working on it ....

any ideas to improve coding is welcome
