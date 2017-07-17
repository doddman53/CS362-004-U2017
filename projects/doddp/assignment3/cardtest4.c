#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Card 4: greatHallCard
int main(){
	printf("Card Test 4: greatHallCard()\n\n");
	struct gameState* state = malloc(sizeof(struct gameState));

	// Kingdom Cards
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	initializeGame(2, k, 1, state);
	int i;
	for (i = 0; i < 4; i++){
		state->hand[0][i] = great_hall;
	}

	state->numActions = 1;
	greatHallCard(state, 0, 3);

	if (state->numActions == 2)
		printf("PASS: numActions incremented by 1.\n");
	else
		printf("FAIL: numActions not incremented by 1.\n");
	
	return 0;
}