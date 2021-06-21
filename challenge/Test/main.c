#include <stdio.h>
#include "boolean_function.h"


void display(const int x[9], const int o[9], const int new_o[9]) {
				// this function displays the output new_o as 'n_O' with the other Xs and Os existed in the board
				printf("Output new_o: ");

				for (int i = 0; i < 9; i++) {
								printf("%d",new_o[i]);
				}
				printf("\n");

				for (int i = 0; i < 9; i++) {

								if (x[i] == 1) printf(" X ");
								else if (o[i] == 1) printf(" O ");
								else if (new_o[i] == 1) printf("n_O");
								else printf("   ");
								if ((i+1)%3 != 0) printf ("|");
								else if ((i+1) != 9)printf("\n---+---+---\n");
				}
				printf("\n \n");


}

int main() {

				// the main function tests and displays one possible complete game flow.

				int x[9] = {1,0,0,0,0,0,0,0,0};
				int o[9] = {0,0,0,0,0,0,0,0,0};
				int new_o[9] = {0,0,0,0,0,0,0,0,0};
				printf("Step 1:\n");
				play(&x[0],&o[0],&new_o[0]);
				display(x,o,new_o);

				int x_1[9] = {1,0,1,0,0,0,0,0,0};
				int o_1[9] = {0,0,0,0,1,0,0,0,0};
				int new_o_1[9] = {0,0,0,0,0,0,0,0,0};
				printf("Step 2:\n");
				play(&x_1[0],&o_1[0],&new_o_1[0]);
				display(x_1,o_1,new_o_1);

				int x_2[9] = {1,0,1,0,0,0,0,1,0};
				int o_2[9] = {0,1,0,0,1,0,0,0,0};
				int new_o_2[9] = {0,0,0,0,0,0,0,0,0};
				printf("Step 3:\n");
				play(&x_2[0],&o_2[0],&new_o_2[0]);
				display(x_2,o_2,new_o_2);

				int x_3[9] = {1,0,1,0,0,1,0,1,0};
				int o_3[9] = {0,1,0,1,1,0,0,0,0};
				int new_o_3[9] = {0,0,0,0,0,0,0,0,0};
				printf("Step 4:\n");
				play(&x_3[0],&o_3[0],&new_o_3[0]);
				display(x_3,o_3,new_o_3);

				int x_4[9] = {1,0,1,0,0,1,1,1,0};
				int o_4[9] = {0,1,0,1,1,0,0,0,1};
				int new_o_4[9] = {0,0,0,0,0,0,0,0,0};
				printf("Step 5:\n");
				play(&x_4[0],&o_4[0],&new_o_4[0]);
				display(x_4,o_4,new_o_4);

}
