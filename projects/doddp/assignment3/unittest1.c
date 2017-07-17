#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// playCard() Unit Test
void playCardTest(int handPos, int choice1, int choice2, int choice3, struct gameState *state){
	
	int test;

	// Check for proper game phase
	state->phase = 1;
	test = playCard(handPos, choice1, choice2, choice3, state);
	if (test == -1)
		printf("PASS: if playCard fails due to improper game state.\n");
	else
		printf("FAIL: if playCard continues with improper game state.\n");
	
	// Check for player actions
	state->phase = 0;
	state->numActions = 0;
	test = playCard(handPos, choice1, choice2, choice3, state);
	if (test == -1)
		printf("PASS: playCard fails due to < 1 turns.\n");
	else
		printf("FAIL: playCard continues with < 1 turns.\n");

	// Test play card
	state->phase = 0;
	state->numActions = 1;
	test = playCard(handPos, choice1, choice2, choice3, state);
	if (test != -1)
		printf("PASS: cardEffect succeeds.\n");
	else
		printf("FAIL: cardEffect fails.\n");

	// Test numActions count
	state->phase = 0;
	state->numActions = 1;
	test = playCard(handPos, choice1, choice2, choice3, state);
	if (state->numActions == 0)
		printf("PASS: numActions is decremented.\n");
	else
		printf("FAIL: numActions is not decremented.\n");
}

int main(){
	printf("Unit Test 1: playCard()\n\n");
	// Initialize game state
	struct gameState* state = malloc(sizeof(struct gameState));
	int handPos = 1;
	int choice1 = 1;
	int choice2 = 2;
	int choice3 = 3;

	playCardTest(handPos, choice1, choice2, choice3, state);

	return 0;
}