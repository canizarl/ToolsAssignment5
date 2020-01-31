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
void ascii2hex(char* istr, char* ostr);


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

    int i;
    int k;
    int t = 0;
    int j = 0;
    printf("%07X  ", j);
    while(fgets(buff,255,fptr)!=NULL){
        //printf("%s", buff);
        int lengths = strlen(buff);
        char hexs[(lengths*2)+1]; 
        ascii2hex(buff,hexs);

        i=0;
        k = 0;
        
        
        while(hexs[i]!='\0'){
            if(k == 0){
                printf("%c", hexs[i]);
                k++;
            }
            else if(k == 1){
                printf("%c ", hexs[i]);
                k = 0;
                t++;
                if(t == 8 ){
                    printf(" ");
                }
            }
            if(t == 16){
                printf("\n");
                t = 0;
                j++;
                printf("%07X  ", j);
            }
            
            i++;
        }
        
        




    }

    printf("\n");
    fclose(fptr);
    return 0;
 }


 void ascii2hex(char* istr, char* ostr){
    int i = 0;
    int j = 0; 
    //char buff[255];
    
    while(istr[j] != '\0'){
        sprintf((ostr+i),"%02X", istr[j]);
        j++;
        i = i+2;
    }
    //insert NULL at the end of the output string
    ostr[i++] = '\0';
}