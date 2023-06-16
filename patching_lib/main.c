// static run REMOVE libmath.so before compile
// gcc main3.c -L./lib -lmath -o main
// a.out

// shared run BUILD libmath.so before run and static not work
// gcc main3.c -L./lib -lmath -o main
// LD_LIBRARY_PATH=lib ./a.out

// patch run
// gcc -fPIC -shared myputs.c -o myputs.so
// LD_PRELOAD=patch/myputs.so LD_LIBRARY_PATH=lib ./a.out
#include <stdio.h>
#include "include/operation.h"
#include "include/divide.h"
#include "include/multiply.h"
#include "include/subs.h"

int main()
{
    int a = 4;
    int b = 2;

    printf("hasil %d + %d: %f\n\n", a, b, operation(a, b));
    printf("hasil %d * %d: %f\n\n", a, b, multiply(a, b));
    printf("hasil %d / %d: %f\n\n", a, b, divide(a, b));
    printf("hasil %d - %d: %f\n\n", a, b, subs(a, b));
}
