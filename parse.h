/**
 * \file parse.h
 * \brief 
        header file for parse.c which takes two arguments: a flag and an int 
        and stores it in a struct(defined below) that will later be used by 
        round.c

        This header file also contains function prototypes for the parse.c file. 
            parse_command_line is the function to parse commands
            print_usage is just a set of instructions for the user

 * \author L. Alberto Canizares
 * \version 1.0
 * \date 2020-01-28
 */
#ifndef PARSE_H
#define PARSE_H


typedef struct {
    char flag;  	// flag that will determine the type of number 
    long long int number; 	// long long int to account for the large E numbers 
}CLOptions;


void parse_command_line(const int argc, char *const *argv, CLOptions *opts);
void print_usage(void);


#endif /* end of include guard: PARSE_H */
