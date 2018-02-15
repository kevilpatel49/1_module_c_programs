/*
Program which Converts an Integer to String & vice-versa
*/
/******************************************************************************
 *
 * @file    program_on_pointer.c
 * @author  Kevil Patel
 * @brief   This program illustrate the conversion from integer to string and vice-versa.
 * @date    FEB/09/2018,Created
 *****************************************************************************/
/******************************************************************************
The program works in following manner:
1. User can enter the integer number in consoles. 
2. That number pass to the my_itoa() function, which convert the integer number to string.
   Ex:- num=1234, its output is "1234" as a string.
3. Same as my_atoi() is implemented, which convert the string to the integer.

CONSTRAINTS:
1. User can not enter the integer number more than -2^63+1 to +2^63-1.
*****************************************************************************/

/***************
 * Include Files
 ***************/
#include <stdio.h>
#include <string.h>
#include <math.h>

/******************************
 * Function Prototypes
 *****************************/
void my_itoa(char *, long long);
long long my_atoi(char *);


/** Function    main
 * @date        FEB/09/2018
 * @brief       Main function of the program.
 * @param		char *:str: to store the string. 
 				int long long: num: to store number.
 				int long long: result: store the integer number, which is converted to integer from string.
 * @return      int: the result of execution.
 *		        0: success
 */
int main(void)
{
    char *str;
    long long num=0, result=0;
    printf("enter a number: ");
    scanf("%lld", &num);
    my_itoa(str, num);
    printf("number converted to string: %s\n", str);
    result = my_atoi(str);
    printf("number converted back to integer: %lld\n", result);
    return 0;
}	// End of main


/** Function    my_itoa
 * @date        FEB/09/2018
 * @brief       this function convert the integer number to string.
 * @param		char *:str: character pointer reference. 
 				int long long: num: to pass the numbe taken from main function.
 				int: index: used for loop.
 				int: rem: to store reminder.
 				int: len: length of the number.
 				int: temp: used in while loop.
 * @return      void: return nothing.
 */
void my_itoa(char *str, long long num)
{
    int index=0, rem=0, len=0, temp=0;
    temp=num;
    //find the length of the number.
    while(temp!=0)
    {
        len++;
        temp /= 10;
    }
    for (index=0;index<len;index++)
    {
    	//logic to convert integer to string.
        rem=num % 10;
        num=num / 10;
        str[len-(index+1)]=rem+'0';
    }
    str[len] = '\0';
}	//End of my_itoa


/** Function    my_atoi
 * @date        FEB/09/2018
 * @brief       this function convert the string to integer number.
 * @param		char *:str: character pointer reference. 
 				int: index: used for loop.
 				int: rem: to store reminder.
 				int: len: length of the string.
 * @return      long long: return integer number.
 */
long long my_atoi(char *str)
{
    int len=strlen(str);
    int index=0;
    long long num = 0;
    for (index=0;index<len;index++)
    {
    	//logic to convert the string to integer number.
        num=num+((str[len-(index+1)]-'0')*pow(10,index));
    }
    return num;
}	//End of my_atoi