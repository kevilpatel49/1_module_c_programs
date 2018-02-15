/*
Program which reverse the linked list.
*/
/******************************************************************************
 *
 * @file    reverse linked list.c
 * @author  Kevil Patel
 * @brief   this program reverse the linked list.
 * @date    FEB/09/2018,Created
 *****************************************************************************/
/******************************************************************************
The program works in following manner:
1. the number is apend n linked list through push function.
2. the linked list is reverse through reverse function.
3. printList is used to print the linkied list.
*****************************************************************************/

/***************
 * Include Files
 ***************/
#include <stdio.h>
#include <stdlib.h>

/**********************
 * structure declaration.
 **********************/
struct Node;
/******************************
 * Function Prototypes
 *****************************/
static void reverse(struct Node** head_ref);
void push(struct Node** head_ref, int new_data);
void print_list(struct Node *head);

/************************************************************************************
 * structure
 * struct Node: contain the variables and self referencing struct node* next.
 * @int data: used to store the number.
 * @struct Node* next: self referencing node.
 ***********************************************************************************/
struct Node
{
    int data;
    struct Node* next;
};
 

/** Function    main
 * @date        FEB/09/2018
 * @brief       Main function of the program.
 * @param		struct Node* head: it is head of the node(NULL indicate it is empty node).
 * @return      int: the result of execution.
 *		        0: success
 */
int main(void)
{
	struct Node* head = NULL;
    push(&head,457);
    push(&head,879);
    push(&head,40); 
    push(&head,32);      
    push(&head,7);
    push(&head,63);

    printf("given linked list\n");
    print_list(head);    
    reverse(&head);                      
    printf("\nreversed Linked list \n");
    print_list(head);
    return 0;
}	//End of main
    
/** Function    reverse
 * @date        FEB/09/2018
 * @brief       reverse the linked list.
 * @param		struct Node* prev: used to store the previous node.
 				struct Node* current: store the curent node.
 				struct node* next: represent next node.
 * @return      void: return nothing.
 */
static void reverse(struct Node** head_ref)
{
    struct Node* prev   = NULL;
    struct Node* current = *head_ref;
    struct Node* next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *head_ref = prev;
}	//End of reverse.

/** Function    push
 * @date        FEB/09/2018
 * @brief       push the data inside the node.
 * @param		struct Node* new_node: new allocated node(allocated memory using malloc).
 * @return      void: return nothing.
 */
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=new_data;
    new_node->next=(*head_ref);    
    (*head_ref)=new_node;
}	//End of push


/** Function    printList
 * @date        FEB/09/2018
 * @brief       print the linked list data.
 * @param		struct Node* temp: temp node used to contain the head(used in while loop until it will no reach to end of node(NULL)).
 * @return      void: return nothing.
 */
void print_list(struct Node *head)
{
    struct Node *temp = head;
    while(temp != NULL)
    {
        printf("%d  ",temp->data);    
        temp=temp->next;  
    }
}	//End of print_list.