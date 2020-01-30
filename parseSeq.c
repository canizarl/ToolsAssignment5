/**
 * \file parseSeq.c
 * \brief Parses command line options to my_seq.c
        Adds integers to a struct containing data needed
        for my_seq.c 

        - if only one integer is given, it assumes it is the
        last number in the sequence. 
        - if two numbers are given, it assumes these are 
        the first and the last number. 
        - if three numbers are given then it assumes first, 
        second is increment, and then third number is last. 
        - If -w is passed then the program flags this function
        and my_seq.c will add  '0' to equalize width padding. 
        
        Check function print_usage for instructions on how to use.

 * \author L. A. Canizares
 * \version 1.0
 * \date 2020-01-28
 */





#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "parseSeq.h"


void print_usage(void){
    /*
    * Default message display to tell the user how to use the parsing function
    * first and increment are optional. If none is given default is 1
    */
    printf("\nusage: seq [-w] [first [incr]] last\n");
}


void  parse_command_line(const int argc, char *const * argv,CLOptions *opts)
{   
    int debugging = 0; // change to 1 for extra information
    int option;
    int i;
    
    if(debugging == 1){
        /* display arguments */ 
        printf("\nargc: %d", argc);
        printf("\nargv: " );
        for(i = 1; i< argc; i++){
            printf(" %s ", argv[i]);
        }
        printf("\n");
        
    }

    // Allocate memory for the arguments to be
    // converted into numbers 
    int *seqnumbers = calloc(3,sizeof(int));
    if (seqnumbers == NULL){
	    perror("Error initialszing seqnumbers");
	    exit(EXIT_FAILURE);
    }


    // check if the arguments given are indeed numbers
    // and only take the number arguments
    int j = 0;
    for(i = 1; i<argc; i++){
        if(isnumber(argv[i])){
            seqnumbers[j] = atoi(argv[i]);
            j++;
        }   
    }

    // store the number arguments to the *opts struct 
    // if increment and first arent given default is 1
    if (j == 1){
        opts -> last = seqnumbers[0];
        opts -> increment = 1;
        opts -> first = 1;
    }
    else if(j == 2){
        opts -> first = seqnumbers[0];
        opts -> last = seqnumbers[1];
        opts -> increment = 1;
    }
    else if( j == 3){
        opts -> first = seqnumbers[0];
        opts -> increment = seqnumbers[1];
        opts -> last = seqnumbers[2];
         
    }
    else{
        printf("\nWARNING - TOO MANY INPUTS\n");
    }

    if(debugging == 1){
        printf("first: %d   ||   increment: %d   ||  last: %d   \n", opts->first, opts->increment , opts->last);
    }
    

    // handle the -w option
    while((option = getopt(argc,argv,"w")) != -1 )
    {
        switch(option)
        {	
            case 'w':
                opts->wflag = 1;
                break;

            case '?':
                printf("\nUnknown option\n");
                print_usage();
                break;
            
            default:
                print_usage();
                exit(EXIT_FAILURE);
        }


    }

    // deallocate memory for seqnumbers 
    free(seqnumbers);

}



int isnumber(char const *stringp){
    // Check if the string is made of unsigned int numbers 
    // this means it does not support + or - prefixes
    // i.e it assumes they are all positive


    // first check that string isnt empty
    if(stringp == NULL || *stringp == '\0'){
        return 0;
    }
    // this checks for numbers only. Anything else in
    // the string will make this not an integer
    while(*stringp){
        char c = *stringp;
        if(c<'0' || c >'9'){
            return 0;
        }
        stringp++;
    }

    return 1;
}


