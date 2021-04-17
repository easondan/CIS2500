#include "headerA3.h"
int main(void) {
    char input;
  int ifNumber;
	tweet *tweets=NULL;
 //Goes though a while loop checking the number of input the loop end when a user enters the number 8
 while(ifNumber!=8){
   //print menu options
    printf("\n1.Create a tweet\n2.Display tweets\n3.Search a tweet (by a keywod)\n4.Find how many are stop words\n5.Delete the nth tweet\n6.Save tweets to a file\n7.Load tweets from a file\n8.Exit\n");
	 printf("Choose a menu Option: ");
   //get input from the user and check if the input is a number if not then user must enter a input again until valid
	 scanf("%s",&input);
   ifNumber = atoi(&input);
   //If the input is valid and is a a number then it will then check if the value between 1 and 8 where it will call
   //the function
    if(ifNumber != 0){
      	if(ifNumber==1){
    addNodeToList(&tweets,createTweet(tweets));
	}else if(ifNumber==2){
		displayTweets(tweets);
	}else if(ifNumber==3){
		searchTweetsByKeyword(tweets);
	}else if(ifNumber==4){
		countStopWords(tweets);
	}else if(ifNumber==5){
    deleteTweet(&tweets);
	}else if(ifNumber==6){
    saveTweetsToFile(tweets);
	}else if(ifNumber==7){
    loadTweetsFromFile(&tweets);
	}else if(ifNumber==8){
    exit(0);
    //This error check is used to see if a user did not enter a number between 1 and 8
  }else{
    printf("invalid input\n");
  }
  //this error check is used to check if the input entered is a number
    }else{
      printf("invalid input\n");
    }
      

 }
  return 0;
}