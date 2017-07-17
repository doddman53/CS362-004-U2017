#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// getWinners() Unit Test
int main(){
	printf("Unit Test 2: getWinners()\n\n");
	// Initialize game state
	struct gameState* state_2players = malloc(sizeof(struct gameState));
	struct gameState* state_3players = malloc(sizeof(struct gameState));
	struct gameState* state_4players = malloc(sizeof(struct gameState));

	// Initialize Test Arrays
	int players2[2];
	int players3[3];
	int players4[4];

	// Kingdom Cards
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};


	// Initialize test cases

		// 2 players
	initializeGame(2, k, 1, state_2players);
	int i;
	
	for (i = 0; i < 5; i++){
		state_2players->hand[0][i] = duchy;
		state_2players->hand[1][i] = estate;
	}
	
	for (i = 5; i < 10; i++){
		state_2players->hand[0][i] = province;
		state_2players->hand[1][i] = gardens;
	}
	getWinners(players2, state_2players);
	printf("Case: 2 players\n");
	if (players2[0] == 1 && players2[1] == 0)
		printf("PASS: Player 1 wins\n");
	else
		printf("FAIL: Player 1 loses\n");

		// 3 players
	initializeGame(3, k, 1, state_3players);
	
	for (i = 0; i < 5; i++){
		state_3players->hand[0][i] = duchy;
		state_3players->hand[1][i] = estate;
		state_3players->hand[2][i] = great_hall;
	}
	
	for (i = 5; i < 10; i++){
		state_3players->hand[0][i] = province;
		state_3players->hand[1][i] = gardens;
		state_3players->hand[2][i] = curse;
	}
	getWinners(players3, state_3players);
	printf("Case: 3 players\n");
	if (players3[0] == 1 && players3[1] == 0 && players3[2] == 0)
		printf("PASS: Player 1 wins\n");
	else
		printf("FAIL: Player 1 loses\n");

		// 4 players
	initializeGame(4, k, 1, state_4players);
	
	for (i = 0; i < 5; i++){
		state_4players->hand[0][i] = duchy;
		state_4players->hand[1][i] = estate;
		state_4players->hand[2][i] = great_hall;
		state_4players->hand[3][i] = gardens;
	}
	
	for (i = 5; i < 10; i++){
		state_4players->hand[0][i] = province;
		state_4players->hand[1][i] = gardens;
		state_4players->hand[2][i] = curse;
		state_4players->hand[3][i] = great_hall;
	}
	getWinners(players4, state_4players);
	printf("Case: 4 players\n");
	if (players4[0] == 1 && players4[1] == 0 && players4[2] == 0 && players4[3] == 0)
		printf("PASS: Player 1 wins\n");
	else
		printf("FAIL: Player 1 loses\n");
	

	return 0;
}