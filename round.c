/**
 * \file round.c
 * \brief 

 * \author L. A. Canizares
 * \version 1.0
 * \date 2020-01-28
 */
#include "parse.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int nval;
    // Read command line arguments
    nval = parse_command_line(argc,argv);

    printf("\nnval:  %d\n", nval);



    printf("\n");
    return 0;
}