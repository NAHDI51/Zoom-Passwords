#ifndef _DEFINITIONS_H_
#include "../definitions.h"
#endif

#ifndef _UNISTD_H_
#include <unistd.h>
#endif

#ifndef _DIRENT_H_
#include <dirent.h>
#endif

#ifndef _STAT_H_
#include <sys/stat.h>
#endif

void list_funcs(int argc, char** argv){
    int listed = 0;
    int total_files = 0;

    //Since we will work on the main directory most frequently, change the current directory.
    chdir("..");

    int folder_exist = folder_exists(".", "counts");
    if(!folder_exist){
        printf("You have not entered any list yet. enter \"pass add\" to add a list.\n");
        return;
    }

    //files and readers defined below.
    DIR* count_dir = opendir("counts");
    DIR* data_dir = opendir("data");
    if(data_dir == NULL || count_dir == NULL){
        fprintf(stderr, "list/list_funcs.c Line: 31 Error: Could not open the file.\n");
        exit(1);
    }

    struct dirent *count_read;
    struct dirent *data_read;

    struct stat count_stats;
    struct stat read_stats;

    /*I have specified three instances of usages of the list command.

    1. no third argument specified.
    2. Third argument specified, but no field specified.
    3. field and argument both specified.

    So let's make these three the turning factors of the program, upon which the program will take action.
    */

    list_p current_list = (list*)malloc(sizeof(list));  //The list on which the structure is to be written on.


        //These are the universal work. I'll have to read the datas from the files  ultimately.
        //However, the lists I'll have to print is the variable here. It solely depends on the command.
        //So it will be like that:
        //After doing the universal works, we will switch to local works, according to the command, we will excecute the local works.
        //All the types of possible commands are defined above.

    //we will have to create some sort of differentiator in order to differentiate our command.

    if(argc == 3){
        //If argc, is equal to 3, we have the additional command specified to work in different situations.
        typedef struct instrcution{
            int number;
            char *specifier;
        }instructions;
        //These will work as the key specifiers in our operation.
        
        instructions *fields = (instructions*)malloc(sizeof(instructions));

        char *equal_sign = strstr(argv[2], '=');
        if(equal_sign == NULL){
            if(strcasecmp(argv[2], ".") == 0){
                fields->number = 4;
                //We don't need to specify the character field, as it will be extraneous.
            } else {
                //Otherwise, we can determine that the subject is a field.
                int length = 0;
                for(int i = 0; *(argv + i) != '\0'; i++) length++;
                fields->specifier = (char*)malloc(length+1);

                for(int i = 0; *(argv+(i-1)) != '\0'; i++){
                    fields->specifier[i] = *(argv+i);
                }
                fields->specifier = SUBJECT_NAME;

                //basically what we have done in that column is to fill out the specifiers.
            }
        } else {
            *equal_sign = '\0';
            int length = 0;

            for(int i = 1; *(equal_sign + i) != '\0'; i++) length++;
            fields->specifier = (char*)malloc(length+1);
            for(int i = 1; *(equal_sign + i) != '\0'; i++){
                
            }
        }
    }

        while(((data_read = readdir(data_dir)) != NULL) || ((count_read = readdir(data_dir)) != NULL)){
            /*algorithm:
            1. make a file pointer that indicates to the count file.
            2. Read that file and scan the first number of the file.
            3. start a loop for the number, and start fetching the structures. Write them on the current_list.
            4. print it to the stdout.
            */

           char *count_name = (char*)malloc(strlen(count_read->d_name) + strlen("/counts") + 2);
           if(count_name == NULL){
               fprintf(stderr, "list/list_funcs.c Line 66: Error: could not allocate the required memory.\n");
               exit(1);
           }
           strcpy(count_name, "counts/");
           strcat(count_name, count_read->d_name);

           FILE* count_file = fopen(count_name, "r");
           if(count_file == NULL){
               fprintf(stderr, "list/list_funcs.c Line 74: Error: Could not open the file.\n");
               exit(1);
           }

           char *file_name = (char*)malloc(strlen());

           int entries;
           fscanf(count_file, "%d", &entries);
            
           for(int i = 0; i < entries; i++){
                fread(current_list, sizeof(list), 1, )   
           }
        }
}