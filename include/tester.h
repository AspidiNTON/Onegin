#ifndef TESTER_H
#define TESTER_H

#include <string.h>

#include "myString.h"

struct Test{
    const char *f;
    const char *s;
    const int n;
};

int runTest(Test *test);

int runDefaultTests();

#endif