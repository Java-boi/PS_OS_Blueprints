
/*
* Compiler flags: -Wall -Werror -Wextra -std=gnu11 -pthread
*/

#include <stdlib.h>
#include <pthread.h>

#define THREAD_COUNT 10

void *thread(void *arg) {
  //threaded code
  return NULL;
}

int main() {

  //thread pointer storage
  pthread_t open_threads[THREAD_COUNT];


  //create threads
  for (int i = 0; i < THREAD_COUNT; i++) {
    // to send iterator "(void *) (intptr_t) i" as last argument. Needs to include stdint.h
    pthread_create(open_threads + i, NULL, thread, NULL);
  }


  // wait for threads and join them
  for (int i = 0; i < THREAD_COUNT; i++) {
    pthread_join(open_threads[i], NULL);
  }


  return EXIT_SUCCESS;
}
