#ifndef _VARIABLES_H_
#include "Variables.h"
#endif

//It's very relevant here. Thus, it has its own function to be called.
void commands_and_works(){
    printf("%-20s adds a password list in this program\n", "add");
    printf("%-20s Deletes a specified list from this program.\n", "delete");
    printf("%-20s modifies a specified list\n", "modify");
    printf("%-20s lists all or a specified list\n\n", "list");
}

//Prints the brief details of all the main commands.
void print_instructions(void){
    printf("Welcome to your password saver program.\n\n");
    printf("The commands available in this program:\n\n");
    commands_and_works();
    printf("Enter \"pass <command_name>\" to use a command.\n");
    printf("For more informations, type \"pass help <command_name>\"\n\n");
    printf("NOTE: the commands are case insensitive, but the program name is case sensitive.\nFor instance,\n");
    printf("For a following command: add,\n");
    printf("if you type \"pass AdD\" or \"pass adD\", it will work.\n");
    printf("But if you type \"PaSs add\", it will not work.\n\n");
}

//Prints the specified command into comprehensive details.
void print_command_details(int argument_count, char **argument_variables){
    /*So as we ensured the second command, the user is left with three choices.
    1. The user entered only two arguments: which is less than the required.
    2. The user entered three arguments : which is perfect.
    3. The user entered more than three arguments: which is too many for the program.
    */
    if(argument_count == 2){
        printf("Enter a command name to get help on.\n");
        printf("Syntax: \"pass help <command_name>\"\n");
        printf("Here command name refers to one of the following commands:\n\n");
        commands_and_works();
    } else if(argument_count == 3){
        //In this block, after ensuring that there are exactly three arguments,
        //We need to verify that if a valid third command line exists.

        if(strcasecmp(*(argument_variables+2), "add") == 0){
            printf("\n\nAdd command\n");
            printf("Syntax: \"pass add <command_name>\"\n\n");
            printf("add command adds a new entry to the list of passwords.\n");
            printf("Upon using this command, you will be asked to enter 4 informations.\n\n");
            printf("=>The name of the host of the meeting.\n");
            printf("=>The content or subject of the meeting\n");
            printf("=>The ID of the meeting\n");
            printf("=>The password of the meeting.\n\n");
            printf("Host name: Host name should obviously be the name of the one created\nthis hostroom.\n");
            printf("content or subject: it should be subject the meeting is being held on\nto discuss about.\n");
            printf("example: if the meeting room is about a class on \"mathematics\", the\nsubject of the meeting is \"mathematics\"");
            printf("ID of the meeting: it should only contain numbers.\n");
            printf("Pass of the meeting: The password given alongside the meeting ID.\n\n");
            printf("#What if the name of the subject I entered already exists?\n");
            printf("=>It will extend and both will appear chronologically. But be careful\nthat you cannot add more than 10");
            printf("entries in a given content or subject.\n\n");
            printf("#I have entered an information incorrectly. What can I do?\n");
            printf("=>No worries, you can modity it through the modify command. For more\n");
            printf("on modify, please refer to the modify command.\n\n");
        }
    }
}