#include <stdio.h>
#include <string.h>

#include <sys/stat.h> 
#include <fcntl.h>

void main(int argc, char* argv[])
{
    int fd = open("/dev/reverse", O_RDWR);
    write(fd, argv[1], strlen(argv[1]));
    read(fd, argv[1], strlen(argv[1]));
    printf("Read: %s\n", argv[1]);
}