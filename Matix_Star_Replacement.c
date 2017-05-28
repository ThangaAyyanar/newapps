/*
A N*N matrix having N rows and N columns containing + or * for it's cell values is passed as the input. Two strings S1 and S2 are also passed as input. The program must search for * in a straight line (either left to right or top to bottom) and replace them with strings S1 and S2.

Input Format:
The first line will contain the value of N.
The next N lines will contain the values for N rows having +  and  * representing the cell values of the matrix.
The last two lines will contain the value of the two strings S1 and S2 respectively.

Output Format:
N lines with the matrix cell values containing * replaced by the characters in the string values S1 and S2.

Constraints:
4 <= N <= 100
Length of S1 and S2 is from 2 to N.

Example Input/Output 1:
Input:
10
++++++++++
++++++++++
+++*++++++
+++*++++++
+++***++++
+++*++++++
+++*++++++
+++*++++++
++++++++++
++++++++++
MANAGE
NEW

Output:
++++++++++
++++++++++
+++M++++++
+++A++++++
+++NEW++++
+++A++++++
+++G++++++
+++E++++++
++++++++++
++++++++++

Example Input/Output 2:
Input:
6
++++++
++*+++
++****
++*+++
++*+++
++++++
LION
IRON

Output:
++++++
++L+++
++IRON
++O+++
++N+++
++++++

*/
#include<stdio.h>
#include<string.h>
//structure to save the details of the star location
struct star_details{
        int starti,startj;
        int length;
}star[2];
/*
 * star[0] => hold details about vertical star
 * star[1] => hold details about horizontal star
*/
short int overlapi=-1,overlapj=-1;
int rows,cols;

//display function
void display(char a[rows][cols]){
        int i,j;
        printf("\n");
        for(i=0;i<rows;i++){
                for(j=0;j<cols;j++)
                        printf("%c",a[i][j]);
                printf("\n");
        }
}

//to find length of the star in the 2-D array
void starformation(int i,int j,char a[rows][cols],char direction){
        int count=0,flag=0;
        //check for vertical
        if(direction=='v'){
                star[0].starti=i;
                star[0].startj=j;
                for(;i<rows;i++){
                        //printf("\nthe value of %d and %d is: %c",i,j,a[i][j]);
                        if(a[i][j]=='*'){
                                count++;
                        }
                        if(a[i][j+1]=='*' && j<cols){
                                overlapi=i;
                                overlapj=j;
                        }
                }
                star[0].length=count;
                //printf("the value of count is %d",count);
        }

        //check for horizontal
        if(direction=='h'){
                star[1].starti=i;
                star[1].startj=j;
                for(;j<cols;j++){
                        //printf("\nthe value of %d and %d is: %c",i,j,a[i][j]);
                        if(a[i][j]=='*'){
                                count++;
                        }
                }
                star[1].length=count;
        }

}

//replace the * with string
void replace_star(char a[rows][cols],char way,char *str,char *str2){
        int k,i,j;
        k=0;
        if(way=='n'){
                for(i=star[0].starti;i<rows&&k<strlen(str);i++)
                        a[i][star[0].startj]=str[k++];
                k=0;
                for(j=star[1].startj;j<cols&&k<strlen(str2);j++)
                        a[star[1].starti][j]=str2[k++];
                display(a);
        }
        if(way=='s'){
                for(i=star[0].starti;i<rows&&k<strlen(str2);i++)
                        a[i][star[0].startj]=str2[k++];
                k=0;
                for(j=star[1].startj;j<cols&&k<strlen(str);j++)
                        a[star[1].starti][j]=str[k++];
                display(a);
        }
}
int main(){
        scanf("%d",&rows);
        cols=rows;
        char a[rows][cols],str[100],str2[100];
        int flag=0,i,j,k;
        for(i=0;i<rows;i++){
                scanf("%s",a[i]);
        }
        scanf("%s",str);
        scanf("%s",str2);

        //find the vertical
        for(i=0;i<rows;i++){
                for(j=0;j<cols;j++){
                        if(a[i][j]=='*' && a[i+1][j]=='*'){
                                starformation(i,j,a,'v');
                                flag=1;
                                break;
                        }
                }
                if(flag)break;
        }
        flag=0;

        //find the horizontal
        for(i=0;i<rows;i++){
                for(j=0;j<cols;j++){
                        if(a[i][j]=='*' && a[i][j+1]=='*'){
                                starformation(i,j,a,'h');
                                flag=1;
                                break;
                        }
                }
                if(flag)break;
        }

        //debug information
        printf("\nThe values are");
        printf("\nvertical %d %d",star[0].starti,star[0].startj);
        printf("\nHorizontal %d %d",star[1].starti,star[1].startj);
        printf("\nlength %d %d",star[0].length,star[1].length);
        printf("\nString length %d %d",strlen(str),strlen(str2));

        //assign value to the star
        if(star[0].length==star[1].length){
                if(str[overlapi-star[0].starti]==str2[overlapj-star[1].startj]){
                        replace_star(a,'n',str,str2);
                        return 0;
                }
                if(str2[overlapi-star[0].starti]==str[overlapj-star[1].startj]){
                        replace_star(a,'s',str,str2);
                        return 0;
                }
                //printf("\nstr location %c",str[overlapi-star[0].starti]);
                //printf("\nstr2 location %c",str2[overlapj-star[1].startj]);
                //printf("\nstr2 location %c",str2[overlapi-star[0].starti]);
                //printf("\nstr location %c",str[overlapj-star[1].startj]);
        }

        //compare the given string with star
        if(star[0].length==strlen(str) && star[1].length==strlen(str2)){
                replace_star(a,'n',str,str2);
                return 0;
        }
        if(star[0].length==strlen(str2) && star[1].length==strlen(str)){
                replace_star(a,'s',str,str2);
                return 0;
        }
        return 0;
}
/*

I tired for most test case if you find any bugs create a issue

find me at thangaayyanar.blogspot.com
*/
