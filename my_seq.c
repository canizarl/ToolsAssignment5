/**
 * \file my_seq.c
 * \brief 
        


 * \author L. A. Canizares
 * \version 1.0
 * \date 2020-01-29
 */

#include <stdio.h>
#include <stdlib.h>
#include "parseSeq.h"
#include <getopt.h>

void printresult(CLOptions *opts);

int main(int argc, char * const *argv)
{  
    CLOptions opts;
    parse_command_line(argc,argv, &opts);






    return 0;
}

void printresult(CLOptions *opts){
    
}