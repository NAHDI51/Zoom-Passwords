/*
<Variables.h>

this header file defines all the global variables to be used throughout the codes of the project.
Feel free to change.
*/

#define _VARIABLES_H_

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

//So basically our structure will be called list.
typedef struct creditentials list;
typedef char* name_of;
typedef list* list_p;

struct creditentials{
    name_of *hoster;
    name_of *category;
    char **ID;
    char **pass;
    list_p prev, next;
    int entries;                    //Entries can't be bigger than 10, no matter what.
};

void print_instructions(void);
void commands_and_works();
void  print_command_details(int argument_count, char **argument_variables);