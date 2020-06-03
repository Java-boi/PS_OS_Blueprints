#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

/* How to compile
    start:
        gcc -c -Wall -Wextra -Werror -fpic system_allocator.c
        gcc -shared system_allocator.o -o system_allocator.so
        gcc -Wall -Wextra -Werror -std=gnu11 shared_library.c -o shared_library -ldl
*/

// declare shared library functions
void *(*my_malloc)(size_t size);
void (*my_free)(void *memory);

int main() {

    // load shared library (.so)
    void *sl_handle = dlopen("./system_allocator.so", RTLD_LAZY);   // RTLD_LAZA means loading funcitons when needed. RTLD_LOCAL... 
    if(sl_handle == NULL) {
        printf("Error: Could not load library (%s)\n", dlerror());
        exit(EXIT_FAILURE);
    }
    my_malloc = dlsym(sl_handle, "my_malloc");
    my_free = dlsym(sl_handle, "my_free");

    if(my_malloc == NULL) {
        printf("Error at loading function pointer my_malloc.\n");
        exit(EXIT_FAILURE);
    }
    if(my_free == NULL) {
        printf("Error at loading function pointer my_free.\n");
        exit(EXIT_FAILURE);
    }

    // call shared library functions
    void *memory = my_malloc(1024);
    my_free(memory);

    // close shared library
    dlclose(sl_handle);

    return EXIT_SUCCESS;
}