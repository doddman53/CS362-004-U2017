#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// greatHallCard
int main(int argc, char* argv[]){
	printf("Great Hall\n\n");
	struct gameState* state = malloc(sizeof(struct gameState));

	if (argc < 2) { printf("Please enter number of iterations.\n"); exit(0); }

	int iterations = atoi(argv[1]);

	int pass = 0, fail = 0;

	// Kingdom Cards
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int randomactions;
	while (iterations > 0){
		initializeGame(2, k, 1, state);
		int i;
		for (i = 0; i < 4; i++){
			state->hand[0][i] = great_hall;
		}

		// Random number of actions between 1 and 5
		randomactions = state->numActions = 1+ rand() % 5;
		//printf("randomactions = %i\n", randomactions);
		greatHallCard(state, 0, randomactions);

		//printf("numActions = %i\nrandomactions+1 = %i\n", state->numActions, randomactions + 1);

		if (state->numActions == randomactions + 1)
			//printf("PASS: numActions incremented by 1.\n");
			pass += 1;
		else
			//printf("FAIL: numActions not incremented by 1.\n");
			fail += 1;
		iterations--;
	}

	printf("Passes: %i\nFails: %i\n", pass, fail);
	return 0;
}