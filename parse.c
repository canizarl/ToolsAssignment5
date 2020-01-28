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
                opts -> number = atoll(optarg);
                opts -> flag = 'K';
                break;

            case 'M':
                opts -> number = atoll(optarg);
                opts -> flag = 'M';
                break;            
            
            case 'G':
                opts -> number = atoll(optarg);
                opts -> flag = 'G';
                break;            
            
            case 'T':
                opts -> number = atoll(optarg);
                opts -> flag = 'T';
                break;            
            
            case 'P':
                opts -> number =  atoll(optarg);
                opts -> flag = 'P';
                break;            
            
            case 'E':
                opts -> number = atoll(optarg);
                opts -> flag = 'E';
                break; 
                
            case 'h':
                opts -> number = atoll(optarg);

                if (opts -> number < 1024){
                    opts -> flag = 'n';
                }
                else if((opts -> number >= 1024) && (opts -> number < 1.024E6)){
                    opts -> flag = 'K';
                }
                else if((opts -> number >= 1.024E6) && (opts -> number < 1.024E9)){
                    opts -> flag = 'M';
                }
                else if((opts -> number >= 1.024E9) && (opts -> number < 1.024E12)){
                    opts -> flag = 'G';
                }
                else if((opts -> number >= 1.024E12) && (opts -> number < 1.024E15)){
                    opts -> flag = 'T';
                }
                else if((opts -> number >= 1.024E15) && (opts -> number < 1.024E18)){
                    opts -> flag = 'P';
                }
                else if(opts -> number >= 1.024E6){
                    opts -> flag = 'E';
                }
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