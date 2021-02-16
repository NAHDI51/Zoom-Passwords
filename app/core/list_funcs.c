#ifndef _DEFINITIONS_H_
#include "../definitions.h"
#endif

#ifndef _UNISTD_H
#include <unistd.h>
#endif

#ifndef _DIRENT_H_
#include <dirent.h>
#endif

#ifndef _STAT_H_
#include <sys/stat.h>
#endif

char *FIELDS[4];

void list_funcs(int argc, char** argv, int mode){

    void (*redirector[3])(list_p, int) = {&get_command, &modify_command, &delete_command};

    int folder_exist = folder_exists(".", "counts");
    if(!folder_exist){
        printf("You have not entered any list yet. enter \"pass add\" to add a list.\n");
        return;
    }

    /*I have specified three instances of usages of the list command.

    1. no third argument specified.
    2. Third argument specified, but no field specified.
    3. field and argument both specified.

    So let's make these three the turning factors of the program, upon which the program will take action.
    */


        //These are the universal work. I'll have to read the datas from the files  ultimately.
        //However, the lists I'll have to print is the variable here. It solely depends on the command.
        //So it will be like that:
        //After doing the universal works, we will switch to local works, according to the command, we will excecute the local works.
        //All the types of possible commands are defined above.

    //we will have to create some sort of differentiator in order to differentiate our command.


     typedef struct instrcution{
            int number;         //The number will compare the key number of the 4 string array.
            char *specifier;    //It will work as the information of the required field.
        }instructions;
        //These will work as the key specifiers in our operation.

    instructions *fields = (instructions*)malloc(sizeof(instructions));
    if(fields == NULL){
        printf("list/list_funcs.c Line 56: Error: Could not allocate the list.\n");
        exit(1);
    }

    if(argc == 2){
        if(mode == called_for_list){
            fields->number = 4;
        } else if ((mode == called_for_modify) || (mode == called_for_get) || (mode == called_for_delete)) {
            printf("\nPlease specify a field and a field information. For more details, Please refer\n");
            printf("to the list help, command: \"pass help list\"");
            exit(1);
        }
    }

    if(argc == 3){
        //If argc, is equal to 3, we have the additional command specified to work in different situations.

        char *equal_sign = strstr(argv[2], "=");
        if(equal_sign == NULL){
            if((mode == called_for_list) && (strcasecmp(argv[2], "all") == 0)){
                fields->number = 4;
                //We don't need to specify the character field, as it will be extraneous.
            } else {
                //Otherwise, we can determine that the field is a subject.
                int length = 0;
                for(int i = 0; *(argv + i) != '\0'; i++) length++;
                fields->specifier = (char*)malloc(length+1);

                for(int i = 0; *(argv+(i-1)) != '\0'; i++){
                    fields->specifier[i] = *(*(argv+2) + i);
                }
                fields->number = SUBJECT_NAME;

                //basically what we have done in that column is to fill out the specifiers.
            }
        } else if(equal_sign != NULL) {

            *equal_sign = '\0';
            int length = 0;

            for(int i = 1; *(equal_sign + i) != '\0'; i++){
                length++;
            }
            fields->specifier = (char*)malloc(length+3);
            if(fields->specifier == NULL){
                fprintf(stderr, "list/list_funcs.c Line 101: Error: Could not allocate the list.\n");
                exit(1);
            }

            int i;
            for(i = 1; *(equal_sign + i) != '\0'; i++){
                fields->specifier[i-1] = *(equal_sign+i);
            }
            fields->specifier[i-1] = '\0';

            //Eliminate if the user has entered an invalid input.
            if(strcasecmp(argv[2], "subject name") == 0){
                fields->number = SUBJECT_NAME;
            } else if (strcasecmp(argv[2], "host name") == 0){
                fields->number = HOST_NAME;
            } else if (strcasecmp(argv[2], "ID") == 0){
                fields->number = ID;
            } else {
                printf("\nPlease enter a proper field. To know more about fields, enter \"pass help list\"\n");
                exit(1);
            }
        }
    }
    if(argc > 3){
        printf("You have entered too many commands. Please checkout the rules for using commands.\n");
        return;
    }
    
    int got_list = false;
    int printed_list = false;
    int total_entries = 0;      //increment for each entry iteration.
    int index;                  //index the program will ask for after listing the entries.


    while(!got_list){
         //files and readers defined below.
        DIR* count_dir = opendir("counts");
        DIR* data_dir = opendir("data");
        if(data_dir == NULL || count_dir == NULL){
            fprintf(stderr, "list/list_funcs.c Line: 140 Error: Could not open the file.\n");
            exit(1);
        }
        //Our main work is on the following two directory: count and data.
        //Therefore, every variable starting with the word count refers to every one of the variable of the directory "count".
        //On the contrary, data refers to every variable of the files inside the directory, "data".

        struct dirent *count_read;
        struct dirent *data_read;

        struct stat count_stats;
        struct stat read_stats;
        int total_files = 0;        //increment for each file iteration.

        int listed = 0;             //increment for each successfully printed list
        char str_listed[6];         //string converted version of the variable listed.

        while((data_read = readdir(data_dir)) != NULL){
            /*algorithm:
            1. make a file pointer that indicates to the count file.
            2. Read that file and scan the first number of the file.
            3. start a loop for the number, and start fetching the structures. Write them on the current_list.
            4. print it to the stdout.
            */
           count_read = readdir(count_dir);

           total_files++;
           if(total_files <= 2){
               continue; 
           }

           char *count_name = (char*)malloc(strlen(count_read->d_name) + strlen("/counts") + 2);
           if(count_name == NULL){
               fprintf(stderr, "list/list_funcs.c Line 173: Error: could not allocate the required memory.\n");
               exit(1);
           }
           strcpy(count_name, "counts/");
           strcat(count_name, count_read->d_name);

           FILE* count_file = fopen(count_name, "r");
           if(count_file == NULL){
               fprintf(stderr, "list/list_funcs.c Line 181: Error: Could not open the file.\n");
               exit(1);
           }

           char* file_name = (char*)malloc(strlen(data_read->d_name) + 8);
           if(file_name == NULL){
               fprintf(stderr, "list/list_funcs.c Line 187: Error: Could not allocate the required memory.\n");
               exit(1);
           }
            strcpy(file_name, "data/");
            strcat(file_name, data_read->d_name);

           FILE* data_file = fopen(file_name, "rb");
           if(data_file == NULL){
               fprintf(stderr, "list/list_funcs.c Line 195: Error: Could not allocate the required memory.\n");
               exit(1);
           }

           int entries;
           int entry_listed = 0;        //entries listed for each subject.
           fscanf(count_file, "%d", &entries);
            
           for(int i = 0; i < entries; i++){
               list_p current_list = (list*)malloc(sizeof(list));  //The list on which the structure is to be written on.
               if(current_list == NULL){
                   fprintf(stderr, "list/list_funcs.c Line 206: Error: could not allocate memory.\n");
                   exit(1);
               }
                total_entries++;
                fread(current_list, sizeof(list), 1, data_file);
                
                //This is where our local operation starts in. The program will fetch and print results based on 
                //What the user has asked.

                //We will basically get divided into four different options for four different commands.
                
                //Procedures:
                /*
                1. For fields->number == 4, we will basically print them all out.
                2. For 3 >= fields->number >= 0, we will print compare them to the index number of current_list->credits,
                   and will print them out if matches.
                */

               if(fields->number == 4){
                        if(entry_listed == 0){
                            FILL(60, '=');
                            printf("|");
                            printf("\n");
                            printf("%-14s: %-44s|\n", FIELDS[SUBJECT_NAME], current_list->credit[SUBJECT_NAME]);
                            FILL(60, '=');
                            printf("|");
                            printf("\n%-60s|\n", " ", " ");
                        }
                        entry_listed++;
                        listed++;
                        //The difference between two listed is that one is global, and the other one is local.
                        printf("%-5s.....%-50s|\n", itoa(listed, str_listed, 10), " ");

                        for(int j = 1; j < FIELD; j++){
                             printf("%-14s: %-44s|\n", FIELDS[j], current_list->credit[j]);
                        }
                        printf("%-60s|\n", " ");
                        if(i != entries -1){                
                            FILL(60, '-');
                            printf("|\n");
                        }

               } else if (fields->number >= 0 && fields->number <= 2){
                   if(strcasestr(current_list->credit[fields->number], fields->specifier) != NULL){
                       //In this column, we can assume that the list meets our criteria, therefore, can work on it.
                       //On first iteration, it will print out the entries.
                       //On second itertion, it will search for one of the entry.

                       if(!printed_list){
                            if(entry_listed == 0){
                                FILL(60, '=');
                                printf("|");
                                printf("\n");
                                printf("%-14s: %-44s|\n", FIELDS[SUBJECT_NAME], current_list->credit[SUBJECT_NAME]);
                                FILL(60, '=');
                                printf("|");
                                printf("\n%-60s|\n", " ", " ");
                            }
                            entry_listed++;
                            listed++;
                            //The difference between two listed is that one is global, and the other one is local.
                   
                            printf("%-5s.....%-50s|\n", itoa(listed, str_listed, 10), " ");

                            for(int j = 1; j < FIELD; j++){
                                printf("%-14s: %-44s|\n", FIELDS[j], current_list->credit[j]);
                            }
                            printf("%-60s|\n", " ");
                            if(i != entries -1){
                                FILL(60, '-');
                                printf("|\n");
                            }
                       } else {
                           listed++;
                           if(index == listed){
                               free(file_name);
                               free(count_name);
                               closedir(count_dir);
                               closedir(data_dir);
                               list_specific(current_list);
                               redirector[mode-1](current_list, mode);
                               goto end;
                            }
                        } 
                    }
               }
               total_files++;
           }
           free(file_name);
           free(count_name);
        }
        if(listed == 0){
            printf("None of the entries matched your search. Please enter a proper information.\n");
            return;
        }
        if(mode == called_for_list){
            closedir(count_dir);
            closedir(data_dir);
            got_list = true;
            goto end;
        }

        if(printed_list == false){
            printf("(%d)s files listed out of (%d)s files.\n", listed, total_entries);
            int format = true;
            printf("You can narrow down the result by specifying more if you want more concised result.\n\n");
            while(format){
                printf("Enter the index number for the subject: ");
                scanf("%d", &index);
                fflush(stdin);

                if(1 > index || index > listed){
                    printf("[INVALID INPUT]");
                } else {
                    format = false;
                }
            }
            printed_list = true;
        }
        closedir(count_dir);
        closedir(data_dir);

    }

    end:
    return;
}

//lists a specific list
void list_specific(list_p node){
    printf("\n");
    FILL(60, '=');
    printf("|\n");
    printf("%-15s%-45s|\n", FIELDS[SUBJECT_NAME], node->credit[SUBJECT_NAME]);
    FILL(60, '=');
    printf("|\n", " ");

    for(int i = 1; i < 4; i++){
        printf("%-15s%-45s|\n", FIELDS[i], node->credit[i]);
    }
    printf("%-60|\n", " ");
    FILL(60, '=');
    printf("|\n\n");
}