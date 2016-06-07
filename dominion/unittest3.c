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
//testing compare
 
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

int i;
int j=100;
  int *a=malloc(sizeof(int));
  *a=rand();
  int *b=malloc(sizeof(int));
  *a=rand();
  if(*a>*b){
    assertEqu(compare(a,b),1);
  }
  else if(*a<*b){  
    assertEqu(compare(a,b),-1);
  }
  else{
    assertEqu(compare(a,b),0);
  }

	checkasserts();
	return 0;
}