#ifndef UTIL_H
#define UTIL_H
#define TRUE 1
#define FALSE 0

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef char bool;

void *malloc_checked(unsigned int b);

#endif
