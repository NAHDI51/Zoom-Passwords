#ifndef _DEFINITIONS_H_
#include "../definitions.h"
#endif

#ifndef _STAT_H_
#include <sys/stat.h>
#endif

#ifndef _DIRENT_H_
#include <dirent.h>
#endif

#ifndef _UNISTD_H_
#include <unistd.h>
#endif

//After taking the input from the user, This source code saves the list on the disk properly.

void write_on_disk(list_p node){

    struct stat stats;    //Records every file's datas and stats.

    //The root folder of the program.
    chdir("..");

    DIR* main_dir = opendir(".");
    if(main_dir == NULL){
        fprintf(stderr, "add/write_on_disk.c Line: 19, Error: count not open the directory.\n");
        exit(1);
    }
    struct dirent* main_dir_record;     //This variable reads the assigned directory and returns the folders and files within.

    int folder_exists = false;
    while((main_dir_record = readdir(main_dir)) != NULL){
        stat(main_dir_record->d_name, &stats);
        if(S_ISDIR(stats.st_mode)){

            //If the data folder is not created, create that folder.
            if(strcasecmp(main_dir_record->d_name, "data") == 0){
                folder_exists = true;
            }
            //Otherwise, don't do anything.
        }
    }

    if(!folder_exists){
        system("mkdir data");
        system("mkdir counts");
    }
    closedir(main_dir);

    //After the validity of the folder data has been ensured, start writing in the folder.
    DIR* data_dir = opendir("data");
    if(data_dir == NULL){
        printf("add/write_on_disk.c Line 55, Error: could not open the directory.\n");
        exit(1);
    }

    //This variable searchs for the entry of a specific subject, and then
    struct dirent *data_record;
    int file_exists = false;

    char *filename = (char*)malloc(sizeof(char) * ((strlen(node->credit[SUBJECT_NAME]) + 1) + strlen(".dat")));
    if(filename == NULL){
        printf("add/write_on_disk.c Line 65, Error: could not open the directory.\n");
        exit(1);
    }
    strcpy(filename, underscore(node->credit[SUBJECT_NAME]));
    strcat(filename, ".dat");


    //search for the file.
    while((data_record = readdir(data_dir)) != NULL){
        stat(data_record->d_name, &stats);
        printf("%s\n", data_record->d_name);
           //If we get it, means we don't have to newly create another file, thus make file_exists true.
            if(strcmp(data_record->d_name, filename) == 0){
                file_exists = true;
                printf("triggered!\n");
            }
    }

    FILE *count_file;
    int entries;
    //The following 5 lines of builds up the address of the file that saves counts by concatnating.
    char* count_name = (char*)malloc(strlen(node->credit[SUBJECT_NAME]) + 2 + strlen(".dat") + strlen("_count") + strlen("counts/"));
    strcpy(count_name, "counts/");
    strcat(count_name, node->credit[SUBJECT_NAME]);
    strcat(count_name, "_count");
    strcat(count_name, ".dat");

    //If the file doesn't exist, we will default the number of entry to 1, and will create a count file.
    if(file_exists == 0){
        entries = 1;

        count_file = fopen(count_name, "a");
        if(count_file == NULL){
            printf("add/write_on_disk Line 95, Error: could not open file: %s", count_file);
            exit(1);
        }
        fprintf(count_file, "%d", 1);

    }else{
        count_file = fopen(count_name, "rb");
        if(count_file == NULL){
            fprintf(stderr, "add/write_on_disk.c Line 104 Error: Could not open file: %s", count_file);
            exit(1);
        }
        fscanf(count_file, "%d", entries);
        entries++;

        fclose(count_file);

        count_file = fopen(count_name, "w");
        if(count_file == NULL){
            fprintf(stderr, "add/write_on_disk.c Line 104 Error: Could not open file: %s", count_file);
            exit(1);
        }
        fprintf(count_file, "%d", entries);
    }

    free(count_name);
    fclose(count_file);

    //So now that after ensuring that everything is optimized, we can proceed to enter the details of the node we imported.

    char *data_filename = (char*)malloc(strlen(filename) + 2 + strlen("data/"));
    if(data_filename == NULL){
        printf("add/write_on_disk Line 125, Error: could not allocate: data_filename");
        exit(1);
    }
    sprintf(data_filename, "data/%s", filename);
    free(filename);

    FILE* data_file = fopen(data_filename, "a");
    if(data_file == NULL){
        fprintf(stderr, "add/write_on_disk.c Line 133: Error: could not open file: %s", data_filename);
        exit(1);
    }

    fwrite(node, sizeof(list), 1, data_file);
    return;
}