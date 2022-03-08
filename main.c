#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    struct node *next;
    char *name;
};

/**
* Remove the top element of the stack and return its content.
*
* @head : pointer to the top of the stack
* @result : pointer to store the popped element
*
* @return 0 if no error, 1 otherwise
*
* pre : @result contains a null-terminated correct string
* post : @result contains the string @name from the element at the top of the stack
*/

int pop(struct node **head, char *result){
    struct node * ptr = * head;
    if ( ptr == NULL ) return 0;
    strcpy(result, (* ptr).name);
    * head = (* ptr).next;
    free(ptr);
    return 1;
}

/**
* Add @name at the "top" of the stack.
*
* @head : pointer to the top of the stack
* @name : the string to be placed in the element at the top of the stack
*
* @return 0 if no error, 1 otherwise
*/
int push(struct node **head, const char *value){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    if ( !ptr ) return 0;
    char * name = (char *)malloc(strlen(value)+1);
    if ( !name ) return 0;
    strcpy (name, value);
    (* ptr).name = name;
    (* ptr).next = * head;
    * head = ptr;
    return 1;
}

int main()
{
    struct node * ptr = NULL;
    int rc = 0;
    rc = push ( &ptr, "test01");
    if ( !rc ) printf("An error has occured\n");
    rc = push ( &ptr, "test02");
    rc = push ( &ptr, "test03");
    rc = push ( &ptr, "test04");
    printf("Valeur %s\n", (* ptr).name);
    char str[100] = {};
    for ( int i =1; i <= 4; i++)
    {
        rc = pop ( &ptr, str);
        printf("Valeur %s\n", (* ptr).name);
        printf("Valeur de retour %s\n", str);
    }
    return 0;
}
