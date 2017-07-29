#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Smithy
int main(int argc, char* argv[]){

	struct gameState* state = malloc(sizeof(struct gameState));

	int iterations = atoi(argv[1]);

	if (argc < 2) { printf("Please Enter number of iterations\n"); exit(0); }

	printf("Smithy\n\n");

	int randcard, passcount = 0, failcount = 0;

	while (iterations > 0){
		// Kingdom Cards
		int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

		randcard = 1 + rand() % 3;
		//printf("randcard = %i\n", randcard);

		initializeGame(2, k, 1, state);
		int i;
		for (i = 0; i < randcard; i++){
			state->hand[0][i] = smithy;
		}

		smithyCard(state, 0, 0, randcard); i = 0;
		while (state->hand[0][i] >= 0){
			i++;
		}
		//printf("i = %i randcard+2 = %i\n", i, randcard + 2);
		if (i == (randcard + 2))
			//printf("PASS: Correct hand size.\n");
			passcount += 1;
		else
			//printf("FAIL: Incorrect hand size. Hand size == %i\n", i);
			failcount += 1;
		iterations--;
	}
	printf("Number of passes: %i\n", passcount);
	printf("Number of fails: %i\n", failcount);
	return 0;
}