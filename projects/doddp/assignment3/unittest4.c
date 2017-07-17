#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
	printf("Unit Test 4: whosTurn()\n\n");
	struct gameState* state0 = malloc(sizeof(struct gameState));
	struct gameState* state1= malloc(sizeof(struct gameState));
	struct gameState* state2 = malloc(sizeof(struct gameState));
	struct gameState* state3 = malloc(sizeof(struct gameState));

	state0->whoseTurn = 0;
	state1->whoseTurn = 1;
	state2->whoseTurn = 2;
	state3->whoseTurn = 3;

	int who;
	who = whoseTurn(state0);
	if (who == 0)
		printf("PASS: whoseTurn == 0\n");
	else
		printf("FAIL: whoseTurn != 0\n");

	who = whoseTurn(state1);
	if (who == 1)
		printf("PASS: whoseTurn == 1\n");
	else
		printf("FAIL: whoseTurn != 1\n");

	who = whoseTurn(state2);
	if (who == 2)
		printf("PASS: whoseTurn == 2\n");
	else
		printf("FAIL: whoseTurn != 2\n");

	who = whoseTurn(state3);
	if (who == 3)
		printf("PASS: whoseTurn == 3\n");
	else
		printf("FAIL: whoseTurn != 3\n");

	return 0;
}