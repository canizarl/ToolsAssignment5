/**
 * \file parseHexd.h
 * \brief 
        header file containing function prototypes for 
        parseHexd.c 


        
 * \author L. Alberto Canizares
 * \version 1.0
 * \date 2020-01-28
 */
#ifndef PARSEHexd_H
#define PARSEHexd_H


typedef struct {
   char *filename;
}CLOptions;


void parse_command_line(const int argc, char *const *argv, CLOptions *opts);
void print_usage(void);




#endif /* end of include guard: PARSEHexd_H */

