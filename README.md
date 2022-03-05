# Lotto Game

Name: Jonathan Hew

# Description

A program I developed in C. <br />
The program allows a user to enter their 6 selected numbers and give them a set of options, each performing a specific requirement. <br />
The 6 numbers are stored in a 1-Dimensional array. <br />
The program is modularised (i.e. use functions) and each task should is dealt in a separate function. <br />
The program displays a simple menu to the user and each option in the menu is implemented by calling a separate function. <br />
Pointer notation is used to access array elements. <br />
<br />
The menu options are as follows: <br />
1. Enter any 6 numbers (1–42 inclusive) from the keyboard. Performs necessary validation (error-checking)  (e.g. all numbers must be different, range 1-42, etc.). <br />
2. Display the contents of the 1-D array containing your lotto numbers that you entered. <br />
3. Sort the contents of the array in increasing order (i.e. 1st element = smallest number, 2nd element = 2nd smallest number, etc.). <br />
4. Compare your chosen lotto numbers in the 1-D array with the following winning numbers: 1,3,5,7,9,11 (Winning numbers).
Depending on how many of the chosen numbers match the above winning numbers, the program will display one of the following messages: <br />
Match 6 = Jackpot <br />
Match 5 = New Car <br />
Match 4 = Weekend Away <br />
Match 3 = Cinema Pass <br />
5. Display the frequency of the numbers entered each time the user enters a new set of numbers (without exiting the program) on the screen. <br />
6. Exit Program <br />
<br />
Also: <br />
1. After a function has completed, the program will return to the main menu and allow the user to select another option. <br />
2. The user is only allowed to select options 2, 3, 4 & 5 only if they have correctly entered their 6 valid chosen numbers, i.e., option 1. <br />


# Video Demo

![A Video](Images:\Videos/LottoGame.mp4)

# Instructions
This was compiled and ran on Mac terminal using GCC compiler

1. Run the code and a menu will appear
2. The options are:
    - i. Enter your Lotto numbers. 
    - ii. Display chosen Lotto numbers. 
    - iii. Sort chosen numbers from smallest to biggest.   
    - iv. Compare chosen Lotto numbers with winning numbers. 
    - v. Display the frequency of a chosen number since the start of the game. 
    - vi. END GAME 

# How It Works

### All function signatures are declared at the start of the code.
```C
void number_entry(int*, int*);
void number_print(int*);
void number_sort(int*);
void number_comparison(int*);
void number_frequency(int*);
```

### The menu is placed inside a do while loop to display the menu until option 6 ("EXIT") is called.
```C
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
      
        ...
    }//end do 
    while (!(input == 6));
```

### the user input is read into a switch case to identify which option to call. The switch case is located inside the do while loop
```C
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
```

### The number entry (OPTION 1) consists of a nested for loop. The outer for loop is to get 6 inputs to put in the array, the inner for loop to check if the number is already in the array. A while loop is also present in the outer for loop for error checking the program will stay in the loop until a valid number is entered. If the number is valid (no errors), it will break out the outer for loop and assign the chosen number into the array.
```C
void number_entry(int *lotto_number, int *num_freq)
{
    ...
    
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
        
        ...
        
    }//end outter for loop
    printf("\n Your Lotto numbers have been chosen. Please select option 2 to view your numbers.");
}//end number_entry()
```

### The number print function (OPTION 2) is implemented with a simple for loop which loops over every element in the array and prining the number.
```C
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
```
### The number sort function uses a simple sorting algorithm. It uses a nested for loop to check if the current number is bigger then the previous number. If so they swap position with the help of a temporary dummy variable.
```C
void number_sort(int *array_to_sort)
{
   ...
    
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
    
    ...
}//end number_sort()
```

### The number comparison function also uses a nested for loop to compare each chosen number with the winning numbers. If a number matches a counter in incremented. 
```C
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
    
    ...
    
```

### The counter is then read into a switch case. Each switch case will display the corresponding prize won.
```C
...

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
    
```

### The number frequency feature is implemented in the number entry function. The counter works by havuing an array the size of the lotto numbers (42 numbers) and when a number is chosen, the number is used as the index. The number at this index of the array is then incremented.
```C
void number_entry(int *lotto_number, int *num_freq)
{
    ...
    
    //assign chosen number into the array
    *(lotto_number+i) = num;
    //increment the frequency array for the chosen numberfor option 5
    num_freq[*(lotto_number+i)]++;
    
    ...
```

### The number inputted by the user is then validated in the number frequency function. If the number is valid. The amount of times the number has been chosen is outputted. 
```C
void number_entry(int *lotto_number, int *num_freq)
{
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
```

