#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int main() {
    struct passwd *pw = getpwuid(getuid());
    if (pw) {
        printf("%s\n", pw->pw_name);
    } else {
        perror("whoami");
        return 1;
    }
    return 0;
}