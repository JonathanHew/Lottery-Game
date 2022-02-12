/* Program designed to play a lotto game.
The game will allow the user to enter 6 numbers and also to offer a set options each performing a specefic requirement.
Program is designed to be modularised and each option is carried out in a seperate function.
Option 1 will allow the user to enter any 6 numbers (1-42 inclusive) from the keyboard with neccesary validation.
Option 2 will display the contents of the 1-d array containing the chosen lotto numbers.
Option 3 will sort the contents of the array from smallest to largest.
Option 4  will compare your chosen lotto numbers with the winning numbers (1,3,5,7,9,11) and display the prize won.
Option 5 will display the frequency of any number on the screen (without existing the program).
Option 6 will exit the program.
Pointer notation is used to access elements of an array.
Option 2,3,4,5 will only be accesible after 6 valid numbers have been chosen.
Designed by Jonathan Hew
Date: 23/02/2020
Compiler: Borland

*/
#include <stdio.h>
#define SIZE 6
#define LOTTO 43
//function signatures
void number_entry(int*, int*);
void number_print(int*);
void number_sort(int*);
void number_comparison(int*);
void number_frequency(int*);

int main()
{
    int input;
    int opt1count=0;
    int user_num[SIZE] = {0};
    int freq[LOTTO] = {0};
    
    //do while loop to displaymenu until option 6 ("EXIT") is clicked after a function is completed the program will return to this main menu
    do 
    {
        input = 0;
        
        printf("\n\n------------------------------------------------------------------------------------------------------------------------");
        printf("\n**********MAIN MENU********** \n\n");
        printf("1. Enter your Lotto numbers. \n");
        printf("2. Display chosen Lotto numbers. \n");
        printf("3. Sort chosen numbers from smallest to biggest. \n");
        printf("4. Compare chosen Lotto numbers with winning numbers. \n");
        printf("5. Display the frequency of a chosen number since the start of the game. \n");
        printf("6. END GAME \n\n");
        printf("------------------------------------------------------------------------------------------------------------------------ \n\n");
        
        scanf("%d", &input);
        
        //switch statement to read the input from the user and to carry out the relevant case and to call the relevant function
        switch (input)
        {
            case 1:
                {
                    //call function number_entry to allow user to input Lotto Numbers
                    number_entry(user_num, freq);
                    //increment the counter for the amount of times option 1 has been called 
                    opt1count = opt1count+1;
                }//end if
                break;
            case 2:
                {
                    //displaying error message as option 1 has not been entered yet. option1 counter is not greater then 0.
                    if ( opt1count < 1)
                    {
                        printf("\n Please enter your lotto numbers first. (Option 1) \n");
                    }//end if
                    else
                    {
                        //if the counter for option 1 is greater then 0 then call function number_print to print lotto numbers chosen
                        number_print(user_num);
                    }//end else
                }//end if
                break;
            case 3:
                {
                    //Displaying error message if Option 1 has not been entered yet. Option 1 count is not greater then 0
                    if ( opt1count < 1)
                    {
                        printf("\n Please enter your lotto numbers first. (Option 1) \n");
                    }//end if
                    else
                    {
                        //If option1 count is greater than 0 and lotto numbers have been entered call function number_sort() to sort the array from smallest to largest
                        number_sort(user_num);
                    }//end else
                }//end if
                break;
            case 4:
                {
                    //Displaying error message as lotto numbers have not yet been entered. Option 1 count is not greater then 0
                    if ( opt1count < 1)
                    {
                        printf("\n Please enter your lotto numbers first. (Option 1) \n");
                    }//end if
                    else
                    {
                        //If lotto numbers have been entered and Option1 count is greater then 0 then call function number_comparison() to compare chosen numbers with winning numbers and to reveal if prizes were won
                        number_comparison(user_num); 
                    }//end else
                }//end if
                break;
            case 5:
                {
                    //displaying error message as lotto numbers have not been entered. Option 1 count is not greater then 0
                    if ( opt1count < 1)
                    {
                        printf("\n Please play the lotto atleast once. (Option 1) \n");
                    }//end if
                    else
                    {
                        //If lotto numbers have been entered , Option 1 count is greater then 0 then call function number_frequency() to check the fequency of number being chosen so far while program has been running
                        number_frequency(freq);
                    }//end else
                }//end if
                break;
            case 6:
                {
                    //exit the program when option 6 is selected
                    return 0;
                }//end if
            default: 
                //displaying error message if an invalid inout is entered
                printf("\n Please enter a valid option. \n");
        }//end switch
    }//end do 
    while (!(input == 6));
        
    getchar();
    
}//end main


