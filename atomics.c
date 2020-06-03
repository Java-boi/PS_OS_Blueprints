
/*
Declaration: _Atomic type name;

Built-in Function: void __atomic_store (type *ptr, type *val, int memorder)
It stores the value of *val into *ptr.

Built-in Function: void __atomic_load (type *ptr, type *ret, int memorder)
It returns the contents of *ptr in *ret.

Built-in Function: type __atomic_fetch_add (type *ptr, type val, int memorder)
Built-in Function: type __atomic_fetch_sub (type *ptr, type val, int memorder)
Built-in Function: type __atomic_fetch_and (type *ptr, type val, int memorder)
Built-in Function: type __atomic_fetch_xor (type *ptr, type val, int memorder)
Built-in Function: type __atomic_fetch_or (type *ptr, type val, int memorder)
Built-in Function: type __atomic_fetch_nand (type *ptr, type val, int memorder)
These built-in functions perform the operation suggested by the name, and return the value that
had previously been in *ptr. Operations on pointer arguments are performed as if the operands were
of the uintptr_t type. That is, they are not scaled by the size of the type to which the pointer points.
*/


// Example:
#include <stdlib.h>
#include <stdio.h>

_Atomic int x;

int main() {
    int value = 22;

    // initialize
    __atomic_store(&x, &value, 0);

    // increment
    __atomic_fetch_add(&x, 1, 0); // increment x by 1

    // load
    __atomic_load(&x, &value, 0);

    printf("value of x = %d\n", value);
    return EXIT_SUCCESS;
}

// Alternative:
#include <stdlib.h>
#include <stdatomic.h>

atomic_int x;

int main(int argc, char const *argv[]) {
    //initialize
    x = 5;

    //increment
    x++;

    //decrement
    x--;

    //load
    int value = x;

    return 0;
}
//
