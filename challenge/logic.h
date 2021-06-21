#ifndef LOGIC_H_
#define LOGIC_H_

#include "board.h"
# define LENGTH 10000

typedef struct truthtable {
        int inputX[LENGTH][9];      // initials = 0, set to 1 if there is a  X
        int inputO[LENGTH][9];      // initials = 0, set to 1 if there is an O
        int outputO[LENGTH][9];     // initials = 0, set to 1 if there is an output_O
        int line;                   // count lines of the truth table
} truthtable;


void init_truth_table(truthtable* t);                 // initialize the truth table with 0
void generate_truth_table(state* s, truthtable* t);   // generate the truth table by playing automatically and recursively the game
void display_truth_table(const truthtable* t);        // display the truth table + number of lines
void write_truth_table(const truthtable* t);          // write the truth table into the 'truth_table' file with PLA format
void simplify_truth_table();                          // minimize the truth table by applying espresso-logic-minimizer
void generate_code ();                                // generate boolean circuit from the minimized truth table


#endif /* LOGIC_H_ */
