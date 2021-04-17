#include "headerA4.h"
 //This function is used to a tweet or node which then the function will return the node 
//This function also accepts the parameter for tweets in this case its the linked list
tweet * createTweet(tweet * head) {
  int userID = 0;
  int length = 0;
  int random = 0;

  //makes room  for a new tweet
  tweet * newTweet = (tweet * )(malloc(sizeof(tweet)));
  //Promops the user for a user name and as well checks if the user enter over the required amount of characters
  printf("\nEnter a username: ");
  //use getchar to clear the standard input buffer
  while (strlen(fgets(newTweet -> user, 52, stdin)) > 51) {
    printf("Username is too Long try again: ");
  }
  //prompts the user to enter their text and check if the text exceed the character amount
  printf("Enter the user’s tweet: ");
  while (strlen(fgets(newTweet -> text, 152, stdin)) > 151) {
    printf("Tweet is too long try again: ");
  }

  //Get rid of the new lines in the user name and tweets
  newTweet -> user[strlen(newTweet -> user) - 1] = '\0';
  newTweet -> text[strlen(newTweet -> text) - 1] = '\0';
  //This first find the string length required for the user id as well with the loop it adds 
  //the ascii character of the person's user name to together which results in a user id when combined with the 
  // length of the tweet and the ascii values of a person's usename
  length = strlen(newTweet -> text);
  for (int i = 0; i < strlen(newTweet -> user); i++) {
    userID = userID + newTweet -> user[i];
  }
  userID = userID + length;

  //This is used to check whether this user id matches with someone elses if it is a random
  //number from 1-999 will be added to the user id and then after a print statment is used to show the id
  //as well the id is added to the tweet
  while (head != NULL) {
    if (head -> id == userID) {
      random += (rand() % (999) + 1);
    } else {
      random += 0;
    }
    userID += random;
    head = head -> next;
  }
  newTweet -> id = userID;

  printf("Your computer-generated user id is %d: ", userID);
  newTweet -> next = NULL;
  //returns the node

  return newTweet;
}

void clearList(tweet * head) {
  //Using recursion where the first condition is check if head is not equal to null
  if (head != NULL) {
    //go to the next node and free the current node
    tweet * next = head -> next;
    free(head);
    //recursive call to the next node
    clearList(next);
  }
}