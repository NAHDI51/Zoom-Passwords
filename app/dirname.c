#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>

int main(){
    DIR* direct = opendir(".");
    struct dirent * direct_read;
    
    while((direct_read = readdir(direct)) != NULL){
        printf("%s\n", direct_read->d_name);
    }
    return 0;
}