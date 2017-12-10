#include <unistd.h>
#include <stdio.h>

char host[4096];

int main() {
    if(sethostname("this_is_a_bad_sign", 18) == -1) {
        perror("sethostname");
    }
    if(gethostname(host, 4095) == -1) {
        perror("gethostname");
    } else {
        printf("Hostname: %s\n", host);
    }
    return 0;
}
