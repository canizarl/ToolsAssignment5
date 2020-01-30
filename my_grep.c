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
    // SETTINGS
    int debugging=1;
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
    while(fscanf(fptr, "%[^\n]\n", buff)!=EOF){
        
        
        if((ret = strstr(buff, opts.text))!=NULL){
            printf("%s \n", buff);
        }
        
    }  
    



    fclose(fptr);

    return 0;
}


// int checkstrings(char *linetocheck, char *stringp){
//     int debugging = 1;
//     if(debugging == 1){
//        printf("checkstrings\n");
//     }
//     if(stringp == NULL || *stringp == '\0'){
//         return 0;
//     }
//     if(linetocheck == NULL || *linetocheck == '\0'){
//         return 0;
//     }

//     int test;
//     int i = 0;
//     while(*linetocheck){
//         printf("%c ", *linetocheck);
//         char c = *linetocheck;
//         if(c == stringp[i]){
//             i++;
//             test = 1;
//             if(stringp[i]=='\0'){
//                 return test;
//             }
//         }
//         else{
//             i = 0;
//             test = 0;
//         }
//         stringp++;
//     }


//     return test;
// }


