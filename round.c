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

int main(int argc, char * const *argv)
{
    int nval = -1;
    int flag = 0;
    CLOptions opts;
    // Read command line arguments
    parse_command_line(argc,argv, &opts);
    nval = opts.number;
    if(nval < 0){
        fprintf(stderr, "ERROR: round.c : nval not assigned correctly. ");
    }
    
    flag = opts.flag;
    if(flag == 0){
        fprintf(stderr, "ERROR: round.c : flag not assigned correctly. ");
    }
    printf("\nnval:  %d\n", nval);
    printf("\nflag:  %d\n", flag);




    printf("\n");
    return 0;
}