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
//testing kingdomCards
 
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

assertEqu(k1,k[0]);
assertEqu(k2,k[1]);
assertEqu(k3,k[2]);
assertEqu(k4,k[3]);
assertEqu(k5,k[4]);
assertEqu(k6,k[5]);
assertEqu(k7,k[6]);
assertEqu(k8,k[7]);
assertEqu(k9,k[8]);
assertEqu(k10,k[9]);

	checkasserts();
	return 0;
}