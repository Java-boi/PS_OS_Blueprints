#include <stdlib.h>
#include <sys/select.h>

int main(int argc, char *argv[]) {

    //create file descriptor sets to observe
    fd_set all_fd, responded_fd;
    FD_ZERO(&all_fd);

    // Add file descriptor (stdin in this case)
    FD_SET(0, &all_fd);

    //select is destructive. Using second variable
    responded_fd = all_fd;

    // wait for change in a file
    int sel_err = select(FD_SETSIZE, &responded_fd, NULL, NULL, NULL);
    if (sel_err == -1) {
        // selection error
    }

    for (int i = 0; i < FD_SETSIZE; i++)
        if (FD_ISSET(i, &responded_fd))
            //change in the file with the file descriptor i occured

    return EXIT_SUCCESS;
}
