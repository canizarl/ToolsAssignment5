/**
 * \file my_hexdump.c
 * \brief This program mimics the hexdump shell utility.
        To use you must give it a filename. 

    # NOTE!!!
    # I used github for version control 
    # https://github.com/canizarl/ToolsAssignment5.git

 * \author L. A. Canizares
 * \version 1.0
 * \date 2020-01-29
 */

#include <stdio.h>
#include <stdlib.h>
#include "parseHexd.h"
#include <string.h>

/* function prototypes */ 


/* THE MAIN FUNCTION */ 
int main(int argc, char * const *argv){ 
    
    printf("\n");
    int debugging = 1;
    CLOptions opts;
    char buff[255];

    parse_command_line(argc, argv, &opts);



    if(debugging == 1){
        printf("%s\n", opts.filename);
    }

    // open the file
    FILE* fptr = fopen(opts.filename,"r"); 
    if (fptr==NULL){ 
        fprintf(stderr, "\nERROR: no such file.\n"); 
        exit(EXIT_FAILURE); 
    } 

    while(fgets(buff,255,fptr)!=NULL){
        printf("%s", buff); 


    }

    fprintf("\n");
    fclose(fptr);
    return 0;
 }