/* Implement number_entry()
Fucntion to allow the user to input 6 chosen Lotto Numbers into the array.
Necessary validation and error checking is carried out to prevent letters, numbers out of the range and repeated numbers frombeing inputted 
*/
void number_entry(int *lotto_number, int *num_freq)
{
    int i;
    int j;
    int num;
    int invalid;
    
    //for loop to clear each element in  array that contained previous lotto numbers
    for (i=0;i<SIZE;i++)
    {
        *(lotto_number+i) = 0;
    }//end for
    
    printf("\n Please enter your 6 lotto numbers.\n ");
    printf("Make sure they lie within the range of 1-42 inclusive.\n");
    printf("Also make sure no number is repeated. \n\n");
    
    //outter for loop to allow user to input eachelement into the array 
    for(i=0;i<SIZE;i++)
    {
        //while loop to wait for number to pass allerror checks before input
        while (1)
        {
            //resetting error counter 
            invalid = 0;
            scanf("%d", &num);
            
            //error checking to see if number lies within the range of 1-42 inclusive
            if (num < 1 || num > 42)
            {
                //displaying error message as number does notlie within the range of 1-42
                printf("\n The number is invalid as it does not lie within the range of 1-42. Please select another number. \n");
                //incrementing error counter 
                invalid ++;
            }//end if
            
            //inner for loop check to see if number has already been inputted by the user
            for (j=0;j<SIZE;j++)
            {
                //checking to see if inputted number already exists in the array
                if (num == *(lotto_number+j))
                {
                    //displaying error message to tell user that nuumber has already been repeated 
                    printf("\n The number is invalid as it has already been chosen. Please select another number. \n");
                    //incrementing error counter
                    invalid ++;
                }//end if
            }//end inner for for
            //if no errors occur in the chosen number then break out of while loop
            if (invalid == 0)
            {
                break;
            }//end if
        }//end while
        
        //assign chosen number into the array
        *(lotto_number+i) = num;
        //increment the frequency array for the chosen numberfor option 5
        num_freq[*(lotto_number+i)]++;
    }//end outter for loop
    printf("\n Your Lotto numbers have been chosen. Please select option 2 to view your numbers.");
}//end number_entry()


/* Implement number_print()
Function to print out all chosen lotto numbers in the array
*/
void number_print(int *array_to_print)
{
    int i;
    
    printf("\n You chose the following lotto numbers: \n");
    //for loop to print out each chosen lotto number in the array
    for (i=0;i<SIZE;i++)
    {
        printf("%d ", *(array_to_print+i));
    }//end for
}//end number_print()


/*Implement number_sort()
Function to sort chosen lotto numbers the array from smallest to biggest when called
*/
void number_sort(int *array_to_sort)
{
    int i;
    int j;
    int temp;
    
    //outer for loop for first number in comparison
    for (i=0;i<SIZE;i++)
    {
        //inner for loop for second number in comparison 
        for (j=0;j<SIZE;j++)
        {
            //checking to see if current number is bigger then previpus number 
            if (*(array_to_sort+i) < *(array_to_sort+j))
            {
                temp = *(array_to_sort+i);
                *(array_to_sort+i) = *(array_to_sort+j);
                *(array_to_sort+j) = temp;
            }//end if
        }//end inner for
    }//end outter for
    printf("\n The numbers have now been sorted from smallest to biggest.\n");
    printf("To view your numbers please selct option 2. \n");
}//end number_sort()


/* Implement number_comparison()
Function to compare the users chosen lotto number array with the already set winning numbers array
A prize will be displayed depending on the amount of matched numbers by the user
*/
void number_comparison(int *array_to_compare)
{
    int winner[SIZE] = {1, 3, 5, 7, 9, 11};
    int i;
    int j;
    int correctcount=0;
    
    //displaying winning numbers message
    printf("\n The winning numbers are:");
    //printing numbers in winning numbers array
    for (i=0;i<SIZE;i++)
    {
        printf("%d ", *(winner+i));
    }//end for
    
    //outer for loop for first number in comparison 
    for (i=0;i<SIZE;i++)
    {
        //inner for loop for second number in comparison 
        for (j=0;j<SIZE;j++)
        {
            //incrementing counter if number is present in both arrays
            if (*(array_to_compare+i) == *(winner+j))
            {
                correctcount++;
            }//end if
        }//end for
    }//end for 
    
    //switch statement to tell user if / what prize they have won according to how many numbers they have matched
    switch (correctcount)
    {
        case 0:
        {
            printf("\n You matched 0 numbers. \n");
            printf("\n Sorry, you didnt win. Better luck next time!");
        }//end case
        break;
        case 1:
        {
            printf("\n You matched 1 number. \n");
            printf("\n Sorry, you didnt win. Better luck next time!");
        }//end case
        break;
        case 2:
        {
            printf("\n You matched 2 numbers. \n");
            printf("\n Sorry, you didnt win. Better luck next time!");
        }//end case
        break;
        case 3:
        {
            printf("\n You matched 3 numbers. \n");
            printf("\n You won a Cinema Pass !! \n");
        }//end case
        break;
        case 4:
        {
            printf("\n You matched 4 numbers. \n");
            printf("\n You won a Weekend away !! \n");
        }//end case
        break;
        case 5:
        {
            printf("\n You matched 5 numbers. \n");
            printf("\n You won a New car !! \n");
        }//end case
        break;
        case 6:
        {
            printf("\n You matched 6 numbers. \n");
            printf("\n You won the Jackpot!!!!! \n");
        }//end case
        break;
        default: 
            printf("\n Sorry you didnt win. Try again next time! \n");
    }//end switch
    
}//end number_comparison()


/* Implement number_frequency() 
function to check the frequency of any chosen number whilst programming has been running
*/
void number_frequency(int *array_freq)
{
    int number_check;
    int invalid;
    int temp;
    
    //while loop to wait tillnumber is valid
    while (1)
    {
        //ressetting error counter
        invalid = 0;
        printf("\n Which lotto number would you like to see the frequency of ? \n ");
        scanf("%d", &temp);
        
        //checking to see if number lies within the range of 1-42 inclusive
        if (temp < 1 || temp > 42)
        {
            //displaying error message if number does not lie within the range
            printf("\n The number is invalid as it does not lie within the range of 1-42. Please select another number. \n");
            //incrementing error count
            invalid ++;
        }//end if
            
        //breaking out of loop if chosen number has no errors
        if (invalid == 0)
        {
            break;
        }//end if    
    }//end while 
    
    number_check = temp;

    printf("\n The number %d has been chosen %d times.", number_check, *(array_freq + number_check));

}//end number_frequency()
