CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc   -c dominion.c -g  $(CFLAGS) 
	
playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player

unittest1:
	gcc unittest1.c -lm -o unittest1.out 
	./unittest1.out >unitresults.out
unittest2:
	gcc unittest2.c -lm -o unittest2.out 
	./unittest2.out >>unitresults.out
unittest3:
	gcc unittest3.c -lm -o unittest3.out 
	./unittest3.out >>unitresults.out
unittest4:
	gcc unittest4.c -lm -o unittest4.out
	./unittest4.out >>unitresults.out
cardtest1:
	gcc cardtest1.c -lm -o cardtest1.out
	./cardtest1.out >>unitresults.out
cardtest2:
	gcc cardtest2.c -lm -o cardtest2.out
	./cardtest2.out >>unitresults.out
cardtest3:
	gcc cardtest3.c -lm -o cardtest3.out
	./cardtest3.out >>unitresults.out
cardtest4:
	gcc cardtest4.c -lm -o cardtest4.out
	./cardtest4.out >>unitresults.out

cardtests: cardtest1 cardtest2 cardtest3 cardtest4

unittests: unittest1 unittest2 unittest3 unittest4

unitresults.out:  unittests cardtests

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM
