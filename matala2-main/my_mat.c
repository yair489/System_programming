#include <stdio.h>
#include <stdbool.h>
#include "my_mat.h"

#define MATRIX_NUM 10


//our statics matrix:
static int mat_master[MATRIX_NUM][MATRIX_NUM]={0};//matrix that help for culculate the path

int min(int a, int b){//return min
    if(a<b){return a;}
    return b;
}

 /*apdate the matrix to hold num represent the shortest path*/
void buildPathMat(){
    //int mat_path[MATRIX_NUM][MATRIX_NUM]={0};//Delete?

    for (size_t k = 0; k < MATRIX_NUM; k++)//Matrix num
    {        
        for (size_t i = 0; i < MATRIX_NUM; i++)//Row line
        {
            for (size_t j = 0; j < MATRIX_NUM;j++)//Coll line
            {
                
                if (i==j)//diagonal line = {0}
                {
                    continue;
                }
                else if (i==k || j==k) //Row or Coll line of Matrix num stay the same
                {
                    continue;   
                }
                else if( (mat_master[k][j] == 0) || (mat_master[i][k] == 0) ){//infinity, so we prefere the other way 
                    continue;   
                }
                else if( mat_master[i][j] == 0 ){//infinity, so we prefere the other way
                    mat_master[i][j] = mat_master[k][j] + mat_master[i][k];
                }
                else{//no one is infinity, so which is shorter?
                    mat_master[i][j] = min( (mat_master[i][j]) , (mat_master[k][j] + mat_master[i][k]) );
                }
                
            }      
        }
        
    }
}
/*get matrix with 10x10 numbers from the scanner, the matrix represent a graph:
matrix[i][j] hold the length of the line between vertices i and j
if there is no such line, it holds 0.*/
 void building(){
    
        
        int input;
        for (size_t i = 0; i < MATRIX_NUM; i++)//Row line
        {
            for (size_t j = 0; j < MATRIX_NUM; j++)//Coll line
            {
                /* to inilaize the matrix */
                scanf(" %d",&input);
                mat_master[i][j]= input;
            }
        }
        
        buildPathMat();
 }
 
/*print True if there is a path from vertex a to b*/ 
void exsistpath(int a, int b){
    if(mat_master[a][b] == 0){//means no path
        printf("False\n");
    }
    else {
        printf("True\n");
    }
}

/*print the shortes path from vertex c to d, if there's no such path- print -1 */
void shortpath(int c ,int d){
    if (mat_master[c][d] == 0)
    {
        printf("-1\n");
    }else{    
        int x = mat_master[c][d];
        printf("%d\n",x);
    }
}
