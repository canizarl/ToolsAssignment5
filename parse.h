/**
 * \file parse.h
 * \brief 

 * \author L. Alberto Canizares
 * \version 1.0
 * \date 2020-01-28
 */
#ifndef PARSE_H
#define PARSE_H


typedef struct {
    char flag;  	/*!< -i option. input data file */
    long long int number; 	/*!< -x option. Holds minimum size you want to filter */
}CLOptions;


void parse_command_line(const int argc, char *const *argv, CLOptions *opts);
void print_usage(void);


#endif /* end of include guard: PARSE_H */
