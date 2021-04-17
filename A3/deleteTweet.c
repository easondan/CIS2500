#include "headerA3.h"
void deleteTweet(tweet ** tweetList){
   int counter=0;
  int position;
  int i=0;
  tweet *next;
  tweet* countTemp=*tweetList;
  tweet* temp = *tweetList;
  //Goes thorugh the list and checks how many nodes there are 
  while(countTemp!=NULL){
    countTemp=countTemp->next;
     counter++;
  }
  //Promopts user and asks what tweet they wish to delete
  printf("Currently There are %d tweets\n",counter);
  printf("Which tweet do you wish to delete-enter a value between 1 and %d: ",counter);
  scanf("%d",&position);
  //treating as an array where array 1 is represented as index 0
  position--;
  //if the user chooses the first tweet 
    if (position == 0)
    {
      //goes to the first or head of the tweet
        *tweetList = temp->next;   
        //prints message and deletes the tweet by freeing the memory since function does not 
        //need to continue return void
         printf("Tweet %s deleted. There are now %d tweets left",temp->user,counter-1);
        free(temp);            
        return;
    }
    //if the position is not equal to the first node
    //The loop will move until it hits the desire position of the node
    //Counter coes up
    while(i<position-1){
       temp = temp->next;
      i++;
    }
    //When the correct position is there the node then will get deleted by freeing the memory
    next = temp->next->next;
      printf("Tweet %s deleted. There are now %d tweets left",temp->next->user,counter-1);
    free(temp->next); 
    temp->next = next;  

} 
