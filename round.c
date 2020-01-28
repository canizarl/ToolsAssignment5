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
#include <string.h>

double round_cal(long long int number, long long int scale);

int main(int argc, char * const *argv)
{   
    int debugging = 1;
    long long int nval = -1;
    float result = -1;
    char flag = ' ';
    CLOptions opts;
    // Read command line arguments
    parse_command_line(argc,argv, &opts);
    nval = opts.number;
    if(nval < 0){
        fprintf(stderr, "ERROR: round.c : nval not assigned correctly. ");
    }
    
    flag = opts.flag;
    if(flag == ' '){
        fprintf(stderr, "ERROR: round.c : flag not assigned correctly. ");
    }


    if (debugging == 1){
        printf("\nnval:  %lld\n", nval);
        printf("\nflag:  %c\n", flag);
    }
    switch(flag){
        case 'n':
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
    double result;
    result = number/(scale*1.024);
    return result;
}