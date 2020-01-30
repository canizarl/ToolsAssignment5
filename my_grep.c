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

    // make a data structure to store the command line arguments
    CLOptions opts;

    // read the command line arguments
    parse_command_line(argc,argv, &opts);



    
    return 0;
}





