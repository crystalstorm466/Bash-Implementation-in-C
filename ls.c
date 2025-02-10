#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#ifdef __unix__
    #define IS_POSIX 1
    #include <unistd.h>
#else
    #define IS_POSIX 0
#endif

void ls(char *name) {
    printf("Listing directory: %s\n", name);
    DIR *dir;
    struct dirent *dent;
    dir = opendir(name);
    if (dir!= NULL) {
         while ((dent=readdir(dir)) != NULL ) {

            if ((strcmp(dent->d_name,".") == 0 || strcmp(dent->d_name,"..") == 0 || (*dent->d_name) == '.')) {

            } else {
            printf("%s", dent->d_name);
            printf("\n");
            }
           
        }
    } else {
        perror("No directory exists!");
        return;
    }
    closedir(dir);
    return;
}
int main(int argc, char *argv[2]) {

    if (argc >= 2) {
        ls(argv[1]); //case if ls has an argument 
        return 0;
    }
    if (IS_POSIX == 1) {
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("Current Working Directory: %s", cwd);
        printf("\n");

    }
    DIR *dir;
    struct dirent *dent;
    char cwd[1024];
    dir = opendir(getcwd(cwd, sizeof(cwd)));

    if (dir!= NULL) {
         while ((dent=readdir(dir)) != NULL ) {

            if ((strcmp(dent->d_name,".") == 0 || strcmp(dent->d_name,"..") == 0 || (*dent->d_name) == '.')) {

            } else {
            printf("%s", dent->d_name);
            printf("\n");
            }
           
        }
    }
   
    closedir(dir);
}