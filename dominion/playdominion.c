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
//testing dominion.c

int main (int argc, char** argv) {
  struct gameState G;
  struct gameState *p = &G;
  int randomSeed=atoi(argv[1]);
  int i=0;
  int flag=0;
  int cards= (randomSeed%20)+7;
  int k[10] = {(cards%20)+7, ((cards+1)%20)+7, ((cards+2)%20)+7, ((cards+3)%20)+7, ((cards+4)%20)+7, ((cards+5)%20)+7, ((cards+6)%20)+7, ((cards+7)%20)+7, ((cards+8)%20)+7, ((cards+9)%20)+7};

  for(i=0;i<10;i++)
  {
    if (k[i]==gardens){
      flag=1;
    }
  }
  if(flag==0)
  {
    k[0]=gardens;
  }


  printf ("Starting game.\n");
  
  int players=(randomSeed)%4+1;
  if (players==1)
  {
  	players=2;
  }
  initializeGame(players, k, atoi(argv[1]), p);

  int money = 0;
  int purchaseCount= 1;
  int purchase=1;
  int played=0;
  printf("%d\n",isGameOver(p));
  printf("outside loop\n");
  while (!isGameOver(p)) {
  		int turn=whoseTurn(p);
  		played=1;
  		while((played<numHandCards(p))&&(p->numActions>0)){
  			playCard(played,1,1,1,p);
  			printf("player:%d playcard:%d\n",whoseTurn(p),handCard(played,p));
  			played++;
  		}
  		money=p->coins;
  		
      if(buyCard(gardens,p)!=-1)
      {
        printf ("Player 0: %d\nPlayer 1: %d\n", scoreFor(0, p), scoreFor(1, p));
      }

  		if(purchaseCount<6)
  		{
  			purchaseCount++;
  			purchase=purchaseCount;
  		}
  	 else if ((purchaseCount>5) &&(purchaseCount<17)){
  			purchaseCount++;
  			purchase= k[purchaseCount-6];
  		}
  		else{
  			purchaseCount=1;
  			purchase=1;
  		}

  		
  		if(buyCard(purchase,p)!=-1)
      {
        printf("player:%d bought:%d\n",whoseTurn(p),purchase);
      }
      printf ("Player 0: %d\nPlayer 1: %d\n", scoreFor(0, p), scoreFor(1, p));
  		endTurn(p);
  		
  	}
	     // end of While
  printf ("Finished game.\n");
  printf ("Player 0: %d\nPlayer 1: %d\n", scoreFor(0, p), scoreFor(1, p));
  return 0;
}
