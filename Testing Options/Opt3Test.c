/* Test for option 1
Jonathan Hew
27/02/2020
*/
#include <stdio.h>
#define SIZE 6
int main()
{
    int user[SIZE] = {1, 3, 5, 7, 9, 2};
    int i;
    int j;
    int temp;
    
    for (i=0;i<SIZE;i++)
    {
        for (j=0;j<SIZE;j++)
        {
            if (*(user+i) < *(user+j))
            {
                temp = *(user+i);
                *(user+i) = *(user+j);
                *(user+j) = temp;
            }//end if
        }//end for
    }//end for
    
    for (i=0;i<SIZE;i++)
    {
        printf("%d ", *(user+i));
    }//end for
    
    getchar();
    
    return 0;
}//end main
