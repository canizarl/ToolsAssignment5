/**
 * \file parseGrep.c
 * \brief Parses command line options to my_grep.c
        Check function print_usage for instructions

 * \author L. A. Canizares
 * \version 1.0
 * \date 2020-01-28
 */





#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "parseGrep.h"


void print_usage(void){
    /*
    * Default message display to tell the user how to use the parsing function
    */
    printf(" usage: grep [-nvc] TEXT [filename]\n");
}


void  parse_command_line(const int argc, char *const * argv,CLOptions *opts)
{   
    int debugging = 1; // change to 1 for extra information
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
     // handle the -nvc option
    while((option = getopt(argc,argv,"nvc")) != -1 )
    {
        switch(option)
        {	
            case 'n':
                if(debugging == 1){
                    printf("OPTION n\n");
                }
                break;

            case 'v':
                if(debugging == 1){
                    printf("OPTION v\n");
                }
                break;

            case 'c':
                if(debugging == 1){
                    printf("OPTION c\n");
                }
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


}