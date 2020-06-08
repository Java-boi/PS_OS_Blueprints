
/*
* Compiler flags: -Wall -Werror -Wextra -std=gnu11 -pthread
*/

#include <stdlib.h>
#include <pthread.h>

#define THREAD_COUNT 10
#define CONDITION 1

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;


void * thread() {
  do {
    pthread_mutex_lock(&mutex);

    while(!CONDITION) {
      pthread_cond_wait(&cond, &mutex);
    }

    //critial region

    pthread_mutex_unlock(&mutex);
  } while (CONDITION);

  //return the sum of the read values
  return NULL;
}


int main(int argc, char *argv[]) {

  //storage for all threads
  pthread_t open_threads[THREAD_COUNT];

  //creating THREAD_COUNT threads
  for (int i = 0; i < THREAD_COUNT; i++) {
    pthread_create(open_threads + i, NULL, thread, NULL);
  }

  //joining up all threads and summing up the results
  for (int i = 0; i < THREAD_COUNT; i++) {
    pthread_join(open_threads[i], NULL);
  }

  //destroy mutex and conditional
  pthread_mutex_destroy(&mutex);
  pthread_cond_destroy(&cond);

  return EXIT_SUCCESS;
}
