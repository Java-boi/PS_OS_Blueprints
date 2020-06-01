#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>

#define SEMAPHORE1_NAME "/sem1"
#define SEMAPHORE2_NAME "/sem2"

#define BUFFER_SIZE 10
#define ITERATIONS 50

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

  //setting up semaphores
  sem_t * semaphore1 = sem_open(SEMAPHORE1_NAME, O_CREAT, 0666, BUFFER_SIZE);
  sem_t * semaphore2 = sem_open(SEMAPHORE2_NAME, O_CREAT, 0666, 0);

  //initializing buffer
  char buffer[BUFFER_SIZE];

  switch (( int pid = fork() )) {
    case -1:
      printf("Couldn't fork process.\n");
      exit(EXIT_FAILURE);
    case 0:
      producer();
    default:
      consumer();
  }

  waitpid(pid, NULL, 0);

  //cleaning semaphores up
  sem_close(sem1);
  sem_close(sem2);

  sem_unlink(SEMAPHORE1_NAME);
  sem_unlink(SEMAPHORE2_NAME);

  return EXIT_SUCCESS;
}
