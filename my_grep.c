/**
 * \file my_seq.c
 * \brief 


 * \author L. A. Canizares
 * \version 1.0
 * \date 2020-01-29
 */

#include <stdio.h>
#include <stdlib.h>
#include "parseGrep.h"


/* function prototypes */ 





/* THE MAIN FUNCTION */ 
int main(int argc, char * const *argv)
{  
    // SETTINGS
    int debugging=1;
    char buff[255];


    // make a data structure to store the command line arguments
    CLOptions opts;

    // read the command line arguments
    parse_command_line(argc,argv, &opts);

    if(debugging==1){
        printf("TEXT:  %s \n", opts.text);
        printf("FNAME: %s \n", opts.filename);
    }

    FILE* fptr = fopen("bohemian.txt","r"); 
    if (fptr==NULL){ 
        fprintf(stderr, "\nERROR: no such file.\n"); 
        exit(EXIT_FAILURE); 
    } 
    while(fscanf(fptr, "%[^\n]\n", buff)!=EOF){  
        printf("%s \n", buff );  
    }  
    




    fclose(fptr);

    return 0;
}





