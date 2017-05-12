/*

i/p:

3              //original matrix length
2             //sub matrix length
1 2 3         //orginal matrix
4 5 6
7 8 9
5 6           //sub matrix value 
7 8

o/p:

TRUE // because submatrix present in original matrix

*/

#include<stdio.h>
int on,sn;
int searchin(int i,int j,int org[on][on],int search[sn][sn]){  //fucntion to check submatrix 
        int row,cols,count=0;
        for(row=0;row<sn;row++,i++){
                for(cols=0;cols<sn;cols++,j++){
                        if(org[i][j]==search[row][cols]){
                                count++;
                        }else{
                                return 0;
                        }
                }
                j=j-sn;
        }
        return 1;
}
int main(){
        scanf("%d",&on);
        scanf("%d",&sn);
        int i,j,org[on][on],search[sn][sn];
        for(i=0;i<on;i++)
                for(j=0;j<on;j++)
                        scanf("%d",&org[i][j]);
        for(i=0;i<sn;i++)
                for(j=0;j<sn;j++)
                        scanf("%d",&search[i][j]);
        for(i=0;i<on;i++){
                for(j=0;j<on;j++){
                        if(org[i][j]==search[0][0]){
                                if(searchin(i,j,org,search)){
                                        printf("Found it");
                                        return 0;
                                }
                        }
                }
        }
        printf("not present");
        return 0;
}
