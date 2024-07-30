#include <cstdio>
#include <cstdlib>
#include "mrt.h"

void throws(void) {
    throw 5;
}

int main(void) {
    try throws();
    char *buff = new char;
    delete buff;
    buff = new char[10];
    delete buff;
    return 0;
}
