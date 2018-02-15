/*
program demonstrating the use of function pointer with structure to perform addition and subtraction.
*/
/******************************************************************************
 *
 * @file    program on function pointer with structure.c
 * @author  Kevil Patel
 * @brief   This program show how to use function pointer with the structure to perform
 			addition and subtraction.
 * @date    FEB/09/2018,Created
 *****************************************************************************/
/******************************************************************************
The program works in following manner:
1. there is one function pointer called maths_operation() used to perform maths operation. 
2. the structure is maintained to store the necessary number for maths operation.
3. the add and sub function are used to perform the addition and subtraction. these functions
   pass as a address to the maths_operation.
*****************************************************************************/

/***************
 * Include Files
 ***************/
#include <stdio.h>

/**********************
 * Function Prototypes
 *********************/
int add(int, int);
int sub(int, int);

/******************
 * function pointer
 *****************/
typedef int (*maths_operation)(int ,int);

/************************************************************************************
 * structure
 * struct maths_number: contain the variables to store information like number results
   switch_number and function pointer.
 * @int number_1: used to store the number.
 * @int number_2: used to store the number.
 * @int result: used to store result after operation.
 * @maths_operation: function pointer which return type is integer and arguments is int.
 ***********************************************************************************/
typedef struct maths_number			
{
	int number_1;
	int number_2;
	int result;
	maths_operation calculator;			/*<-----function pointer*/
}maths_number;

/** Function    main
 * @date        FEB/09/2018
 * @brief       Main function of the program.
 * @param       short int: switch_number: used to select the operation. 
 				maths_number: obj: object of the structure. its work same as a class and its 
 				                   object in OOP concept.
 * @return      int: the result of execution.
 *              0: success
 */
int main(void)
{
	unsigned short int switch_number;
	maths_number obj;
	printf("please choose any option\n");
	printf("1-Addition\n");
	printf("2-subtraction\n");
	scanf("%hu",&switch_number);
	switch(switch_number)
	{
		case 1:
			printf("please enter two number\n");
			scanf("%d %d",&obj.number_1,&obj.number_2);
			obj.calculator=add;		//pass the adddress of the add()
			obj.result=obj.calculator(obj.number_1,obj.number_2);
			printf("the result is %d\n",obj.result);
			break;
		case 2:
			printf("please enter two number\n");
			scanf("%d %d",&obj.number_1,&obj.number_2);
			obj.calculator=sub;		//pass the adddress of the sub()
			obj.result=obj.calculator(obj.number_1,obj.number_2);
			printf("the result is %d\n",obj.result);
			break;
		default:
			printf("invalid choice. please select valid number\n");
	}
}	//End of main

/** Function    add
 * @date        FEB/09/2018
 * @brief       this function perform addition operation.
 * @param       int: num_1: store the number.
 				int: num_2: store the number.
 * @return      int: return the number after addition.
 */
int add(int num_1, int num_2)
{
	return num_1 + num_2;
}	//End of add

/** Function    sub
 * @date        FEB/09/2018
 * @brief       this function perform addition operation.
 * @param       int: num_1: store the number.
 				int: num_2: store the number.
 * @return      int: return the number after subtraction.
 */
int sub(int num_1, int num_2)
{
	return num_1 - num_2;
}	//End of sub