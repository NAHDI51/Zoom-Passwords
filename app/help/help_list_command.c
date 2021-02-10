//This source code explicitly describes the utility and functions of list.

#ifndef _DEFINITIONS_H_
#include "../definitions.h"
#endif

char *FIELDS[4];

void list_command_details(void){
    printf("\n\nList Command\n");
    FILL(strlen("list command"), '-');
    printf("\n");
    printf("List command lists either everything or a list specified.\n\n");
    printf("i)In order to list everything:\n");
    printf("Syntax: pass list all\n");
    printf("        pass list \n\n");
    printf("Either command will work.\n\n");
    printf("ii)To list a specified list:\n");
    printf("Syntax: pass list \"FIELD\"=\"FIELD INFORMATION\"\n\n");
    printf("this command searches for the information specified on the field and lists\n");
    printf("the following list. This command works similarly to the command \"delete\".\n\n");
    printf("In the given syntax, the FIELD name is the name of one of the following\n");
    printf("fields you have entered with the add command, except for the password.\n\n");
    printf("FIELDS:\n");
    
    for(int i = 0; i < 3; i++){
        printf("=>%s\n", upper_case(FIELDS[i]));
    }

    printf("Field information is the information you have entered on the field.\n\n");
    printf("EXAMPLE:\n");
    FILL(7, '-');
    printf("\n\n");
    printf("%-13s: %s\n", "SUBJECT NAME", caps_first("mathematics"));
    FILL(15+strlen("mathematics"),'-');
    printf("\n");
    printf("%-13s: %s\n", upper_case(FIELDS[HOST_NAME]), caps_first("Maksudur Rahman"));
    printf("%-13s: %s\n", upper_case(FIELDS[ID]), "2452 2342 534");
    printf("%-13s: %s\n", upper_case(FIELDS[PASS]), "23ksnfsd");
    printf("\n");

    printf("Suppose we have a list looks like this, how can we list it?\n");
    printf("We can list it by the three following commands.\n\n");
    printf("pass list \"%s\"=\"%s\"\n", FIELDS[SUBJECT_NAME], caps_first("mathematics"));
    printf("pass list \"%s\"=\"%s\"\n", FIELDS[HOST_NAME], caps_first("Maksudur Rahman"));
    printf("pass list \"%s\"=\"%s\"\n", FIELDS[ID], caps_first("2452 2342 534"));
    printf("\n");
    printf("=>The letters in both FIELD and FIELD INFORMATION are case insensitive, earlier,\n");
    printf("  if you have typed \"subject name\" instead of \"%s\", it\n  would have worked.\n", FIELDS[SUBJECT_NAME]);
    printf("=>YOU DON'T NEED TO TYPE IN THE WHOLE FIELD INFORMATION. For instance, typing in\n");
    printf("  \"math\" instead of \"mathematics\" will fetch up all the entries with the term \n");
    printf("  \"math\" in it as a field information.\n"); 
    printf("=>In case of multiple matches for a specified field, the program will fetch up all\n");
    printf("  the lists.\n");

    return;
}