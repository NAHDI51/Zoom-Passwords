#include "definitions.h"

void delete_command(list_p node, int mode){
    if(mode == called_for_delete){
        int proper = false;
         char *input = (char*)malloc(100);
            if(input == NULL){
                printf("Error.\n");
                exit(1);
            }

        while(!proper){
            printf("Do you really want to delete it?[Y/N]: ");
            fgets(input, 98, stdin);
            fflush(stdin);

            break_new_line(&input);
            no_spaces_first(&input);

            if(strlen(input) == 0){
                continue;
            }else if(strcasecmp(input, "y") == 0){
                proper = true;
            }else if(strcasecmp(input, "n") == 0){
                printf("\nProgram Terminated.\n");
                exit(0);
            } else {
                printf("[INVALID INPUT] ");
            }
            free(input);
        }
    }

    //count file
    char* count_name = (char*)malloc(strlen("counts/") + strlen("_count") + strlen(node->credit[SUBJECT_NAME]) + strlen(".txt") + 2);
    if(!count_name){
        fprintf(stderr, "funcs.c Line: 26, Error.\n");
        exit(1);
    }
    strcpy(count_name, "counts/");
    strcat(count_name, node->credit[SUBJECT_NAME]);
    strcat(count_name, "_count");

    FILE* count_readfile = fopen(count_name, "rb");
    FILE* count_writefile = fopen(count_name, "wb");
    if(!count_writefile){
        fprintf(stderr, "funcs.c Line 47, Error.");
        exit(1);
    }

    //main file
    char* data_name = (char*)malloc(strlen("data/")+ strlen(node->credit[SUBJECT_NAME]) + strlen(".txt") + 2);
    if(!data_name){
        fprintf(stderr, "funcs.c Line: 54, Error.\n");
        exit(1);
    }
    strcpy(data_name, "data/");
    strcat(data_name, node->credit[SUBJECT_NAME]);
    strcat(data_name, ".txt");

    FILE* data_readfile = fopen(data_name, "rb");
    FILE* data_writefile = fopen(data_name, "wb");
    if(!data_readfile || !data_writefile){
        fprintf(stderr, "funcs.c Line 64, Error.");
        exit(1);
    }

    int entries;
    list_p reader = (list_p)malloc(sizeof(list));

    fscanf(count_readfile, "%d", &entries);
    for(int i = 0; i < entries; i++){
        fread(reader, sizeof(list), 1, data_readfile);
        if((strcmp(node->credit[ID], reader->credit[ID])==0) && strcmp(node->credit[PASS], reader->credit[PASS]) == 0){
            printf("Entry deleted.\n");       
        } else {
            fwrite(&reader, sizeof(list), 1, data_writefile);
        }
    }

    if(entries-1 == 0){
        fclose(count_readfile);
        fclose(count_writefile);
        int x = remove(count_name);
        if(x){
            fprintf(stderr, "funcs.c Line 86, Error.");
            exit(1);
        }
    } else {
        fprintf(count_writefile, "%d", entries-1);
    }

    fclose(count_readfile);
    fclose(count_writefile);
    fclose(data_readfile);
    fclose(data_writefile);
    free(count_name);
    free(data_name);
    free(reader);
}

void modify_command(list_p node, int mode){
    list_specific(node);
    printf("modify command.\n");
    printf("Reahed here.\n");
    return;
}

void get_command(list_p node, int mode){
   int proper = false;
   int decision;

    printf("[0] = Quit program\n");
    printf("[1] = Delete List\n");
    printf("[2] = Modify List\n\n");

   while(!proper){
        printf("Enter a option: ");
        scanf("%d", &decision);
        fflush(stdin);

        if(decision == 0){
            printf("Program Terminated.\n");
            exit(0);
        } else if (decision < 0 || decision > 2) {
            printf("[ENTER A PROPER INDEX] ");
        } else {
            proper = true;
        }
   }
   if(decision == 1){
       delete_command(node, mode);
   } else if (decision == 2){
       modify_command(node, mode);
   }
}
