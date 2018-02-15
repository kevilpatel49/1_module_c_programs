/*
program to sort the given array using function pointer(using qsort() with compare function.
*/
/******************************************************************************
 *
 * @file    program sorting array using function pointer and qsort().c
 * @author  Kevil Patel
 * @brief   This program show how to use qsort() function with function pointer to
 			perform the array sorting.
 * @date    FEB/09/2018,Created
 *****************************************************************************/
/******************************************************************************
The program works in following manner:
1. the integer type of array is given.
2. qsort function is defined in stdlib.h which is used to sort the array. but to perform sorting 
   need a function which compare the values and sort the array.
3. compare function is used to compare the two element of the number.
   Ex: second_element - first_element
4. according to the difference between array element it will perform the sorting. 
*****************************************************************************/

/***************
 * Include Files
 ***************/
#include <stdio.h>
#include <stdlib.h>

/************************************
 * Function Prototypes
 ************************************/
int compare(const void*, const void*);

/** Function    main
 * @date        FEB/09/2018
 * @brief       Main function of the program.
 * @param       int: arra[]: array to store the integer number.
 				int: count: count number of array.
 * @function    int (*cmp)(const void*,const void*): used as a function pointer.
 * @return      int: the result of execution.
 *              0: success
 */
int main(void)
{
	int (*cmp)(const void*,const void*);
	cmp=&compare;
	int array[]={7,8,9,1,2,3,6,5,4};
	int count=0;
	qsort(array, sizeof(array)/sizeof(*array), sizeof(*array), cmp);	//qsort function(check its last argument cmp)
	while(count < (sizeof(array)/sizeof(*array)))
	{
		printf("%d\t",array[count]);
		count++;
	}
	printf("\n");
	return 0;
}	//End of main


/** Function    compare
 * @date        FEB/09/2018
 * @brief       compare the two numbers.
 * @param       void* left: the first element of array.
 				void* right: the second element of array.
 * @return      int: difference between two array element.
 */
int compare(const void* left,const void* right)
{
	return (*(int*)right - *(int*)left);
}	//End of compare