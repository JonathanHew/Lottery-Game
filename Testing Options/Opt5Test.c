/* Test for option 5
Jonathan Hew 
03/03/2020
*/
#include <stdio.h>
#define SIZE 6
#define LOTTO 100
int main()
{
    int user[SIZE];
    int freq[LOTTO] = { 0 };
    int number;
    int i;
    int invalid;
    int temp;
    
    printf("Please enter your 6 lotto numbers. \n");
    
    for (i=0;i<SIZE;i++)
    {
        scanf("%d",&*(user+i));
        
        freq[*(user+i)]++;
    }//end for
    
    for (i=0;i<SIZE;i++)
    {
        printf("%d ", *(user+i));
    }//end for
    
    while (1)
    {
        invalid = 0;
        printf("\n Which lotto number would you like to see the frequency of ? \n ");
        scanf("%d", &temp);
        flushall();
        
        //checking to see if number lies within the range of 1-42 inclusive
        if (temp < 1 || temp > 42)
        {
            printf("\n The number %d is invalid as it does not lie within the range of 1-42. Please select another number. \n", temp);
            invalid ++;
        }//end if
            
        //exiting while loop if number is valid
        if (invalid == 0)
        {
            break;
        }//end if    
    }//end while 
    
    number = temp;

    printf("\n The number %d has been chosen %d times.", number, *(freq + number));
    getchar();
    
    return 0;
    
}//end main