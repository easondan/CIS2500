#include "headerA3.h"
//this function is used to display the tweets in a specific format
//This is used to take a tweet or in this case the linked for the tweets
void displayTweets(tweet * tweetList){
  //make a temporary variable
tweet * temp = tweetList;

//using recursion where the case 1 is temp!=1 this will get recursivly called until temp==NULL
//And from that the list of tweets will be printed out
if(temp!=NULL){
	printf("%d: created by %s: %s\n",temp->id,temp->user,temp->text);
displayTweets(temp->next);

}

}


