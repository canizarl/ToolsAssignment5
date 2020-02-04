/**
 * \file my_hexdump.c
 * \brief This program mimics the hexdump shell utility.
        To use you must give it the filename of a txt file
        located in the same directory 

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
    int debugging = 0;
    CLOptions opts;
    char buff[255];

    // Parse commands to obtain filename
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

    int i;          // keeps track of the hexadecimal numbers being printed
    int k;          // toggles between 0 and 1 to print each byte as two numbers
    int t = 0;      //  counter for each byte
    int j = 0;      // this is to count the lines being displayed. 
    int b = 0;      // counter for the second buffer (to display  the text)
    int bytes = 0;  // counter of all the bytes in the file. 
    printf("%07x0  ", j); // First line. 
    


    // Allocate memory for the second buffer which will be used to display 
    // the text on  the right hand side. 
    char *secondbuff = malloc(sizeof(char)*16);   
    if (secondbuff==NULL){ 
        fprintf(stderr, "\nERROR: second buffer error.\n"); 
        exit(EXIT_FAILURE); 
    } 

    
    while(fgets(buff,255,fptr)!=NULL){
        // This loop reads through each line in the file 
        // amd stores it in a buffer. 


        int lengths = strlen(buff);
        char hexs[(lengths*2)+1];     // this will store the hexadecimal numbers
        
        // convert buffer into hexadecimal
        ascii2hex(buff,hexs);
        
        
        // counters reset
        b = 0;
        i = 0;
        k = 0;
        

        while(hexs[i]!='\0'){
            /* This loop goes throught each hexadecimal number 
            and prints 16 bytes in one line. */ 
            

            /* Each character in hexadecimal is comprised of two numbers 
                if k = 0 then the first one is printed
                if k = 1 then the second one is printed and a gap is also 
                printed to account for the next character. */
            if(k == 0){
                printf("%c", hexs[i]);
                k++;
                
            }
            else if(k == 1){
                printf("%c ", hexs[i]);
                k = 0;

                /* Non - printable characters are shown as a dot. */ 
                if(buff[b] == '\0' ||buff[b] == '\a' ||buff[b] == '\b' ||buff[b] == '\f' ||buff[b] == '\n' ||buff[b] == '\r' ||buff[b] == '\t' ||buff[b] == '\v'){ 
                    *(secondbuff+t) = '.';
                    b++;
                }
                else{
                    *(secondbuff+t) = buff[b];
                    b++;
                }
                t++;

                bytes++;
                if(t == 8 ){
                    printf(" ");
                }
            }
            if(t == 16){
                /* If 16 bytes have been printed then it prints the text to the side and makes a new line. */ 
                printf("|" );
                
                int kk;
                for(kk = 0; kk<16; kk++){
                    printf("%c", secondbuff[kk]);
                }
                printf("|");
                printf("\n");

                
                t = 0;
                j++;
                printf("%07x0  ", j);
            }
            
            i++;
        }
        
        


    

    }
    free(secondbuff);
    printf("\n%08x\n",bytes);
    printf("\n");
    fclose(fptr);
    return 0;
 }


 void ascii2hex(char* istr, char* ostr){
     /* This function turns asscii characters 
     into hexadecimal numbers.  */ 
    int i = 0;
    int j = 0; 
    
    while(istr[j] != '\0'){
        sprintf((ostr+i),"%02x", istr[j]);
        j++;
        i = i+2;
    }
    
    /* C requires a NULL character at the end of a string  */ 
    ostr[i++] = '\0';
}

