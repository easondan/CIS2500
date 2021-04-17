#include "headerA3.h"
/*This function is used to add the nodes to the tweet list 
it takes in the tweetList which contains the tweet and a specific 
tweet that is then stored in that tweet list
*/
void addNodeToList(tweet**tweetList,tweet * node){
  //if there is nothing in the list then the node then becomes the head tweet
		if(*tweetList == NULL){
			  *tweetList = node;
}
//Other than that this if statement will check if the list of tweets are empty or and will proceed to 
//make another tweet which is the last tweet and will be added to the end of the list
    else if(tweetList!=NULL)
    {
      tweet *lastTweet = *tweetList;
        
        while(lastTweet->next != NULL)
        {
            lastTweet = lastTweet->next;
        }

        lastTweet->next = node;
    }

}
