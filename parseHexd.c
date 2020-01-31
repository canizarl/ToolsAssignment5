/**
 * \file parseHexd.c
 * \brief this is used to parse commands to my_Hexdump.c
        


 * \author L. A. Canizares
 * \version 1.0
 * \date 2020-01-29
 */

#include <stdio.h>
#include <stdlib.h>
#include "parseHexd.h"
#include <string.h>

void print_usage(void){
    /*
    * Default message display to tell the user how to use the parsing function
    */
    printf(" usage: ./my_hexdump filename\n");
}


void  parse_command_line(const int argc, char *const * argv,CLOptions *opts)
{ 

    int debugging =1;   // change to 1 for debugging help

    int i = 0;
    if(debugging == 1){
        /* display arguments */ 
        printf("\nargc: %d", argc);
        printf("\nargv: " );
        for(i = 1; i< argc; i++){
            printf(" %s ", argv[i]);
        }
        printf("\n");
    }

    if(argc == 1){
        print_usage();   // in case the user doesnt know how to use it and just types ./my_grep
    }
    else if(argc == 2){
        opts -> filename = argv[1];
    }
    else{
        fprintf(stderr, "ERROR :: TOO MANY ARGUMENTS " );
        exit(EXIT_FAILURE);
    }

}