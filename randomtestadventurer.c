#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void adventurerRandomTest(int iterations, struct gameState* state, int currentPlayer, int cardDrawn, int z, int drawntreasure){
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy };
	int temphand[10];
	memset(temphand, '\0', sizeof(temphand));
	int numPlayers;
	int i, card, passcount = 0, failcount = 0, count = 1;
	
	while (iterations > 0){

		//printf("Iteration %i\n", count++);

		numPlayers = 2 + rand() % 3;
		initializeGame(numPlayers, k, 1, state);
		currentPlayer = rand() % numPlayers;
		card = rand() % 10;
		cardDrawn = k[card];


		for (i = 0; i < 5; i++){
			state->hand[0][i] = silver;
		}

		for (i = 5; i < 10; i++){
			state->hand[0][i] = adventurer;
		}

		state->deckCount[0] = 0;
		state->handCount[0] = 10;
		adventurerCard(state, currentPlayer, cardDrawn, temphand, 0, 0);

		i = 0;
		while(state->discard[0][i] > 0){
			i++;
		}

		if (i == 5)
			//printf("PASS: All 5 adventurers discarded\n");
			passcount += 1;
		else
			failcount += 1;
			//printf("FAIL: Not all 5 adventurers discarded\n");
		iterations--;
	}
	printf("Total Passes: %i\n", passcount);
	printf("Total Fails: %i\n", failcount);
}


int main(int argc, char* argv[]){

	// Seed the time
	srand(time(NULL));

	if (argc < 2) { printf("Too Few Arguments - Specify a number of iterations\n"); exit(0); }

	int iterations = atoi(argv[1]);

	struct gameState* state = malloc(sizeof(struct gameState));
	int currentPlayer;
	int cardDrawn;
	int* temphand;
	int z;
	int drawntreasure;

	printf("Adventurer\n\n");
	adventurerRandomTest(iterations, state, currentPlayer, cardDrawn, z, drawntreasure);

	return 0;
}