#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "parse.h"


void print_usage(void){
    /*
    * Default error message display to tell the user how to use the parsing function
    */
    printf("\n Usage: ./round [-flag input_number ] \n");
    printf("\n flags:  K | M | G | T | P | E | h ");
    printf("\n input number must be an integer ");
    printf("\n flag h will return the human readable format ");
}


void  parse_command_line(const int argc, char *const * argv,CLOptions *opts)
{
    /** 
     * This function takes an argument with an option and stores it in the system.
     * The user can also disply a usage statement to understand how to input numbers 
     * into the program. */
    printf("\n");
    int option;


    /*
    * 
    * 
    */
    while((option = getopt(argc,argv,"K:M:G:T:P:E:h:")) != -1 )
    {
        switch(option)
        {	
            case 'K':
                opts -> number = atoi(optarg);
                opts -> flag = 1;
                break;

            case 'M':
                opts -> number = atoi(optarg);
                opts -> flag = 2;
                break;            
            
            case 'G':
                opts -> number = atoi(optarg);
                opts -> flag = 3;
                break;            
            
            case 'T':
                opts -> number = atoi(optarg);
                opts -> flag = 4;
                break;            
            
            case 'P':
                opts -> number =  atoi(optarg);
                opts -> flag = 5;
                break;            
            
            case 'E':
                opts -> number = atoi(optarg);
                opts -> flag = 6;
                break; 
                
            case 'h':
                opts -> number = atoi(optarg);
                opts -> flag = 7;
                break;
            
            case '?':
                if ((optopt == 'K') || (optopt == 'M') || (optopt == 'G') || (optopt == 'T') || (optopt == 'P')||(optopt == 'E')||(optopt == 'h')){
                    printf("hello there");
                    }

                print_usage();
                break;
            
            default:
                print_usage();
                fprintf(stderr, "getopt");

        }
    }



}