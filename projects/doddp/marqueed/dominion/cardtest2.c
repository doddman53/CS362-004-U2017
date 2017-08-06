#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Card 2: Smithy
int main(){

	struct gameState* state = malloc(sizeof(struct gameState));

	// Kingdom Cards
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	initializeGame(2, k, 1, state);
	int i;
	for (i = 0; i < 4; i++){
		state->hand[0][i] = smithy;
	}

	//smithyCard(state, 0, 0, 3); i = 0;
	smithyRefact(0, state, 3, 0);
	while (state->hand[0][i] >= 0){
		i++;
	}

	printf("Card Test: Smithy Refact\n\n");

	printf("Hand = 4 smithy. Play 1 smithy, draw three cards.\n");
	printf("Hand size should == 6 after playing 1 Smithy (4+3-1=6)\n");

	if (i == 6)
		printf("PASS: Correct hand size.\n");
	else
		printf("FAIL: Incorrect hand size. Hand size == %i\n", i);

	return 0;
}