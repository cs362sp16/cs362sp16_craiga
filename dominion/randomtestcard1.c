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
//testing salvager
 
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
  printf("Test for salvager Failed.\n");
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
	int choice=randomSeed%(treasure_map+1);
	int *foo;
	int x=0;
	initializeGame(numPlayers, k, randomSeed,g);
	g->handCount[g->whoseTurn]=27;//makes hand size to fit every card
	for(x=0;x<27;x++)//populates hand with one of every card
	{
			g->hand[g->whoseTurn][x]=x;
	}
	assertEqu(g->discardCount[g->whoseTurn],0);//checks to make sure discard is empty
	int money=g->coins;//finds initial money for player
	/*for(x=0;x<g->handCount[g->whoseTurn];x++)
	{
		printf("%d ",g->hand[g->whoseTurn][x]);
	}
	printf("\n");(*/
	int expectedMoney=g->coins+getCost(g->hand[g->whoseTurn][choice]);//calculates expected new coins
	cardEffect(salvager,choice,0,0,g,0,foo);
	int money2=g->coins;//finds final money for player
	assertEqu(treasure_map-1,g->handCount[g->whoseTurn]);//checks to make sure hand is two smaller
	assertEqu(expectedMoney,money2);//checks to see if new money is correct
	assertEqu(1,g->discardCount[g->whoseTurn]);//checks to make sure discardcount is one
	checkasserts();
	return 0;
}