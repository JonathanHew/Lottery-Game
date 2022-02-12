/* Test for option4
Jonathan Hew
27/02/2020
*/
#include <stdio.h>
#define SIZE 6
int main()
{
    int user[SIZE] = {1, 11, 9, 5, 17};
    int winner[SIZE] = {1, 3, 5, 7, 9, 11};
    int i;
    int j;
    int correctcount=0;
    
    for (i=0;i<SIZE;i++)
    {
        for (j=0;j<SIZE;j++)
        {
            if (user[i] == winner[j])
            {
                correctcount++;
            }//end if
        }//end for
    }//end for 
    
    switch (correctcount)
    {
        case 0:
        {
            printf("\n Sorry, you didnt win. Better luck next time!");
        }//end case
        break;
        case 1:
        {
            printf("\n Sorry, you didnt win. Better luck next time!");
        }//end case
        break;
        case 2:
        {
            printf("\n Sorry, you didnt win. Better luck next time!");
        }//end case
        break;
        case 3:
        {
            printf("\n You won a Cinema Pass !! \n");
        }//end case
        break;
        case 4:
        {
            printf("\n You won a Weekend away !! \n");
        }//end case
        break;
        case 5:
        {
            printf("\n You won a New car !! \n");
        }//end case
        break;
        case 6:
        {
            printf("\n You won the Jackpot!!!!! \n");
        }//end case
        break;
        default: 
                printf("\n Sorry you didnt win. Try again next time! \n");
    }//end switch
    
    getchar();
    
    return 0;
}//end main
