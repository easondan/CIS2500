#include "headerA3.h"
#include "functionA3.h"
//This function is used to count the amount of stop words where it only considers the top 25
void countStopWords(tweet * tweetList){
   int counter=0;
   int counter2=0;
    tweet *temp = tweetList;
  char words[25][10]={"a","an","and","are","as",
"at","be","by","for","from","has","he","in","is","it","its", "of","on","that","the","to","was","were","will","with"};
//This loop goes through the linked list for each tweet
    while(temp!=NULL){
      //After that is then takes the tweet and goes through and calls a function which then tries to find the the stop words
      //As well this function returns the amount of words that occure for a specific word
      for(int i=0;i<25;i++){
        counter2+=countOccuringWords(temp->text,words[i]);
      }
      //Use this to proceed to the next node in the linked list
      temp=temp->next;
        counter++;
    }
   //prints a statement on how many stop words there are as well as tweets
    printf("Across %d tweets,%d stop words were found.",counter,counter2);
}

