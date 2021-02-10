#ifndef _DEFINITIONS_H_
#include "../definitions.h"
#endif

#ifndef _STAT_H_
#include <sys/stat.h>
#endif

#ifndef _DIRENT_H_
#include <dirent.h>
#endif

#ifndef _UNISTD_H
#include <unistd.h>
#endif

//After taking the input from the user, This source code saves the list on the disk properly.

void write_on_disk(list_p node){

    int folder_exist = folder_exists(".", "data");
    if(!folder_exist){
        system("mkdir data");
        system("mkdir counts");
    }

    char *filename = (char*)malloc(sizeof(char) * ((strlen(node->credit[SUBJECT_NAME]) + 1) + strlen(".txt")));
    if(filename == NULL){
        printf("add/write_on_disk.c Line 32, Error: could not open the directory.\n");
        exit(1);
    }
    strcpy(filename, underscore(node->credit[SUBJECT_NAME]));
    strcat(filename, ".txt");

    int file_exist = file_exists("data", filename);

    FILE *count_file;
    int entries;
    //The following 5 lines of builds up the address of the file that saves counts by concatnating.
    char* count_name = (char*)malloc(strlen(node->credit[SUBJECT_NAME]) + 2 + strlen(".dat") + strlen("_count") + strlen("counts/"));
    strcpy(count_name, "counts/");
    strcat(count_name, node->credit[SUBJECT_NAME]);
    strcat(count_name, "_count");
    strcat(count_name, ".txt");

    //If the file doesn't exist, we will default the number of entry to 1, and will create a count file.
    if(file_exist == 0){
        entries = 1;

        count_file = fopen(count_name, "a");
        if(count_file == NULL){
            printf("add/write_on_disk Line 55, Error: could not open file: %s", count_file);
            exit(1);
        }
        fprintf(count_file, "%d", 1);

    }else{
        count_file = fopen(count_name, "r");
        if(count_file == NULL){
            fprintf(stderr, "add/write_on_disk.c Line 64 Error: Could not open file: %s", count_file);
            exit(1);
        }
        fscanf(count_file, "%d", &entries);
        entries++;

        fclose(count_file);

        count_file = fopen(count_name, "w");
        if(count_file == NULL){
            fprintf(stderr, "add/write_on_disk.c Line 73 Error: Could not open file: %s", count_file);
            exit(1);
        }
        fprintf(count_file, "%d", entries);
    }

    free(count_name);
    fclose(count_file);

    //So now that after ensuring that everything is optimized, we can proceed to enter the details of the node we imported.

    char *data_filename = (char*)malloc(strlen(filename) + 2 + strlen("data/"));
    if(data_filename == NULL){
        printf("add/write_on_disk Line 86, Error: could not allocate: data_filename");
        exit(1);
    }
    sprintf(data_filename, "data/%s", filename);
    free(filename);

    FILE* data_file = fopen(data_filename, "a");
    if(data_file == NULL){
        fprintf(stderr, "add/write_on_disk.c Line 94: Error: could not open file: %s", data_filename);
        exit(1);
    }

    fwrite(node, sizeof(list), 1, data_file);
    return;
}