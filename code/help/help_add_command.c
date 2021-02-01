#ifndef _DEFINITIONS_H_
#include "../definitions.h"
#endif

void add_command_details(){
     printf("\n\nAdd command\n");
            printf("Syntax: \"pass add\"\n\n");
            printf("add command adds a new entry to the list of passwords.\n");
            printf("Upon using this command, you will be asked to enter 4 informations.\n\n");
            printf("=>The name of the host of the meeting.\n");
            printf("=>The content or subject of the meeting\n");
            printf("=>The ID of the meeting\n");
            printf("=>The password of the meeting.\n\n");
            printf("Host name: Host name should be the name of the one created\n\tthis hostroom.\n");
            printf("content or subject: it should be subject the meeting is being held on\n\tto discuss about.\n");
            printf("example: if the meeting room is about a class on \"mathematics\", the\n\tsubject of the meeting is \"mathematics\"");
            printf("ID of the meeting: it should\n\tonly contain numbers.\n");
            printf("Pass of the meeting: The password given alongside the meeting ID.\n\n");
            printf("#What if the name of the subject I entered already exists?\n");
            printf("=>It will extend and both will appear chronologically. But be careful\nthat you cannot add more than 10");
            printf("entries in a given content or subject.\n\n");
            printf("#I have entered an information incorrectly. What can I do?\n");
            printf("=>No worries, you can modity it through the modify command. For more\n");
            printf("on modify, please refer to the modify command.\n\n");\

     return;
}

