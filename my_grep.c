/**
 * \file my_seq.c
 * \brief This program mimics the grep shell utility.
        To use you must give it a filename. 

        it supports:
            -v : inverts the grep
            -c : highlights the input string in the output
            -n : shows the line numbers 



 * \author L. A. Canizares
 * \version 1.0
 * \date 2020-01-29
 */

#include <stdio.h>
#include <stdlib.h>
#include "parseGrep.h"
#include <string.h>

/* function prototypes */ 


/* THE MAIN FUNCTION */ 
int main(int argc, char * const *argv)
{  
    printf("\n");
    // SETTINGS
    int debugging=0;
    char buff[255];
    char *ret;

    // make a data structure to store the command line arguments
    CLOptions opts;

    // read the command line arguments
    parse_command_line(argc,argv, &opts);

    if(debugging==1){
        printf("TEXT:  %s \n", opts.text);
        printf("FNAME: %s \n", opts.filename);
    }

    // open the file
    FILE* fptr = fopen(opts.filename,"r"); 
    if (fptr==NULL){ 
        fprintf(stderr, "\nERROR: no such file.\n"); 
        exit(EXIT_FAILURE); 
    } 


    // some counters 
    int n = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int t = 0;

    // measure the length of the input string 
    while(opts.text[k] != '\0'){
        k++;
    }
    
    // Reads the file line by line
    while(fgets(buff,255,fptr)!=NULL){
        n++;
        

        // finds the input string in the text
        if((ret = strstr(buff, opts.text))!=NULL){
            
            // PRINTING RESULTS

            // normal grep case
            if(opts.vflag == 0){
                // if the numbers is activated
                if(opts.nflag == 1){
                    printf("%d: ", n);
                }
                // if colour flag is not active
                if(opts.cflag == 0){
                    printf("%s", buff);
                }
                // if colour flag is activated
                if(opts.cflag == 1){
                    i = 0;
                    j = 0;
                  
                    while(buff[i]!= '\0'){

                        // this part of the code takes the point where the line matches the input string
                        // and starts coloring until the length of the input string has been matched. 
                        // program the looks for the following part of the sting that matches the input 
                        // if none is found program carries on as normal after.                        
                        if(&buff[i] == &ret[j]){
                            for(t=0; t<k; t++){

                                printf("\033[1;31m"); // this makes printing in red
                                printf("%c", buff[i]); 
                                printf("\033[0m");    // reset colour 
                                i++;
                            }
                            i--;

                            ret = strstr(ret+1, opts.text);  // looking for the next input string look alike

                        }
                        else{
                            printf("%c", buff[i]);  // carry on as normal 
                        }

                        i++;
                        
                    }
                    
                  
                    
                }
            }
            

        }
        else if(((ret = strstr(buff, opts.text)) ==NULL) && (opts.vflag == 1)){
            // inverted case 

            // with line numbers
            if(opts.nflag == 1){
                printf("%d: ", n);
            }
            printf("%s", buff);
        }
        
    }  
    



    fclose(fptr);
    printf("\n");
    return 0;
}

