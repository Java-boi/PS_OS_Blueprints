#include <stdlib.h>
#include <unistd.h>
// #include <sys/wait.h>

int main(int argc, char *argv[]) {

  switch (( int pid = fork() )) {
    case -1:
      // Fork Error
    case 0:
      // Child code
    default:
      // Parent code
      // wait(NULL)
      // waitpid(pid)
  }

  return EXIT_SUCCESS;
}
