#include <stdio.h>
#include "board.h"
#include "logic.h"


int main() {

        struct state s;
        struct truthtable t;
        init_board(&s);

        printf("Loading... \n \n");
        display_board(&s);

        init_truth_table(&t);
        generate_truth_table(&s, &t);
        // display_truth_table(&t);       // uncomment this line for display the truth table in terminal
        write_truth_table(&t);
        simplify_truth_table();
        generate_code();

        printf("Finished! Check 'boolean_function.c' in 'Test' Folder. \n");


        /* uncomment following lines for play the game directly with computer */

        /*
        while (s.turn < 9) {
                human(&s);
                display_board(&s);
                computer(&s);
                display_board(&s);

                switch (evaluate(&s)) {
                case  1: printf("X win\n"); return 0;
                case -1: printf("O win\n"); return 0;
                case  2: printf("Draw!\n"); return 0;
                }
        }
        */

}
