#ifndef _DEFINITIONS_H_
#include "definitions.h"
#endif

#ifndef _DIRENT_H_
#include <dirent.h>
#endif

#ifndef _STAT_H_
#include <sys/stat.h>
#endif

int folder_exists(char* path, char *folder){
    DIR* main_dir = opendir(path);
    if(main_dir == NULL){
        fprintf(stderr, "exitance.c Line: 16, Error: count not open the directory.\n");
        exit(1);
    }
    struct dirent* main_dir_record;     //This variable reads the assigned directory and returns the folders and files within.
    struct stat stats;

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
    closedir(main_dir);
    return folder_exists;
}

int file_exists(char *path, char *filename){

    struct stat stats;    //Records every file's datas and stats.

    DIR* data_dir = opendir(path);
    if(data_dir == NULL){
        printf("existance.c Line 44, Error: could not open the directory.\n");
        exit(1);
    }

    //This variable searchs for the entry of a specific subject, and then
    struct dirent *data_record;
    int file_exists = false;

     //search for the file.
    while((data_record = readdir(data_dir)) != NULL){
        stat(data_record->d_name, &stats);

           //If we get it, means we don't have to newly create another file, thus make file_exists true.
            if(strcmp(data_record->d_name, filename) == 0){
                file_exists = true;
            }
    }
    return file_exists;
}