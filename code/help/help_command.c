//This source code is built to provide the explicit definitions and guidelines for the commands that is to be used in this program.

#ifndef _DEFINITIONS_H_
#include "../definitions.h"
#endif

//It's very relevant here. Thus, it has its own function to be called.
void commands_and_works(){
    printf("%-15s adds a password list in this program\n", "add");
    printf("%-15s Deletes a specified list from this program.\n", "delete");
    printf("%-15s modifies a specified list\n", "modify");
    printf("%-15s lists all or a specified list\n\n", "list");
    printf("%-15s gets the list for a specified information.\n", "get");
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

        if        (strcasecmp(*(argument_variables+2), "add") == 0){
            add_command_details();
        } else if (strcasecmp(*(argument_variables+2), "delete") == 0){
            delete_command_details();
        } else if (strcasecmp(*(argument_variables+2), "list") == 0){
            list_command_details();
        } else if (strcasecmp(*(argument_variables+2), "get") == 0){
            get_command_details();
        } else if (strcasecmp(*(argument_variables+2), "modify") == 0){
            modify_command_details();
        } else {
            printf("Error: The specified command \"%s\" does not exist. Please enter a proper command name.\n", *(argument_variables+2));
        }
    } else {
        for(int i = 3; i < argument_count; i++){
            printf("Error: command \"%s\" not found. Please enter a valid command.\n", *(argument_variables+i));
        }
        exit(1);
    }
}