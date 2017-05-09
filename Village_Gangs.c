/*

Village Gangs - Max Count

In a village there are N people whose identification numbers are from 1 to N. These villagers team together among themselves to form a certain number of gangs. There may be some villagers who are not part of any of these gangs. A combination (i,j) where 1 <= i,j <= N indicates that i and j belong to the same gang. C is the number of such combinations that are passed as input to the program.

The program must print the size of the gang which has the maximum number of people. (People who are not part of any of the gangs are considered as individual gangs whose size is 1)

Input Format:
First line contains N and C separated by a space.
Next C lines contain two identification numbers i and j separated by a space.

Output Format:
First line contains the size of the gang which has the maximum number of people.

Boundary Conditions:
1 <= N <= 100000
1 <= C <= 100000
1 <= i,j <= N in the C lines.

Note:
In a combination (i,j),  i and j can be equal.

Example Input/Output 1:
Input:
5 6
2 2
3 3
1 1
2 3
1 4
3 4

Output:
4

Explanation:
There are 5 people and 6 combinations are provided. So based on the input we have the following gangs.
(2,3,1,4) (5).
Gang (2,3,1,4) is the largest with size as 4.

Example Input/Output 2:
Input:
10 11
1 2
7 8
10 9
10 10
4 4
3 10
8 5
6 5
6 6
9 4
3 2

Output:
6

Explanation:
The largest gang is (1,2,3,10,9,4) whose size is 6.

*/

// THIS WORKS WELL BUT FAILED IN HIDDEN TEST IF YOU FOUND ANY PROBLEM THEN INTIMATE ME  

#include<stdio.h>

struct combi{
	int person1,person2;
};

int num_people,combinations;
int max=0,stack[50],top=0;

int findmygang(int key,int *a,struct combi *possible){              //  function to find gang members
	int count=1,i,k=0;
	a[key-1]=1;
	while(k<num_people){
	for(i=0;i<combinations;i++){
		if(possible[i].person1==key && possible[i].person2==key){
			continue;
		}else if(possible[i].person1==key){
			//printf("\nkey is %d",key);
			if(a[possible[i].person2-1]!=1){
				a[possible[i].person2-1]=1;
				stack[top++]=possible[i].person2;
				count++;
			}
		}else if(possible[i].person2==key){
			//printf("\nkey is %d",key);
			if(a[possible[i].person1-1]!=1){
				a[possible[i].person1-1]=1;
				stack[top++]=possible[i].person1;
				count++;
			}
		}
	}
	//printf("\nthe current key is %d",key);
	if(top!=0){
		key=stack[top-1];
		top--;
	}else{
		break;
	}
	k++;
	}
	return count;
}

int main(){
	scanf("%d%d",&num_people,&combinations);
	int i,a[num_people],t_result;
	struct combi possible[combinations];
	for(i=0;i<combinations;i++){
		scanf("%d%d",&possible[i].person1,&possible[i].person2);
	}
	for(i=0;i<num_people;i++)
		a[i]=0;
	i=0;
	while(i<num_people){
		if(a[i]==0){
			t_result=findmygang(i+1,a,possible);
			if(max<t_result)
				max=t_result;
		}
		i++;
	}
	printf("%d",max);
	return 0;
}

/*

here logic is very simple

Input:
5 6
2 2
3 3
1 1
2 3
1 4
3 4

Output:
4

EXPLANATION:-

when seeing 2 its pair is 3 and 3 pair is 4 and 4 pair is 1
2->3->1->4

my program find all above chains and select the max gang chain
  
*/
