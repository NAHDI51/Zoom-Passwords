#ifndef _DEFINITIONS_H_
#include "../definitions.h"
#endif

char *FIELDS[4];

void get_command_details(void)
{
    printf("get Command\n");
    FILL(strlen("get command"), '-');
    printf("\n");
    printf("get command gets a certain field for a specified information, and lets you modify it.\n");
    printf("[NOTE: You can also directly modify it through the modify command]\n\n");
    printf("Syntax: pass get \"FIELD\"=\"FIELD INFORMATION\"\n");
    printf("[NOTE: Not specifying the FIELD will default the search to the FIELD \"%s\".]\n\n", FIELDS[SUBJECT_NAME]);
    printf("In the given syntax, the FIELD name is the name of one of the following\n");
    printf("FIELDS you have entered with the add command, except for the password.\n\n");
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

    printf("Suppose we have a list looks like this, how can we get it?\n");
    printf("We can get it by the three following commands.\n\n");
    printf("pass get \"%s\"=\"%s\"\n", FIELDS[SUBJECT_NAME], caps_first("mathematics"));
    printf("-takes the information for the field \"%s\" and retreives the list.\n\n", FIELDS[SUBJECT_NAME]);
    printf("pass get \"%s\"=\"%s\"\n", FIELDS[HOST_NAME], caps_first("Maksudur Rahman"));
    printf("-takes the information for the field \"%s\" and retreives the list.\n\n", FIELDS[HOST_NAME]);
    printf("pass get \"%s\"=\"%s\"\n", FIELDS[ID], caps_first("2452 2342 534"));
    printf("-takes the information for the field \"%s\" and retreives the list.\n\n", FIELDS[ID]);
    printf("pass get \"%s\"\n", caps_first("mathematics"));
    printf("Since there is no field specified, it will be defaulted to the FIELD: \"%s\"\n\n", FIELDS[SUBJECT_NAME]);
    printf("\n");
    printf("After fetching one or multiple specified lists, you will be asked to choose one of the\nfollowing:\n\n");
    printf("=>Delete (D)\n");
    printf("=>Modify (M)\n");
    printf("=>Quit   (Q)\n");
    printf("\n");
    printf("Upon choosing Delete, the system will delete the entry once and for all.\n");
    printf("Upon choosing modify, you will be asked to enter the field and information you want to\nModify.");
    printf("Please refer to the modify command for more details.\n\n");
    printf("[NOTE: For multiple lists fetched, the indexes of the list will be given and you'll have\n");
    printf("to enter the index number for the list you want. Press Q to quit.]\n\n");

    printf("Notes:\n");
    printf("=>The letters in both FIELD and FIELD INFORMATION are case insensitive, earlier,\n");
    printf("  if you have typed \"subject name\" instead of \"%s\", it\n  would have worked.\n", FIELDS[SUBJECT_NAME]);
    printf("=>YOU DON'T NEED TO TYPE IN THE WHOLE FIELD INFORMATION. For instance, typing in\n");
    printf("  \"math\" instead of \"mathematics\" will fetch up all the entries with the term \n");
    printf("  \"math\" in it as a field information.\n"); 
    printf("=>For multiple results fetched for a given command will give you the right to make\n");
    printf("  a decision. You will be given an index number to enter, to get the respective.\n");

    return;
}