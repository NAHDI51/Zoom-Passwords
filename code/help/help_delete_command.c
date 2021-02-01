#ifndef _DEFINITIONS_H_
#include "../definitions.h"
#endif

char *FIELDS[4];

void delete_command_details(){
    printf("\n\nDelete command\n");
    FILL(strlen("DELETE COMMAND"), '-');
    printf("\n");
    printf("Delete command deletes either everything or a list specified.\n\n");
    printf("i) To delete everything:\n");
    printf("syntax: pass delete all\n\n");
    printf("ii) To delete a specified list:\n");
    printf("syntax: pass delete \"field\"=\"field_informations\"\n");
    printf("Delete command deletes a specified entry from the list of passwords.\n\n");
    printf("In the given syntax, the field name is the name of one of the following\n");
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

    printf("Suppose we have a list looks like this, how can we delete it?\n");
    printf("We can delete it by the three following commands.\n\n");
    printf("pass delete \"%s\"=\"%s\"\n", FIELDS[SUBJECT_NAME], caps_first("mathematics"));
    printf("pass delete \"%s\"=\"%s\"\n", FIELDS[HOST_NAME], caps_first("Maksudur Rahman"));
    printf("pass delete \"%s\"=\"%s\"\n", FIELDS[ID], caps_first("2452 2342 534"));
    printf("\n");
    printf("Notes:\n");
    printf("=>The letters in both FIELD and FIELD INFORMATION are case insensitive, earlier,\n");
    printf("  if you have typed \"subject name\" instead of \"%s\", it\n  would have worked.\n", FIELDS[SUBJECT_NAME]);
    printf("=>YOU DON'T NEED TO TYPE IN THE WHOLE FIELD INFORMATION. For instance, typing in\n");
    printf("  \"math\" instead of \"mathematics\" will fetch up all the entries with the term \n");
    printf("  \"math\" in it as a field information.\n"); 
    printf("=>For multiple results fetched for a given command will give you the right to make\n");
    printf("  a decision. You will be given an index number to enter, to delete the respective.\n");

    return;
}