#include <stdio.h>


int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Need more arguments!\n: Usage: ./cat <filename");
        return 2;
    } 
    
    FILE *fileptr;
    int ch;
    fileptr = fopen(argv[1], "r");

    if (NULL == fileptr) { printf("\n"); return 0; } //return empty
    while ((ch = fgetc(fileptr)) != EOF) {
        printf("%c", ch);
    }
    printf("\n");
    fclose(fileptr);
    return 0;
}
