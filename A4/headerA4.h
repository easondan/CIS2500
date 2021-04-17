#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
typedef struct microtweet {
 int id; //non-unique integer value
 char user [51]; // the username / userid of the person who wrote the tweet
 char text [141]; // the text of the tweet
 struct microtweet *next; //dynamic connection to the next tweet
} tweet;

//Queue Functions
void enqueue (tweet ** head, tweet ** tail, tweet * node);
void dequeue (tweet ** head, tweet ** tail);
int isEmpty (tweet * head);
void printQueue (tweet * head);
//misc Functions
void sortID (tweet ** head, tweet ** tail);
void reverse (tweet ** head, tweet ** tail);
void sortUsername (tweet ** head, tweet ** tail);
//Helper Functions
tweet * createTweet(tweet*head);
void clearList(tweet*head);

