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
    int debugging = 1;
    /** 
     * This function takes an argument with an option and stores it in the system.
     * The user can also disply a usage statement to understand how to input numbers 
     * into the program. */
    printf("\n");
    int option;

    if(debugging == 1){
        printf("\nargc: %d", argc);
        printf("\nargv: %s", argv[1]);
    }
    /*
    * 
    * 
    */

    if(argc == 2){
        printf("\n No option selected - DEFAULT: K \n");
        opts -> number = atoll(argv[1]);
        if(atoll(argv[1])==0){
            fprintf(stderr, "\nERRROR Not a number or number not assigned correctly to opts ");
        }
        opts -> flag = 'K';

    }


    while((option = getopt(argc,argv,"K:M:G:T:P:E:h:")) != -1 )
    {
        
        if(debugging == 1){
            printf("\noption: %c", option);
        }

        switch(option)
        {	
            case 'K':
                opts -> number = atoll(optarg);
                opts -> flag = 'K';
                if ((atoll(optarg)) >=9223372036854775807){
                    printf("\nWARNING INPUT NUMBER TOO BIG - MAX NUMBER is 9223372036854775807  9.0E \n");
                }

                break;

            case 'M':
                opts -> number = atoll(optarg);
                opts -> flag = 'M';
                if ((atoll(optarg)) >=9223372036854775807){
                    printf("\nWARNING INPUT NUMBER TOO BIG - MAX NUMBER is 9223372036854775807  9.0E \n");
                }
                break;            
            
            case 'G':
                opts -> number = atoll(optarg);
                opts -> flag = 'G';
                if ((atoll(optarg)) >=9223372036854775807){
                    printf("\nWARNING INPUT NUMBER TOO BIG - MAX NUMBER is 9223372036854775807  9.0E \n");
                }
                break;            
            
            case 'T':
                opts -> number = atoll(optarg);
                opts -> flag = 'T';
                if ((atoll(optarg)) >=9223372036854775807){
                    printf("\nWARNING INPUT NUMBER TOO BIG - MAX NUMBER is 9223372036854775807  9.0E \n");
                }
                break;            
            
            case 'P':
                opts -> number =  atoll(optarg);
                opts -> flag = 'P';
                if ((atoll(optarg)) >=9223372036854775807){
                    printf("\nWARNING INPUT NUMBER TOO BIG - MAX NUMBER is 9223372036854775807  9.0E \n");
                }
                break;            
            
            case 'E':
                opts -> number = atoll(optarg);
                opts -> flag = 'E';
                if ((atoll(optarg)) >=9223372036854775807){
                    printf("\nWARNING INPUT NUMBER TOO BIG - MAX NUMBER is 9223372036854775807  9.0E \n");
                }
                break; 
                
            case 'h':
                opts -> number = atoll(optarg);
                if ((atoll(optarg)) >=9223372036854775807){
                    printf("\nWARNING INPUT NUMBER TOO BIG - MAX NUMBER is 9223372036854775807  9.0E \n");
                }

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
                printf("\nUnknown option\n");
                print_usage();
                break;
            
            default:
                printf("DEFAULT!!!");

        }
    }




}