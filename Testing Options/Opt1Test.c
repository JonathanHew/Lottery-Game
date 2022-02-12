/* Test for option 1 
Joathan Hew
20/02/2020
*/
#include <stdio.h>
#define SIZE 6
int main()
{
    int user[SIZE]= {0,0,0,0,0,0};
    int i;
    int j;
    int num;
    int valid;
    
    printf("Please enter your 6 lotto numbers. \n");
    
    //entering data
    for(i=0;i<SIZE;i++)
    {
        while (1)
        {
            valid = 0;
            scanf("%d", &num);
            flushall();
            
            if (num < 1 || num > 42)
            {
                printf("\n The number %d is invalid as it does not lie within the range of 1-42. Please select another number. \n", num);
                valid ++;
            }//end if
            
            for (j=0;j<SIZE;j++)
            {
                if (num == user[j])
                {
                    printf("\n The number %d is invalid as it has already been chosen. Please selectanother number. \n", num);
                    valid ++;
                }//end if
            }//end for
            if (valid == 0)
            {
                break;
            }//end if
        }//end while
        
        
        *(user+i) = num;
    }//end for
    
    printf("\n");
    //displaying data
    for (i=0;i<SIZE;i++)
    {
        printf("%d ", *(user+i));
    }//end for
    
    
    getchar();
    
    return 0;
}//end main