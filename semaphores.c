#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <wait.h>
#include <sys/stat.h>

#define SEMAPHORE1_NAME "/sem1"
#define SEMAPHORE2_NAME "/sem2"

#define BUFFER_SIZE 10
#define ITERATIONS 50

//setting up semaphores
sem_t * semaphore1;
sem_t * semaphore2;

//initializing buffer
char buffer[BUFFER_SIZE];


void producer( void ) {

  for (int i = 0; i <= ITERATIONS; i++) {
    sem_wait(semaphore1);
    //add stuff to buffer via buffer[i % BUFFER_SIZE]
    sem_post(semaphore2);
  }

  exit(EXIT_SUCCESS);

}

void consumer( void ) {

  for (int i = 0; i <= ITERATIONS; i++) {
    sem_wait(semaphore2);
    //remove stuff from buffer via buffer[i % BUFFER_SIZE]
    sem_post(semaphore1);
  }

}



int main(int argc, char const *argv[]) {

  //initializing semaphores
  semaphore1 = sem_open(SEMAPHORE1_NAME, O_CREAT, 0666, BUFFER_SIZE);
  semaphore2 = sem_open(SEMAPHORE2_NAME, O_CREAT, 0666, 0);


  int pid;
  switch (( pid = fork() )) {
    case -1:
      //fork error
      break;
    case 0:
      producer();
      break;
    default:
      consumer();
  }

  waitpid(pid, NULL, 0);

  //cleaning semaphores up
  sem_close(semaphore1);
  sem_close(semaphore2);

  sem_unlink(SEMAPHORE1_NAME);
  sem_unlink(SEMAPHORE2_NAME);

  return EXIT_SUCCESS;
}
