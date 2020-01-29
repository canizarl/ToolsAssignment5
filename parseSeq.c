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

                printf("Defaults\n");
                // print_usage();
                // exit(EXIT_FAILURE);
        }


    }




}