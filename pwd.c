#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[2]) {
    
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("%s", cwd);
        printf("\n");

   
}