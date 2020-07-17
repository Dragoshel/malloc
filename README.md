# Malloc
This file will document the process of learning the complexities of C and re-implementing the malloc function.
## Malloc library function from C
It's a funciton that is very commonly used to allocate new bytes of memory. It returns a void pointer to the start of the memory address that has just been allocated and can then be attributed to any pointer variable.

In itself, malloc does not demand a lot of logic, but rather, is a wrapper function for the __brk()__ and __sbrk()__ system calls. It provides an additional level of abstraction and it's responsible for input and error checking.

Let's first talk a bit about the two system calls which quite nicely provide most of the functionality for this implementation:
  * Both __brk()__ and __sbrk()__ change the program break of the process in question, essentially allocating additioanl memory and making it available for the process to take care of. The program break refers to the end of the data segment and is the first address location after the end of the uninitialized data segment. Here the program break is just a way to tell the process that it can access memory until that point. Also, the data segment simply refers to the heap (For the ones that were confused - Don't worry I was also at the beginning).
  
  * __brk(void * addr)__ takes in a pointer and moves the program break to the address specified. Increasing the  program break allocates new memory - Decreasing it deallocated memory. 

  * The __sbrk(size_t size)__ it's more useful. It simply takes in a size and increases the end of the heap by _size_ bytes.
  
## Take a look at the diagram below
                                                    
```
References:
  https://danluu.com/malloc-tutorial/
  https://medium.com/@andrestc/implementing-malloc-and-free-ba7e7704a473
```
