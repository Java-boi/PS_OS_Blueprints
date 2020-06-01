#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char const *argv[]) {

  // storage for the file descriptors [read, write]
  int fds[2];
  pipe(fds);

  //linking pipe read end to stdout
  dup2(1, fds[0]);

  //writing to pipe
  char * writebuffer = "test";
  write(fds[1], writebuffer, strlen(writebuffer));

  return EXIT_SUCCESS;
}
