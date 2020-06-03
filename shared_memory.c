
/*
* Compiler flags: -Wall -Werror -Wextra -std=gnu11 -lrt
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

#define SHARED_MEMORY_SIZE 256
#define SHARED_MEMORY_PATH "/ps_os"

int main(int argc, char const *argv[]) {

  //creating shared memory file descriptors and error checking
  int smfd = shm_open(SHARED_MEMORY_PATH, O_RDWR | O_CREAT, 0666);
  if (smfd == -1) {
    // shared memory error
  }


  //setting the size of the shared memory
  int trun_err = ftruncate(smfd, SHARED_MEMORY_SIZE);
  if (trun_err == -1) {
    // shared memory error
  }


  //mapping shared memory into heap
  void * shared_memory = mmap(NULL, SHARED_MEMORY_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, smfd, 0);
  if (shared_memory == MAP_FAILED) {
    // shared memory mapping error
  }

  //unlinking the shared memory
  shm_unlink(SHARED_MEMORY_PATH);

  return EXIT_SUCCESS;
}
