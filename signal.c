#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>


void handler(int sig) {
    // Execute on signal
}

int main(int argc, char *argv[]) {

  switch (( int pid = fork() )) {
    case -1:
      // Fork Error
    case 0:
        //setting path for signals
        signal(SIGUSR1, handler);

        // pause() waits for signal
        while(1) {
            pause();
        }

        break;

    default:
        //send signal
        kill(pid, SIGUSR1);

        //wait for fork
        wait(NULL);
  }

  return EXIT_SUCCESS;
}
