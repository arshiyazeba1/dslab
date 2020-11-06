#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
    int fd;
    char buf[1024];
    char *myfifo = "/tmp/myfifo";
    mkfifo(myfifo, 0666);
    printf("Writer process started and now open one more terminal for running reader process\n");
    fd = open(myfifo, O_WRONLY);
    write(fd, "WELCOME E2 BATCH", sizeof("WELCOME E2 BATCH"));
    close(fd);
    unlink(myfifo);
    return 0;
}
