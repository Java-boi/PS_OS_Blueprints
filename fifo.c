#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256
#define FIFO_PATH "/FIFOPATH";


int main(int argc, char *argv[]) {

    // create fifo
    if (mkfifo(FIFO_PATH, 0666) < 0) {
        // Fifo error
    }

    //open fifo
    if ((int fd = open(FIFO_PATH, O_RDWR)) < 0) {
        //fifo error
    }

    //write to fifo
    char * writebuffer = "Test";
    write(fd, writebuffer, strlen(writebuffer));

    //read from fifo
    char buffer[BUFFER_SIZE];
    int read_chars = read(fd, buffer, BUFFER_SIZE - 1));
    *(buffer + read_chars) = '\0'

    // close fifo
    close(fd);

    // destory fifo
    unlink(FIFO_PATH);

    return EXIT_SUCCESS;
}
