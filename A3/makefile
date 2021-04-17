CC=gcc
CFLAGS=-Wall	-std=c99
tweet:	main.o	createTweet.o	displayTweets.o	searchTweetsByKeyword.o	countStopWords.o deleteTweet.o	saveTweetsToFile.o loadTweetsFromFile.o addNodeToList.o countOccuringWords.o
	$(CC)	$(CFLAGS)		main.o	createTweet.o	displayTweets.o	searchTweetsByKeyword.o	countStopWords.o deleteTweet.o	saveTweetsToFile.o loadTweetsFromFile.o addNodeToList.o countOccuringWords.o -o	tweet
createTweet.o:	createTweet.c	headerA3.h
	$(CC)	$(CFLAGS)	-c	createTweet.c
displayTweets.o:	displayTweets.c	headerA3.h
	$(CC)	$(CFLAGS)	-c	displayTweets.c
searchTweetsByKeyword.o:	searchTweetsByKeyword.c	headerA3.h
	$(CC)	$(CFLAGS)	-c	searchTweetsByKeyword.c  -D_GNU_SOURCE
countStopWord.o:	countStopWords.c	headerA3.h functionA3.h
	$(CC)	$(CFLAGS)	-c	countStopWords.c
deleteTweet.o:	deleteTweet.c	headerA3.h
	$(CC)	$(CFLAGS)	-c	deleteTweet.c
saveTweetsToFile.o:	saveTweetsToFile.c	headerA3.h
	$(CC)	$(CFLAGS)	-c	saveTweetsToFile.c
loadTweetsFromFile.o:	loadTweetsFromFile.c	headerA3.h
	$(CC)	$(CFLAGS)	-c	loadTweetsFromFile.c
addNodeToList.o:	addNodeToList.c	headerA3.h
	$(CC)	$(CFLAGS)	-c	addNodeToList.c
countOccuringWords.o:	countOccuringWords.c	headerA3.h functionA3.h
	$(CC)	$(CFLAGS)	-c	countOccuringWords.c
main.o:	main.c	headerA3.h
	$(CC)	$(CFLAGS)	-c	main.c
clean:
	rm	*.o	tweet	