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
#include <math.h>
#include <limits.h>

void printresult(CLOptions *opts);
int numd(int n);

int main(int argc, char * const *argv)
{  
    CLOptions opts;
    parse_command_line(argc,argv, &opts);
    printresult(&opts);





    return 0;
}

void printresult(CLOptions *opts){
    int const first = opts->first;
    int const increment = opts -> increment;
    int const last = opts -> last;

    if(first > last){
        fprintf(stderr, "ERROR: only increasing sequence supported\n");
        exit(EXIT_FAILURE);
    }
    if(increment > ((last-first))){
        fprintf(stderr, "ERROR: increment too large! \n");
        exit(EXIT_FAILURE);
    }

    int i = first; 
    int z;
    int diff;
    while(i<(last+1)){
        if (opts->wflag){
            diff = numd(last) - numd(i);
            for(z = 0;z<diff; z++){
                printf("0");
            }
            // printf("%d \n", i);
        }
        printf("%d \n", i);
        // else {
        //     printf(" %d \n",i);
        // }
        i = i+increment;
    }


}


int numd (int i) {
    if (i == 0){
        return 1;
    }
    return floor (log10 (abs (i))) + 1;
}