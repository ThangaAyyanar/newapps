/*

There are four tower A,B,C,D
A->C
B->D
given co-ordinates of the tower

check whether the tower A or C interfere with BD communication also B or C interfere with AC communication
*/

/*

There are lot of ways to solve the problem the logic i used is

check A in between B and D 
check C in between B and D 
check B in between A and C 
check D in between A and C 

when you implement this in if condition it will be clumsy large and not a good way to program

other logic ( this logic passed all test case )

((y2<y3 && y3<y4) || (y2>y3 && y3<y4)) => interfere

otherwise no

if you have any logic pull request i will update it

*/
