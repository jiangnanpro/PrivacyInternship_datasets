#ifndef BOARD_H_
#define BOARD_H_

typedef struct state {
        int board[3][3]; // initial = -1, O = 0 , X = 1
        int turn;        // X (humain) first
} state;


void init_board(state* s);                    // initialize the board with -1
void display_board(const state* s);           // display the current board
//int move(state* s, int i, int j);           // move function for humain & computer (uncomment this line for play the game directly with computer)
//void human(state* s);                       // get humain's action from terminal (uncomment this line for play the game directly with computer)
int evaluate(const state* s);                 // check if the game is over: X win / O win / Draw
int minimax(state* s);                        // Minimax Algorithm, compute recursively the score for each possible move
int best_move(state* s);                      // call minimax then return the best move for computer player
//void computer(state* s);                    // computer's action (uncomment this line for play the game directly with computer)


#endif /* BOARD_H_ */
