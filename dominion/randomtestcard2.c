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
//testing gardens
 
int failed = 0;

int assertEqu(int expected,int actual) {
  if (actual != expected) {
    printf("FAILED ASSERTION: expected=%d acutal=%d\n", expected, actual);
    failed = 1;
  }
}

void checkasserts() {
  if (!failed) {
    printf ("TEST SUCCESSFULLY COMPLETED.\n");
  }
  else{
  printf("Test for gardens Failed.\n");
  }
}

int main(int argc,char *argv[]) {
	srand(time(NULL));
	int* k = malloc(10 * sizeof(int));
	k=kingdomCards(1,2,3,4,5,6,7,8,9,10); 
	struct gameState* g;
	g=newGame();
	int randomSeed=atoi(argv[1]);
	int numPlayers=4;
	int *foo;
	int x=0;
	initializeGame(numPlayers, k, randomSeed,g);
	g->deckCount[g->whoseTurn]=randomSeed;//makes deck size of random seed
	for(x=0;x<g->deckCount[g->whoseTurn];x++)//populates deck with all copper
	{
			g->deck[g->whoseTurn][x]=4;
			if ((g->deckCount[g->whoseTurn]-1)==x)
			{
				g->deck[g->whoseTurn][x]=gardens;
			}
	}
	g->handCount[g->whoseTurn]=1;//makes size of the hand 1
	g->hand[g->whoseTurn][0]=gardens;//replaces hand with garden card
	
	assertEqu(cardEffect(gardens,0,0,0,g,0,foo),-1);
	int score=scoreFor(g->whoseTurn, g);//finds score for player
	int expectedScore=(g->deckCount[g->whoseTurn]+1)/10;//calculates expected score based on deck size
	assertEqu(expectedScore,score);
	checkasserts();
	return 0;
}