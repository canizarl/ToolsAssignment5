/**
 * \file parseGrep.h
 * \brief 
        header file containing function prototypes for 
        parseGrep.c 


        
 * \author L. Alberto Canizares
 * \version 1.0
 * \date 2020-01-28
 */
#ifndef PARSEGREP_H
#define PARSEGREP_H


typedef struct {
   char *text;
   char *filename;
   int nflag;
   int cflag;
   int vflag;
}CLOptions;


void parse_command_line(const int argc, char *const *argv, CLOptions *opts);
void print_usage(void);




#endif /* end of include guard: PARSEGREP_H */

