#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "logic.h"
# define LENGTH 10000

void init_truth_table(truthtable* t) {

        for (int i = 0; i < LENGTH; i++)
                for (int j = 0; j < 9; j++) {
                        t->inputX[i][j] = 0;
                        t->inputO[i][j] = 0;
                        t->outputO[i][j] = 0;
                }

        t->line = 0;
}


void generate_truth_table(state* s, truthtable* t) {

        for (int i = 0; i < 9; i++) {

                int eval = evaluate(s);

                if (s->board[i/3][i%3] == -1 && eval != 1 && eval != -1) {

                        for (int ii = 0; ii < 9; ii++) {

                                if (s->board[ii/3][ii%3] == 0) {
                                        t->inputX[t->line][ii] = 1;
                                }
                                if (s->board[ii/3][ii%3] == 1) {
                                        t->inputO[t->line][ii] = 1;
                                }
                        }
                        s->board[i/3][i%3] = 0;
                        s->turn++;
                        t->inputX[t->line][i] = 1;
                        int bestmove = best_move(s);
                        if (bestmove != -1) {

                                s->board[(bestmove-1)/3][(bestmove-1)%3] = 1;
                                s->turn++;
                                t->outputO[t->line][bestmove-1] = 1;
                                t->line++;

                                generate_truth_table(s,t);

                                s->board[(bestmove-1)/3][(bestmove-1)%3] = -1;
                                s->turn--;
                        }
                        else {

                                t->line++;
                                generate_truth_table(s,t);
                        }

                        s->board[i/3][i%3] = -1;
                        s->turn--;
                }
        }
}


void display_truth_table(const truthtable* t) {

        for (int i = 0; i < t->line; i++) {
                for (int j = 0; j < 9; j++) {
                        printf("%d", t->inputX[i][j]);
                }
                printf("|");
                for (int j = 0; j < 9; j++) {
                        printf("%d", t->inputO[i][j]);
                }
                printf("|");
                for (int j = 0; j < 9; j++) {
                        printf("%d", t->outputO[i][j]);
                }
                printf("\n");
        }

        printf("Truth table has %d Lines. \n",t->line);
}


void write_truth_table(const truthtable* t) {

        FILE * fp;
        if((fp = fopen("truth_table","wb"))==NULL) {
                printf("cant open the file");
                exit(0);
        }

        fprintf(fp, ".i %d \n", 18);
        fprintf(fp, ".o %d \n", 9);

        for (int i = 0; i < t->line; i++) {
                for (int j = 0; j < 9; j++) {
                        fprintf(fp, "%d",t->inputX[i][j]);
                }
                for (int j = 0; j < 9; j++) {
                        fprintf(fp, "%d", t->inputO[i][j]);
                }
                fprintf(fp," ");
                for (int j = 0; j < 9; j++) {
                        fprintf(fp, "%d", t->outputO[i][j]);
                }
                fprintf(fp,"\n");
        }

        fclose(fp);
}


void simplify_truth_table() {

        system("./espresso ./truth_table > truth_table_minimized");
}


