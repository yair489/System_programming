#include <stdio.h>
#include <stdbool.h>
#include "my_mat.h"


int main(){
char input;
bool flag =true;//when to stop the program
do
{
    
    scanf("%c",&input);
    int ch_num = (int)input;
    switch (ch_num)
    {
    case 'A':
        /* code */
        building();
        break;

    case 'B':
        /* code */
       
        int a, b;
        scanf("%d",&a);
        scanf("%d",&b);
        exsistpath(a, b);
        break;

    case 'C':
        /* code */
        
       int c,d ;
        scanf("%d",&c);
        scanf("%d",&d); 
        shortpath(c ,d);
        break;

     case 'D':
        flag =false;
     break;

    default:
        break;
    
    }
} while (flag);


    return 0;
}
