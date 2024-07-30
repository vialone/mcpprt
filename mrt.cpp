#include <cstdio>
#include <cstdlib>
#include "mrt.h"

int ___excno = 0;
bool ___handled = false;

___Rt ___rt;

int main(int argc, char **argv, char **envp);

void ___defaultExceptionHandler(const char *file, int line) {
    printf("Uncaught exception in file %s at line %d\n", file, line);
    exit(___excno);
}


extern "C"
__attribute__((naked))
void _start(int argc, char **argv, char **envp) {
    int status;
    status = ((int(*)(int,char**,char**))main)(argc, argv, envp);
    exit(status);
}

void *operator new(size_t size) {
    return malloc(size);
}
void operator delete(void *ptr) {
    free(ptr);
}

void *operator new[](size_t size) {
    return malloc(size);
}
void operator delete[](void *ptr) {
    free(ptr);
}

void operator delete(void *ptr, size_t size) {
    free(ptr);
}
