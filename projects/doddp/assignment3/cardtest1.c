#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Card 1: Adventurer
int main(){
	printf("Card Test 1: adventurerCard()\n\n");
	struct gameState* state = malloc(sizeof(struct gameState));
	int temphand[10];
	//memset(temphand, '\0', sizeof(temphand));
	int i;

	// Kingdom Cards
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	initializeGame(2, k, 1, state);

	for (i = 0; i < 5; i++){
		state->hand[0][i] = silver;
		//printf("%i\n", state->hand[0][i]);
	}
	for (i = 5; i < 10; i++){
		state->hand[0][i] = adventurer;
		//printf("%i\n", state->hand[0][i]);
	}
	state->deckCount[0] = 0;
	state->handCount[0] = 10;
	adventurerCard(state, 0, 0, temphand, 0, 0);

	i = 0;
	while (state->discard[0][i] > 0){
		i++;
	}

	// Hand = 1-5: silver, 6-10: adventurer. All 5 Adventurers should
	// be discarded.
	if (i == 5)
		printf("PASS: All 5 adventurers discarded\n");
	else
		printf("FAIL: Not all 5 adventurers discarded\n");
	return 0;
}