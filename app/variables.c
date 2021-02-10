//As it stood, looks like the array, the general variable types, in other words, 
//non composite variable types cannot be defined in the main header file. Thus, we
//are using this source code to declare the simple variable types.

//This source code defines the global single contiguous variables and functions to allocate them.

#ifndef _DEFINITIONS_H_
#include "definitions.h"
#endif

extern int content_count;
extern char *FIELDS[];

void allocate_FIELDS(void){
    FIELDS[HOST_NAME] = (char*)malloc(sizeof(char*) * (strlen("HOST NAME")+1));
    FIELDS[SUBJECT_NAME] = (char*)malloc(sizeof(char*) * (strlen("SUBJECT NAME")+1));
    FIELDS[ID] = (char*)malloc(sizeof(char*) * (strlen("ID")+1));
    FIELDS[PASS] = (char*)malloc(sizeof(char*) * (strlen("PASS")+1));

    strcpy(FIELDS[HOST_NAME], "HOST NAME");
    strcpy(FIELDS[SUBJECT_NAME], "SUBJECT NAME");
    strcpy(FIELDS[ID], "ID");
    strcpy(FIELDS[PASS], "PASS");
}

list_p allocate_LIST(void){
    list_p new_list = (list_p)malloc(sizeof(list));

    if(new_list == NULL){
        printf("Error: could not allocate the list.\n");
        exit(1);
    }
    
    return new_list;
}