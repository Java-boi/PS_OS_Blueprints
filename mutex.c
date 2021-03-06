
/*
* Compiler flags: -Wall -Werror -Wextra -std=gnu11 -pthread
*/

#include <stdlib.h>
#include <pthread.h>

#define THREAD_COUNT 10

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void * thread() {
  pthread_mutex_lock(&mutex);
  //critial region
  pthread_mutex_unlock(&mutex);

  //return the sum of the read values
  return NULL;
}


int main() {

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

  //destroy mutex
  pthread_mutex_destroy(&mutex);

  return EXIT_SUCCESS;
}
