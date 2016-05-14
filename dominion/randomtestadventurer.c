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
//testing adenturer
 
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
  printf("Test for adventurer Failed.\n");
  }
}

int main(int argc,char *argv[]) {

	srand(time(NULL));
	int randomSeed=atoi(argv[1]);
	int* k = malloc(10 * sizeof(int));
	k=kingdomCards(1,2,3,4,5,6,7,8,9,10); 
	struct gameState* g;
	g=newGame();
	int numPlayers=4;
	int *foo;
	initializeGame(numPlayers, k, randomSeed,g);
	assertEqu(numHandCards(g),5);//test for initial hand size
	int x=0;
	int cashcount=0;
	int cardcount=g->handCount[g->whoseTurn]+g->deckCount[g->whoseTurn]+g->discardCount[g->whoseTurn];
	int copperplace=randomSeed%(g->deckCount[g->whoseTurn]);
	int copperplace2=(randomSeed*randomSeed+1)%(g->deckCount[g->whoseTurn]);
	for(x=0;x<g->deckCount[g->whoseTurn];x++)//populates deck with all estates except for 2 copper in random postions based on seed
	{
		if(x==copperplace||x==copperplace2){
			g->deck[g->whoseTurn][x]=4;
		}
		else{
			g->deck[g->whoseTurn][x]=1;
		}
	}
	for(x=0;x<MAX_HAND;x++)
	{
		if (g->hand[g->whoseTurn][x]== copper || g->hand[g->whoseTurn][x]== silver || g->hand[g->whoseTurn][x]== gold)
		{
			cashcount++;
		}
	}
	cardEffect(adventurer,0,0,0,g,0,foo);
	int cardcount2=g->handCount[g->whoseTurn]+g->deckCount[g->whoseTurn]+g->discardCount[g->whoseTurn];
	assertEqu(numHandCards(g),7);//test for final hand size
	int cashcount2=0;
	for(x=0;x<MAX_HAND;x++)
	{
		if (g->hand[g->whoseTurn][x]== copper || g->hand[g->whoseTurn][x]== silver || g->hand[g->whoseTurn][x]== gold)
		{
			cashcount2++;
		}
	}
	assertEqu(cashcount,cashcount2-2);//verifies two monetary cards were added into hand
	assertEqu(cardcount,cardcount2);//verifies that other cards were discarded and overall number of cards stayed the same
	checkasserts();
	return 0;
}