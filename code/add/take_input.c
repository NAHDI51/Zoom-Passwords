#ifndef _DEFINITIONS_H_
#include "../definitions.h"
#endif

/*source code of the main function off add
    What the add command does:
    -Takes off the input from the user.
    -saves the input in the disk, with the subject's name as the name of the file, on ../../datas/SUBJECT_NAME.dat
*/

list_p add_take_input(int argc, char **argv)
{
    if(argc > 2){
        for(int i = 2; i < argc; i++){
            printf("Error: \"%s\" is not a command. Please enter a valid command.\n", *(argv+i));
        }
        exit(1);
    } else if(argc == 2){
        list_p new_list;
        new_list = allocate_LIST();

        //This function will here take 4 inputs: 
        /*
        =>Host Name
        =>Subject Name
        =>ID
        =>Pass

        the input will be taken with the 100 character string input and will be saved on the list.
        */

       /*Each of them has definite criterias.
       =>NAME: Must not contain any numbers and notations.
       =>SUBJECT NAME: No contraints, may contain any sumbol or notation.
       =>ID: Cannot contain any letters, symbols and notations.
       =>PASS: Can contain anything.

       The following functions for measuring these criterias are defined in the source code "../formatting_functions.c". They are:
       =>does_not_contain_number(sentence)
       =>does_not_contain_symbol(sentence)
       =>does_not_contain_letter(sentence)

       In order to format the sentences, the following defined functions are:
       =>break_new_line(sentence) //eliminates the last unnecessary newline when taken input
       =>caps_first(sentence)        //Makes the first letters of the words of the following sentence capital and the rest small.
       =>no_spaces_first(sentence)   //Eliminates the gaps left before starting a sentence
       */

       int decision = true;
       int key = 0;

       printf("\n***Enter Q to quit***\n\n");

       while(key < 4){
            decision = true;

           while(decision){
               char *input = (char*)malloc(sizeof(char*) * 100);
               switch(key){

                    case SUBJECT_NAME:
                        printf("Enter the name of the subject: ");
                        break;
                    case HOST_NAME:
                        printf("Enter the name of the Host: ");
                        break;
                    case ID:
                        printf("Enter the ID number: ");
                        break;
                    case PASS:
                        printf("Enter the Password: ");
                        break;
               }
                fgets(input, 98, stdin);

                break_new_line(&input);
                no_spaces_first(&input);

                if(strcmp(input, "Q") == 0){
                    key = 4;
                    decision = false;
                    break;
                    }

                switch (key)
                {
                    case SUBJECT_NAME:
                        input = upper_case(input);

                        if((does_not_contain_symbol(input))){
                            decision = false;
                        } else if (has_comma(input)){
                            decision = false;
                        } else {
                            printf("[YOU CAN'T ENTER ANY SYMBOL EXCEPT COMMA] ");
                        }
                        break;
                
                    case HOST_NAME:
                        input = caps_first(input);
                        if((does_not_contain_number(input)) && (does_not_contain_symbol(input))){
                            decision = false;
                        } else {
                            printf("[NAME CANNOT CONTAIN ANY NUMBERS OR SYMBOLS] ");
                        }
                        break;

                }
               free(input);
               fflush(stdin);
           }
           key++;
       }
       if(key == 5){
           printf("Program Terminated.\n");
           exit(0);
       }
    }
}