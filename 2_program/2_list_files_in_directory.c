/*
Program to list the files in present working directory.
*/
/******************************************************************************
 *
 * @file    program file operation.c
 * @author  Kevil Patel
 * @brief   This program show how to use c program to list the file in directory
 * @date    FEB/09/2018,Created
 *****************************************************************************/
/******************************************************************************
The program works in following manner:
1. dirent.h used to opendir() and readdir() function. 
2. opendir() function open the working directory.
3. if directory open successfully it read the directory file using readdir()
*****************************************************************************/

/***************
 * Include Files
 ***************/
#include <dirent.h>     //used to perform direcory related operation.
#include <stdio.h>

/** Function    main
 * @date        FEB/09/2018
 * @brief       Main function of the program.
 * @param       struct dirent *pdir *: defined in dirent.h(used to perform directory related operation.) 
 * @return      int: the result of execution.
 *              0: success
 */
int main(void)
{
    DIR *directory;
    struct dirent *pdir;
    directory = opendir(".");
    if(directory)
    {
        while((pdir=readdir(directory))!=NULL)
        {
            printf("%s\n",pdir->d_name);
        }
        closedir(directory);
    }
    return(0);
}   //End of main.