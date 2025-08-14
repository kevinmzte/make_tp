#include <stdio.h>
#include <stdlib.h>          // para atoi
#include "listing1.3.hpp"    // antes "reciprocal.hpp"

int main (int argc, char **argv)
{
    int i;
    i = atoi(argv[1]);
    printf("The reciprocal of %d is %g\n", i, reciprocal(i));
    return 0;
}
