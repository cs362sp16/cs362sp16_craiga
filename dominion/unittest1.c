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
//testing get cost
 
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
	assertEqu(getCost(curse),0);
	assertEqu(getCost(estate),2);
	assertEqu(getCost(duchy),5);
	assertEqu(getCost(province),8);
	assertEqu(getCost(copper),0);
	assertEqu(getCost(silver),3);
	assertEqu(getCost(gold),6);
	assertEqu(getCost(adventurer),6);
	assertEqu(getCost(council_room),5);
	assertEqu(getCost(feast),4);
	assertEqu(getCost(gardens),4);
	assertEqu(getCost(mine),5);
	assertEqu(getCost(remodel),4);
	assertEqu(getCost(smithy),4);
	assertEqu(getCost(village),3);
	assertEqu(getCost(baron),4);
	assertEqu(getCost(great_hall),3);
	assertEqu(getCost(minion),5);
	assertEqu(getCost(steward),3);
	assertEqu(getCost(tribute),5);
	assertEqu(getCost(ambassador),3);
	assertEqu(getCost(cutpurse),4);
	assertEqu(getCost(embargo),2);
	assertEqu(getCost(outpost),5);
	assertEqu(getCost(salvager),4);
	assertEqu(getCost(sea_hag),4);
	assertEqu(getCost(treasure_map),4);
	checkasserts();
	return 0;
}