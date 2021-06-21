#include <stdio.h>
#include "board.h"

#define CHECK(j1, i1, j2, i2, j3, i3) \
        if (s->board[j1][i1] != -1 && s->board[j1][i1] == s->board[j2][i2] && s->board[j1][i1] == s->board[j3][i3]) \
        return s->board[j1][i1] == 0 ? 1 : -1;

#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))


void init_board(state* s) {

        for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                        s->board[i][j] = -1;
        s->turn = 0;
}


void display_board(const state* s) {

        for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                        switch (s->board[i][j]) {
                        case -1: printf(" %d ", i * 3 + j + 1); break;
                        case  0: printf(" X "); break;
                        case  1: printf(" O "); break;
                        }
                        if (j < 2)
                                printf("|");
                        else
                                printf("\n");
                }
                if (i < 2)
                        printf("---+---+---\n");
                else
                        printf("\n");
        }
}


int move(state* s, int i, int j) {
        if (s->board[i][j] != -1)
                return 0;
        s->board[i][j] = s->turn++ % 2;
        return 1;
}


void human(state* s) {
        char c;
        do {
                printf("%c: ", "XO"[s->turn % 2]);
                c = getchar();
                while (getchar() != '\n');
                printf("\n");
        } while (c < '1' || c > '9' || !move(s, (c - '1') / 3, (c - '1') % 3));
}


int evaluate(const state* s) {

        for (int i = 0; i < 3; i++) {
                CHECK(i, 0, i, 1, i, 2); // horizontal
                CHECK(0, i, 1, i, 2, i); // vertical
        }
        CHECK(0, 0, 1, 1, 2, 2);    // diagonal
        CHECK(0, 2, 1, 1, 2, 0);    // diagonal
        if (s->turn == 9)
                return 2;

        return 0;
}


int minimax(state* s) {
        int current = evaluate(s);

        if (current == -1)
                return 10;
        else if (current == 1)
                return -10;
        else if (current == 2)
                return 0;

        if (s->turn % 2 == 1) {
                int best = -1000;

                for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                                if (s->board[i][j] == -1) {
                                        s->board[i][j] = 1;
                                        s->turn++;
                                        best = max(best, minimax(s));
                                        s->board[i][j] = -1;
                                        s->turn--;
                                }
                        }
                }
                return best;
        }

        else {
                int best = 1000;

                for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                                if (s->board[i][j] == -1) {
                                        s->board[i][j] = 0;
                                        s->turn++;
                                        best = min(best,minimax(s));
                                        s->board[i][j] =-1;
                                        s->turn--;
                                }
                        }
                }
                return best;
        }
}



int best_move(state* s) {
        int bestmove = -1;
        int score = -1000;

        for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                        if (s->board[i][j] == -1) {
                                s->board[i][j] = 1;
                                s->turn++;
                                int temp = minimax(s);

                                if (temp > score) {
                                        score = temp;
                                        bestmove = i*3+j+1;
                                }

                                s->board[i][j] = -1;
                                s->turn--;
                        }
                }
        }
        return bestmove;
}


void computer(state* s) {
        int bestmove;
        printf("%c: ", "XO"[s->turn % 2]);
        bestmove = best_move(s);
        printf("bestmove: %d \n",bestmove);
        move(s, (bestmove - 1) / 3, (bestmove - 1) % 3);
}
