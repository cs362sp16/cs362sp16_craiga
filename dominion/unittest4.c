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
//testing newgame
 
int failed = 0;

int assertIsGame(struct gameState* g, int* k) {
  int randomSeed=17;
  int numPlayers=4;
  initializeGame(numPlayers, k, randomSeed,g);
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
int k1=rand();
int k2=rand();
int k3=rand();
int k4=rand();
int k5=rand();
int k6=rand(); 
int k7=rand();
int k8=rand(); 
int k9=rand(); 
int k10=rand();
int* k = malloc(10 * sizeof(int));
k=kingdomCards(k1,  k2,  k3,  k4,  k5,  k6, k7,  k8,  k9, k10); 


struct gameState* g;
g=newGame();
assertIsGame(g,k);

checkasserts();
return 0;
}