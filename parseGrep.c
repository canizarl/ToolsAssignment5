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

    int j = 0;
    for(i = 1; i< argc; i++){
        if(*argv[i] !='-'){
            if(j == 0){
                opts -> text = argv[i];
                j++;
            }
            else if(j == 1){
                opts -> filename = argv[i];
            }
            else{
                printf("WARNING: TOO MANY INPUTS");
            }



        }
    }

    if(argc == 1){
        print_usage();
    }

    opts -> nflag = 0;
    opts -> vflag = 0;
    opts -> cflag = 0;

    // handle the -nvc option
    while((option = getopt(argc,argv,"nvc")) != -1 )
    {
        switch(option)
        {	
            case 'n':
                if(debugging == 1){
                    printf("OPTION n\n");
                }
                opts -> nflag = 1;
                break;

            case 'v':
                if(debugging == 1){
                    printf("OPTION v\n");
                }
                opts -> vflag = 1;
                break;

            case 'c':
                if(debugging == 1){
                    printf("OPTION c\n");
                }
                opts -> cflag = 1;
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