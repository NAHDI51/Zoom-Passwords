#include "definitions.h"
#include <unistd.h>

int main()
{
    int x = chdir("..");
    if(x != 0){
        printf("Couldnt change path.\n");
    }
    char path[100];
    getcwd(path, 100);
    printf("%s\n", path);
}