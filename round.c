/**
 * \file round.c
 * \brief 
        Takes a flag and an integer and rounds this number to the 
        specified unit, using base 2 rounding where 1K is 1024. 
        Rounds to one decimal place. 
        If no flag is supplied the default is K


 * \author L. A. Canizares
 * \version 1.0
 * \date 2020-01-28
 */
#include "parse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double round_cal(long long int number, long long int scale);

int main(int argc, char * const *argv)
{   
    int debugging = 0;    // change to 1 for extra information
    long long int nval = -1;
    float result = -1;
    char flag = ' ';
    CLOptions opts;      // struct where flag and integers are stored
    
    
    // Read command line arguments
    parse_command_line(argc,argv, &opts);
    nval = opts.number;  // original integer 
    if(nval < 0){
        fprintf(stderr, "ERROR: round.c : nval not assigned correctly. ");
    }
    
    flag = opts.flag;  // flag to be used for conversion 
    if(flag == ' '){
        fprintf(stderr, "ERROR: round.c : flag not assigned correctly. ");
    }


    if (debugging == 1){
        printf("\nnval:  %lld\n", nval);
        printf("\nflag:  %c\n", flag);
    }
    switch(flag){
        case 'n':
            /* this case is for numbers smaller than K 
            and only when user uses -h flag */
            result = nval;
            printf("%lld  =  %.1f ",nval,result);
            break;

        case 'K':
            result = round_cal(nval, 1E3);
            printf("%lld  =  %.1f K",nval,result);
            break;
        case 'M':
            result = round_cal(nval, 1E6);
            printf("%lld  =  %.1f M",nval,result);
            break;
        case 'G':
            result = round_cal(nval, 1E9);
            printf("%lld  =  %.1f G",nval,result);
            break;
        case 'T':
            result = round_cal(nval, 1E12);
            printf("%lld  =  %.1f T",nval,result);
            break;
        case 'P':
            result = round_cal(nval, 1E15);
            printf("%lld  =  %.1f P",nval,result);
            break;
        case 'E':
            result = round_cal(nval, 1E18);
            printf("%lld  =  %.1f E",nval,result);
            break;
    }   

    printf("\n");
    return 0;
}


double round_cal(long long int number, long long int scale){
    /* This function converts to the right unit using base 2 rounding */
    double result;
    result = number/(scale*1.024);
    return result;
}