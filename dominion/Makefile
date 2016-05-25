CFLAGS = -Wall -fpic -ftest-coverage -lm -fprofile-arcs 

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

newdominion:
	gcc   -c newdominion.c -g  $(CFLAGS)

all: playdom player newdominion

playdominion:
	gcc playdominion.c -lm -coverage -o playdominion.out
	./playdominion.out 42 > playdominion.txt
playnewdominion:
	gcc playnewdominion.c -lm -coverage -o playnewdominion.out
	./playnewdominion.out 42 > playnewdominion.txt

playalldominion: playnewdominion playdominion

diffdominion: playalldominion
	gcc diffdominion.c -lm -coverage -o diffdominion.out
	./diffdominion.out > diffdominion.txt

unittest1:
	gcc unittest1.c -lm -coverage -o unittest1.out 
	./unittest1.out >unitresults.out
unittest2:
	gcc unittest2.c -lm -coverage -o unittest2.out 
	./unittest2.out >>unitresults.out
unittest3:
	gcc unittest3.c -lm -coverage -o unittest3.out 
	./unittest3.out >>unitresults.out
unittest4:
	gcc unittest4.c -lm -coverage -o unittest4.out
	./unittest4.out >>unitresults.out
cardtest1:
	gcc cardtest1.c -lm -coverage -o cardtest1.out
	./cardtest1.out >>unitresults.out
cardtest2:
	gcc cardtest2.c -lm -coverage -o cardtest2.out
	./cardtest2.out >>unitresults.out
cardtest3:
	gcc cardtest3.c -lm -coverage -o cardtest3.out
	./cardtest3.out >>unitresults.out
cardtest4:
	gcc cardtest4.c -lm -coverage -o cardtest4.out
	./cardtest4.out >>unitresults.out

cardtests: cardtest1 cardtest2 cardtest3 cardtest4

unittests: unittest1 unittest2 unittest3 unittest4

unitresults.out:  unittests cardtests
	gcov dominion.c >> unittestresults.out

randomtestcard1:	
	gcc randomtestcard1.c -lm -coverage -o randomtestcard1.out
	./randomtestcard1.out 42 >randomresults.out

randomtestcard2:	
	gcc randomtestcard2.c -lm -coverage -o randomtestcard2.out
	./randomtestcard2.out 42 >>randomresults.out

randomtestadventurer:	
	gcc randomtestadventurer.c -lm -coverage -o randomtestadventurer.out
	./randomtestadventurer.out 42 >>randomresults.out

randomresults.out: randomtestcard1 randomtestcard2 randomtestadventurer
	gcov dominion.c >> unittestresults.out
clean:
	rm -f *.out *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM
