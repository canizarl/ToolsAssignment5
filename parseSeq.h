/**
 * \file parseSeq.h
 * \brief 
        header file containing function prototypes for 
        parseSeq.c which takes one, two or three integers. 
        Stores these into a struct defined below. 

        it also contains some function prototypes needed in parseSeq.c

        
 * \author L. Alberto Canizares
 * \version 1.0
 * \date 2020-01-28
 */
#ifndef PARSESEQ_H
#define PARSESEQ_H


typedef struct {
    int last;  	// last value 
    int increment; 	// increment value 
    int first;  // first value 
    int wflag; // check if -w option has been given 
}CLOptions;


void parse_command_line(const int argc, char *const *argv, CLOptions *opts);
void print_usage(void);
int isnumber(char const *stringp);



#endif /* end of include guard: PARSESEQ_H */
