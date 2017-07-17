#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Card 3: Steward
int main(){
	printf("Card Test 3: stewardCard()\n\n");
	struct gameState* state = malloc(sizeof(struct gameState));

	// Kingdom Cards
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	initializeGame(2, k, 1, state);
	int i;
	for (i = 0; i < 4; i++){
		state->hand[0][i] = steward;
	}
	state->coins = 0;
	stewardCard(state, 1, 2, 3, 0, 3);

	i = 0;
	while (state->hand[0][i] >= 0){
		i++;
	}
	if (i == 6)
		printf("PASS: 2 cards drawn.\n");
	else
		printf("FAIL: 2 cards not drawn.\n");

	initializeGame(2, k, 1, state);
	for (i = 0; i < 4; i++){
		state->hand[0][i] = steward;
	}
	state->coins = 0;
	stewardCard(state, 2, 2, 3, 0, 3);
	if (state->coins == 2)
		printf("PASS: 2 coins added.\n");
	else
		printf("FAIL: 2 coins not added.\n");

	return 0;
}