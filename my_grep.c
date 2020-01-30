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
#include <string.h>

/* function prototypes */ 
int checkstrings(char *linetocheck, char *stringp);


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

    FILE* fptr = fopen(opts.filename,"r"); 
    if (fptr==NULL){ 
        fprintf(stderr, "\nERROR: no such file.\n"); 
        exit(EXIT_FAILURE); 
    } 

    int n = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int t = 0;
    while(opts.text[k] != '\0'){
        k++;
    }
    

    while(fgets(buff,255,fptr)!=NULL){
        n++;
        
        if((ret = strstr(buff, opts.text))!=NULL){
            
            if(opts.vflag == 0){
                if(opts.nflag == 1){
                    printf("%d: ", n);
                }
                if(opts.cflag == 0){
                    printf("%s", buff);
                }
                if(opts.cflag == 1){
                    i = 0;
                    j = 0;
                  
                    while(buff[i]!= '\0'){
                        
                        //printf("j = %d \n", j);
                        if(&buff[i] == &ret[j]){
                            for(t=0; t<k; t++){
                                printf("\033[1;31m");
                                printf("%c", buff[i]);
                                printf("\033[0m");
                                i++;
                            }
                            i--;

                            ret = strstr(ret+1, opts.text);

                        }
                        else{
                            printf("%c", buff[i]);
                        }

                        i++;
                        
                    }
                    
                  
                    
                }
            }
            

        }
        else if(((ret = strstr(buff, opts.text)) ==NULL) && (opts.vflag == 1)){
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

