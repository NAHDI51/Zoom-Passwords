#ifndef _DEFINITIONS_H_
#include "definitions.h"
#endif

int main(int argc, char **argv)
{
    //First and foremost, call the global variable allocator functions.
    allocate_FIELDS();

    //Copy out the argv arguments in a multidimensional array. Allocate a multidimensional string with the corresponding 
    //size of each argv[i].
    //Reason: It is recommended not to manipulate the value of argv, as it has the tendency to cause 
    //segmentation fault.

    char **copy_argv = (char**)malloc(sizeof(char**) * argc);
    for(int i = 0; i < argc; i++){
        *(copy_argv + i) = (char*)malloc(sizeof(char*) * strlen(*(argv+i)));
        strcpy(*(copy_argv+i), *(argv+i));
    }
   
    if(argc < 2){
        print_instructions();
    }else{
        //compare the second command line with many others. If it happens to match, initialize the corresponding function,
        //else, return no commands message.
        //This lexicographical block solely manipulates the second command line argument.

        if(strcasecmp(*(copy_argv+1), "help") == 0){
            print_command_details(argc, copy_argv);
        } else if (strcasecmp(*(copy_argv+1), "add") ==  0){
            add_list(argc, copy_argv);
        } else {
            printf("Error: command \"%s\" not found. Please use a valid command.\n", *(copy_argv+1));
        }
    }
    return 0;
}