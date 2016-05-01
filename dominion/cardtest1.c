#include "dominion.h"
#include "dominion.c"
#include "rngs.h"
#include "rngs.c"
#include "interface.c"
#include "interface.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>
//testing outpost
 
int failed = 0;

int assertEqu(int expected,int actual) {
  if (actual != expected) {
    printf("FAILED ASSERTION: actual=%d expected=%d\n", expected, actual);
    failed = 1;
  }
}

void checkasserts() {
  if (!failed) {
    printf ("TEST SUCCESSFULLY COMPLETED.\n");
  }
  else{
  printf("Test Failed.\n");
  }
}

int main() {
	srand(time(NULL));
	int* k = malloc(10 * sizeof(int));
	k=kingdomCards(1,2,3,4,5,6,7,8,9,10); 
	struct gameState* g;
	g=newGame();
	int randomSeed=rand();
	int numPlayers=4;
	int *foo;
	initializeGame(numPlayers, k, randomSeed,g);
	assertEqu(g->outpostPlayed,0);
	cardEffect(outpost,0,0,0,g,0,foo);
	assertEqu(g->outpostPlayed,1);
	checkasserts();
	return 0;
}