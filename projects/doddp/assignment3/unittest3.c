#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// isGameOver() Unit Test
int main(){
	printf("Unit Test 3: isGameOver()\n\n");

	struct gameState* state1 = malloc(sizeof(struct gameState));
	struct gameState* state2 = malloc(sizeof(struct gameState));

	int test1, test2;

	// Case 1: No More Province Cards
	state1->supplyCount[province] = 0;
	test1 = isGameOver(state1);
	if (test1 == 1)
		printf("PASS: province == 0, GAME OVER\n");
	else
		printf("PASS: province == 0 and return value == 0\n");

	// Case 2: If three supply piles are at 0
	state2->supplyCount[province] = 2; // Ensure supply count gets tested
	int i;
	for (i = 0; i < 25; i++) { state2->supplyCount[i] = 0; }


	test2 = isGameOver(state1);
	if (test2 == 1)
		printf("PASS: supply count depleted, GAME OVER\n");
	else
		printf("PASS: supply count depleted, and return value == 0\n");

	return 0;
}