#include "headerA3.h"
//This function allows you to search different keyword
 int searchTweetsByKeyword(tweet*tweetList){
   //use a tempoary tweet to copy the tweetlist to temp
   tweet *temp = tweetList;
    char keyWord[100];
    char *checkSearchWord;
    int trueFalse=0;
    //get user to enter a keyword and clear the standard input buffer and remove newline due to fgets
    printf("Enter a keyword: ");
    getchar();
      fgets(keyWord,sizeof(keyWord),stdin);
      keyWord[strlen(keyWord)-1]='\0';
      //use a while loop to go through the linked list
    while(temp!=NULL){
      //Using the function strcasestr which is a function which will find the first occurence
      //of the substring or in this case a keyword and will return NULL or a pointer
        checkSearchWord = strcasestr(temp->text,keyWord);
        //if the pointer is not equal to NUll then that means the keyword has been found and will return 1 
        //saying that the tweet has been found
    if(checkSearchWord != NULL){
       printf("Match found for ‘%s’: %s wrote: %s\n", keyWord,temp->user,temp->text);
       trueFalse=1;
    }
    //goes to the next node
    
  temp=temp->next;
 }
  return trueFalse;
    }