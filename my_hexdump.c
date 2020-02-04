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
void hex2ascii(char* istr, char* ostr);


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
    int bytes = 0;
    printf("%07x0  ", j);
    while(fgets(buff,255,fptr)!=NULL){
        //printf("%s", buff);
        int lengths = strlen(buff);
        char hexs[(lengths*2)+1];
        
        ascii2hex(buff,hexs);

        i=0;
        k = 0;
        char *buff2ascii = malloc(sizeof(char)*32);
        char buffinascii[16];
        if(buff2ascii==NULL){
	        fprintf(stderr,"Error making buff2ascii pointer. \n");
	        exit(EXIT_FAILURE);
        }
        
        while(hexs[i]!='\0'){
            if(k == 0){
                printf("%c", hexs[i]);
                buff2ascii[t] = hexs[i];
                k++;
            }
            else if(k == 1){
                printf("%c ", hexs[i]);
                buff2ascii[t] = hexs[i];
                k = 0;
                t++;
                bytes++;
                if(t == 8 ){
                    printf(" ");
                }
            }
            if(t == 16){
                printf(" |  " );
                hex2ascii(buff2ascii, buffinascii);
                if(debugging==1){
                    printf("%d",(int)buffinascii);
                }
                else{
                    printf("%d", buffinascii);
                }

                // here goes the hex2asscii code
                printf("  | ");
                printf("\n");
                t = 0;
                j++;
                printf("%07x0  ", j);
            }
            
            i++;
        }
        
        free(buff2ascii);


    

    }
    printf("\n%08x\n",bytes);
    printf("\n");
    fclose(fptr);
    return 0;
 }


 void ascii2hex(char* istr, char* ostr){
    int i = 0;
    int j = 0; 
    
    while(istr[j] != '\0'){
        sprintf((ostr+i),"%02x", istr[j]);
        j++;
        i = i+2;
    }
    //insert NULL at the end of the output string
    ostr[i++] = '\0';
}

 void hex2ascii(char* istr, char* ostr){
    // make code here to turn each bytes into ASCII
    int i = 0;
    int j = 0;
    char buff[2];
    while (istr[i]!='\0'){
        buff[0] = istr[i];
        buff[1] = istr[i+1];
        int number = strtol(buff, NULL, 16);
        i+=2;
        ostr[j] = (char) number;
        j++;

    }

}