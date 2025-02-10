#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Need more arguments!\n: Usage: ./cat <filename");
        return 2;
    } 
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error");
        return 3;
    } 
    char *lines[10];  // Circular buffer for last 10 lines
    int line_count = 0;
    size_t buf_size = 0;
    ssize_t len;
    char *buffer = NULL;

    while ((len = getline(&buffer, &buf_size, file)) != -1) {
        if (line_count < 10) {
            lines[line_count] = strdup(buffer);  // Copy line
        } else {
            free(lines[line_count % 10]);  // Free old line
            lines[line_count % 10] = strdup(buffer);  // Store new line
        }
        line_count++;
    }

    int start = (line_count > 10) ? (line_count % 10) : 0;
    int total = (line_count > 10) ? 10 : line_count;

    for (int i = 0; i < total; i++) {
        printf("%s", lines[(start + i) % 10]);
        free(lines[(start + i) % 10]);  // Free memory
    }

    free(buffer);
    fclose(file);
    return 0;
}