void generate_code() {
        // To do: this function is quite long and still need to be simplified.

        char str[100];
        char expression[] = "ABCDEFGHIabcdefghi";

        char out_0[LENGTH];
        char out_1[LENGTH];
        char out_2[LENGTH];
        char out_3[LENGTH];
        char out_4[LENGTH];
        char out_5[LENGTH];
        char out_6[LENGTH];
        char out_7[LENGTH];
        char out_8[LENGTH];

        int j_0=0;
        int j_1=0;
        int j_2=0;
        int j_3=0;
        int j_4=0;
        int j_5=0;
        int j_6=0;
        int j_7=0;
        int j_8=0;

        int count=0;
        int count_NOT=0;
        int count_AND=0;
        int count_OR=0;

        FILE *fp_read;

        if((fp_read=fopen("truth_table_minimized","r")) == NULL) {
                printf("can't open the file");
                exit(0);
        };

        while(fgets(str, 100, fp_read) != NULL) {

                if (str[19] == '1') {
                        out_0[j_0++] = '(';
                        for (int i = 0; i < 18; i++) {
                                if(str[i]=='0')
                                {
                                        out_0[j_0++] = '(';
                                        out_0[j_0++] = '!';
                                        out_0[j_0++] = expression[i];
                                        out_0[j_0++] = ')';
                                        count_NOT++;
                                }
                                else
                                        out_0[j_0++] = expression[i];
                                if(i != 17) {
                                        out_0[j_0++] = '&';
                                        out_0[j_0++] = '&';
                                        count_AND++;
                                }
                        }
                        out_0[j_0++] = ')';
                        out_0[j_0++] = '|';
                        out_0[j_0++] = '|';
                        count_OR++;

                }


                if (str[20] == '1') {
                        out_1[j_1++] = '(';
                        for (int i = 0; i < 18; i++) {
                                if(str[i]=='0')
                                {
                                        out_1[j_1++] = '(';
                                        out_1[j_1++] = '!';
                                        out_1[j_1++] = expression[i];
                                        out_1[j_1++] = ')';
                                        count_NOT++;
                                }
                                else
                                        out_1[j_1++] = expression[i];
                                if(i != 17) {
                                        out_1[j_1++] = '&';
                                        out_1[j_1++] = '&';
                                        count_AND++;
                                }
                        }
                        out_1[j_1++] = ')';
                        out_1[j_1++] = '|';
                        out_1[j_1++] = '|';
                        count_OR++;
                }

                if (str[21] == '1') {
                        out_2[j_2++] = '(';
                        for (int i = 0; i < 18; i++) {
                                if(str[i]=='0')
                                {
                                        out_2[j_2++] = '(';
                                        out_2[j_2++] = '!';
                                        out_2[j_2++] = expression[i];
                                        out_2[j_2++] = ')';
                                        count_NOT++;
                                }
                                else
                                        out_2[j_2++] = expression[i];
                                if(i != 17) {
                                        out_2[j_2++] = '&';
                                        out_2[j_2++] = '&';
                                        count_AND++;
                                }
                        }
                        out_2[j_2++] = ')';
                        out_2[j_2++] = '|';
                        out_2[j_2++] = '|';
                        count_OR++;
                }

                if (str[22] == '1') {
                        out_3[j_3++] = '(';
                        for (int i = 0; i < 18; i++) {
                                if(str[i]=='0')
                                {
                                        out_3[j_3++] = '(';
                                        out_3[j_3++] = '!';
                                        out_3[j_3++] = expression[i];
                                        out_3[j_3++] = ')';
                                        count_NOT++;
                                }
                                else
                                        out_3[j_3++] = expression[i];
                                if(i != 17) {
                                        out_3[j_3++] = '&';
                                        out_3[j_3++] = '&';
                                        count_AND++;
                                }
                        }
                        out_3[j_3++] = ')';
                        out_3[j_3++] = '|';
                        out_3[j_3++] = '|';
                        count_OR++;
                }

                if (str[23] == '1') {
                        out_4[j_4++] = '(';
                        for (int i = 0; i < 18; i++) {
                                if(str[i]=='0')
                                {
                                        out_4[j_4++] = '(';
                                        out_4[j_4++] = '!';
                                        out_4[j_4++] = expression[i];
                                        out_4[j_4++] = ')';
                                        count_NOT++;
                                }
                                else
                                        out_4[j_4++] = expression[i];
                                if(i != 17) {
                                        out_4[j_4++] = '&';
                                        out_4[j_4++] = '&';
                                        count_AND++;
                                }
                        }
                        out_4[j_4++] = ')';
                        out_4[j_4++] = '|';
                        out_4[j_4++] = '|';
                        count_OR++;
                }

                if (str[24] == '1') {
                        out_5[j_5++] = '(';
                        for (int i = 0; i < 18; i++) {
                                if(str[i]=='0')
                                {
                                        out_5[j_5++] = '(';
                                        out_5[j_5++] = '!';
                                        out_5[j_5++] = expression[i];
                                        out_5[j_5++] = ')';
                                        count_NOT++;
                                }
                                else
                                        out_5[j_5++] = expression[i];
                                if(i != 17) {
                                        out_5[j_5++] = '&';
                                        out_5[j_5++] = '&';
                                        count_AND++;
                                }
                        }
                        out_5[j_5++] = ')';
                        out_5[j_5++] = '|';
                        out_5[j_5++] = '|';
                        count_OR++;
                }

                if (str[25] == '1') {
                        out_6[j_6++] = '(';
                        for (int i = 0; i < 18; i++) {
                                if(str[i]=='0')
                                {
                                        out_6[j_6++] = '(';
                                        out_6[j_6++] = '!';
                                        out_6[j_6++] = expression[i];
                                        out_6[j_6++] = ')';
                                        count_NOT++;
                                }
                                else
                                        out_6[j_6++] = expression[i];
                                if(i != 17) {
                                        out_6[j_6++] = '&';
                                        out_6[j_6++] = '&';
                                        count_AND++;
                                }
                        }
                        out_6[j_6++] = ')';
                        out_6[j_6++] = '|';
                        out_6[j_6++] = '|';
                        count_OR++;
                }

                if (str[26] == '1') {
                        out_7[j_7++] = '(';
                        for (int i = 0; i < 18; i++) {
                                if(str[i]=='0')
                                {
                                        out_7[j_7++] = '(';
                                        out_7[j_7++] = '!';
                                        out_7[j_7++] = expression[i];
                                        out_7[j_7++] = ')';
                                        count_NOT++;
                                }
                                else
                                        out_7[j_7++] = expression[i];
                                if(i != 17) {
                                        out_7[j_7++] = '&';
                                        out_7[j_7++] = '&';
                                        count_AND++;
                                }
                        }
                        out_7[j_7++] = ')';
                        out_7[j_7++] = '|';
                        out_7[j_7++] = '|';
                        count_OR++;
                }

                if (str[27] == '1') {
                        out_8[j_8++] = '(';
                        for (int i = 0; i < 18; i++) {
                                if(str[i]=='0')
                                {
                                        out_8[j_8++] = '(';
                                        out_8[j_8++] = '!';
                                        out_8[j_8++] = expression[i];
                                        out_8[j_8++] = ')';
                                        count_NOT++;
                                }
                                else
                                        out_8[j_8++] = expression[i];
                                if(i != 17) {
                                        out_8[j_8++] = '&';
                                        out_8[j_8++] = '&';
                                        count_AND++;
                                }
                        }
                        out_8[j_8++] = ')';
                        out_8[j_8++] = '|';
                        out_8[j_8++] = '|';
                        count_OR++;
                }
        }

        out_0[j_0-2] = '\0';
        out_1[j_1-2] = '\0';
        out_2[j_2-2] = '\0';
        out_3[j_3-2] = '\0';
        out_4[j_4-2] = '\0';
        out_5[j_5-2] = '\0';
        out_6[j_6-2] = '\0';
        out_7[j_7-2] = '\0';
        out_8[j_8-2] = '\0';

        count_OR -= 8;

        count = count_NOT + count_AND + count_OR;


        fclose(fp_read);


        FILE * fp_write;

        if((fp_write = fopen("Test/boolean_function.c","wb"))==NULL) {
                printf("can't open the file");
                exit(0);
        }


        fprintf(fp_write,"#include <stdio.h> \n");
        fprintf(fp_write,"#include \"boolean_function.h\" \n");
        fprintf(fp_write, "void play (const int x[9], const int o[9], int new_o[9]) { \n");

        fprintf(fp_write,"/* %d Logical gates in total:\n", count);
        fprintf(fp_write," * %d NOT gates.\n", count_NOT);
        fprintf(fp_write," * %d AND gates.\n", count_AND);
        fprintf(fp_write," * %d OR  gates.\n */ \n", count_OR);

        fprintf(fp_write, " int A = x[0]; \n int B = x[1]; \n int C = x[2]; \n int D = x[3]; \n int E = x[4]; \n int F = x[5]; \n int G = x[6]; \n int H = x[7]; \n int I = x[8]; \n int a = o[0]; \n int b = o[1]; \n int c = o[2]; \n int d = o[3]; \n int e = o[4]; \n int f = o[5]; \n int g = o[6]; \n int h = o[7]; \n int i = o[8]; \n");

        fprintf(fp_write,"new_o[0] = ");
        fputs(out_0, fp_write);
        fprintf(fp_write,"; \n");

        fprintf(fp_write,"new_o[1] = ");
        fputs(out_1, fp_write);
        fprintf(fp_write,"; \n");

        fprintf(fp_write,"new_o[2] = ");
        fputs(out_2, fp_write);
        fprintf(fp_write,"; \n");

        fprintf(fp_write,"new_o[3] = ");
        fputs(out_3, fp_write);
        fprintf(fp_write,"; \n");

        fprintf(fp_write,"new_o[4] = ");
        fputs(out_4, fp_write);
        fprintf(fp_write,"; \n");

        fprintf(fp_write,"new_o[5] = ");
        fputs(out_5, fp_write);
        fprintf(fp_write,"; \n");

        fprintf(fp_write,"new_o[6] = ");
        fputs(out_6, fp_write);
        fprintf(fp_write,"; \n");

        fprintf(fp_write,"new_o[7] = ");
        fputs(out_7, fp_write);
        fprintf(fp_write,"; \n");

        fprintf(fp_write,"new_o[8] = ");
        fputs(out_8, fp_write);
        fprintf(fp_write,"; \n");

        fprintf(fp_write, " \n } \n");

        fclose(fp_write);

        printf("The boolean circuit generated contains %d logical gates in total:\n", count);
        printf("- %d NOT gates;\n", count_NOT);
        printf("- %d AND gates;\n", count_AND);
        printf("- %d  OR  gates.\n \n", count_OR);
}
