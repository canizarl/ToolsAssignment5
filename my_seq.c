/**
 * \file my_seq.c
 * \brief This program mimics the seq shell utility. 
    Only increments sequence is supported. 
    The user can give one, two or three integers to be 
    sequenced. 

    These are the possible sequences:
    One integer given : 1 to LAST in increments of 1 
        ./my_seq LAST
    Two integers given: FIRST to LAST in increments of 1
        ./my_seq FIRST LAST
    Three integers given: FIRST to LAST in increments of INCREMENT 
        ./my_seq FIRST INCREMENT LAST

    The option -w is also supported. 
        This option adds a '0' to the numbers being displayed 
        to adjust for the width of the number with most digits. 


 * \author L. A. Canizares
 * \version 1.0
 * \date 2020-01-29
 */

#include <stdio.h>
#include <stdlib.h>
#include "parseSeq.h"
#include <math.h>


/* function prototypes */ 
void printresult(CLOptions *opts);
int numd(int n);




/* THE MAIN FUNCTION */ 
int main(int argc, char * const *argv)
{  

    // make a data structure to store the command line arguments
    CLOptions opts;

    // read the command line arguments
    parse_command_line(argc,argv, &opts);

    // mimic the seq utility 
    printresult(&opts);
    
    return 0;
}





void printresult(CLOptions *opts){
    /* This function mimics the seq shell utility. 
     * Notice only increments of positive numbers are supported. 
    */
    int const first = opts->first;
    int const increment = opts -> increment;
    int const last = opts -> last;


    // Only positive increment supported. 
    if(first > last){
        fprintf(stderr, "ERROR: only increasing sequence supported\n");
        exit(EXIT_FAILURE);
    }

    // this prevents from picking an increment that is too big
    // for example it makes no sense to go from 5 to 10 in steps of 6
    if(increment > ((last-first))){
        fprintf(stderr, "ERROR: increment too large! \n");
        exit(EXIT_FAILURE);
    }



    int i = first; 
    int z;
    int diff;

    // goes from last until final number and adds increment to the 
    // current value. if wflag is activated then it prints the necessary
    // number of '0' in front of the current value to adjust for width. 
    while(i<(last+1)){
        // check if user activated the -w flag
        if (opts->wflag){
            diff = numd(last) - numd(i);
            for(z = 0;z<diff; z++){
                printf("0");
            }
        }
        printf("%d \n", i);
        i = i+increment;
    }


}


int numd (int i) {
    // This function checks how many digits are 
    // in the number i 
    if (i == 0){
        return 1;
    }
    return floor (log10 (abs (i))) + 1;
}