/*
<definitions.h>

this header file defines all the global variables to be used throughout the codes of the project.
Feel free to change.
*/

#define _DEFINITIONS_H_

#ifndef _STDIO_H_
#include <stdio.h>
#endif //includes stdio.h if not added previously.

#ifndef _STDLIB_H_
#include <stdlib.h>
#endif //includes stdlib.h if not added previously.

#ifndef _STRING_H_
#include <string.h>
#endif //includes string.h if not added previously.

#ifndef _CTYPE_H_
#include <ctype.h>
#endif //includes ctype.h if not added previously.

#ifndef _STDBOOL_H_
#include <stdbool.h>
#endif //includes stdbool.h if not added previously.

#define SUBJECT_NAME    (0)
#define HOST_NAME       (1)
#define ID              (2)
#define PASS            (3)

//So basically our structure will be called list.
typedef struct creditentials list;
struct list_linked_list linked_list;
typedef list* list_p;

//This struct is basically used for storing the structures in the disk.
struct creditentials{
    char *host;
    char *subject;
    char *id;
    char *pass;
};

//upon fetching multiple results for the function search, this list will link them so that the structures can be tracked.
struct list_linked_list{
    list credits;
    list_p next;
    list_p prev;
};


//The following function declared below are dedicated help functions.
void commands_and_works(void);          //breifly describes the standard commands and their destined works.
void add_command_details(void);         //explicitly describes the functionalities and facilities and the usage of the command add.
void delete_command_details(void);      //explicitly describes the functionalities and facilities and the usage of the command delete.
void list_command_details(void);        //explicitly describes the fucntionalities and facilities and the usage of the command list.
void get_command_details(void);         //explicitly describes the functionalities and facilities and the usage of the command get.
void modify_command_details(void);      //explicitly describes the functionalities and facilities and the usage of the command modify.
void print_command_details(int argument_count, char **argument_variables);  //dispences and redirects the commands and their paths according to the input taken.
void print_instructions(void);          //the general entry of the program.

//As we know, the array cannot be used without proper allocation. Thus, this
//function allocates the area to be used for the function manually. Use this
//once and ONLY once.

//functions used for defining some global variables.
void allocate_FIELDS(void);

//formatting functions
void FILL(int quantity, char character);                 //Fills a "quantity" of space with a certain "Character".
char first_of(char *key);                                 //Returns first character.
void no_spaces_first(char **sentence);                    //Removes the unncesssary spaces at the beginning of a sentence
void break_new_line(char **sentence);                      //Breaks the last newline of a sentence.
char *upper_case(char *sentence);                         //Sentence capped.
char *caps_first(char *sentence);                         //Caps Locks the first letter of the sentence.
int verify_number(char *id);                              //Checks if the sentence is made of basic numbers
int addition_string(char *sentence);                      //The sum of the ASCII values of the string.
int char_case_compare(char a, char b);                         //Compares two characers, ignoring their cases.
void swap(char *a, char *b);


