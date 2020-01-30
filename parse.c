/**
 * \file parse.c
 * \brief Parses command line options to round.c
        Check function print_usage for instructions

 * \author L. A. Canizares
 * \version 1.0
 * \date 2020-01-28
 */





#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "parse.h"


void print_usage(void){
    /*
    * Default message display to tell the user how to use the parsing function
    */
    printf("\n Usage: ./round [-flag input_number ] \n");
    printf("\n flags:  K | M | G | T | P | E | h ");
    printf("\n input number must be an integer ");
    printf("\n flag h will return the human readable format ");
    printf("\n default option: -K ");
}


void  parse_command_line(const int argc, char *const * argv,CLOptions *opts)
{   
    /** 
     * This function takes an option argument followed by an integer. These are then
     * stored in a opts structure stored in a pointer. This will be used by round.c
     * If the wrong option is passed, a usage message is displayed.
     * */


    int debugging = 0; // change to 1 for extra information
    
    printf("\n");
    int option;

    if(debugging == 1){
        printf("\nargc: %d", argc);
        printf("\nargv: %s", argv[1]);
    }





    /*
    *   If no command option is given and only an int is passed, 
    *   the program checks that it is indeed an int and uses K
    *   as default. 
    */
    if(argc == 2){
        printf("\n No option selected - DEFAULT: K \n");
        opts -> number = atoll(argv[1]);
        if(atoll(argv[1])==0){
            fprintf(stderr, "\nERRROR Not a number or number not assigned correctly to opts ");
        }
        opts -> flag = 'K'; 
    }

    if(argc == 1){
            print_usage();
    }


    /** 
     * When an option and an integer are passed the program selects from 
     * the different options and sends the appropriate flag to parse.c
     * using a struct defined in parse.h
     * opts -> number stores the integer in the struct pointer 
     * opts -> flag   stores the flag in the struct pointer
     * Program breaks down with numbers bigger than 8 bytes which is 
     * what a long long int takes. 
     * */
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
                /**
                 * Case h is special and picks a flag 
                 * according to what is easy for humans
                 * to read  */
                opts -> number = atoll(optarg);
                if ((atoll(optarg)) >=9223372036854775807){
                    printf("\nWARNING INPUT NUMBER TOO BIG - MAX NUMBER is 9223372036854775807  9.0E \n");
                }

                if (opts -> number < 1024){
                    /* if the number is smaller than 1K then number will be display as is */
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
                print_usage();
                exit(EXIT_FAILURE);

        }
    }

}