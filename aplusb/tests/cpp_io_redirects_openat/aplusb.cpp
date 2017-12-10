#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fdw = openat(AT_FDCWD, "DATA.out", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if(fdw == -1) {
        perror("DATA.out openat");
        return 1;
    }
    int fdr = openat(AT_FDCWD, "DATA.in", O_RDONLY);
    if(fdr == -1) {
        perror("DATA.in openat");
        return 1;
    }
    
    if(dup2(fdw, 1) == -1 || dup2(fdr, 0) == -1) {
        perror("dup2");
        return 1;
    }

    int N;
    scanf("%d", &N);

    while(N--) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", a + b);
    }

    return 0;
}
