for(x=0;x<numHandCards(g);x++)
	{
		printf("%d",g->hand[g->whoseTurn][x]);
	}
	printf("-final hand\n");
	for(x=0;x<g->deckCount[g->whoseTurn];x++)//replaces deck with estates and  two copper placed amongst the deck based on random seed.
	{
		printf("%d",g->deck[g->whoseTurn][x]);
	}
	printf("-final deck\n");