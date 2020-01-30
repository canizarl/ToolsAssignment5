/**
 * \file parseSeq.c
 * \brief Parses command line options to my_seq.c
        Check function print_usage for instructions

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
    */
    printf("\nusage: seq [-w] [first [incr]] last\n");
}


void  parse_command_line(const int argc, char *const * argv,CLOptions *opts)
{   
    int debugging = 1; // change to 1 for extra information
    int option;
    int i;
    
    if(debugging == 1){
        printf("\nargc: %d", argc);
        printf("\nargv: " );
        for(i = 1; i< argc; i++){
            printf(" %s ", argv[i]);
        }
        printf("\n");
        
    }

    int *seqnumbers = calloc(3,sizeof(int));
    int j = 0;
    for(i = 1; i<argc; i++){
        if(isnumber(argv[i])){
            seqnumbers[j] = atoi(argv[i]);
            j++;
        }   
    }

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
    


    while((option = getopt(argc,argv,"w")) != -1 )
    {
        switch(option)
        {	
            case 'w':
                printf("CASE w\n");
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


    free(seqnumbers);

}

int isnumber(char const *stringp){
    if(stringp == NULL || *stringp == '\0'){
        return 0;
    }

    int dots = 0;
    while(*stringp){
        char c = *stringp;
        switch(c){
            case '.':
                if(++dots > 1){
                    return 0;
                }
                break;

            default:
                if(c<'0' || c >'9'){
                    return 0;
                }
        }
        stringp++;
    }

    return 1;
}


