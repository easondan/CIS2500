#include "headerA4.h"

int main() {
  //Tail head and node pointers for the queue
  tweet * tail = NULL, * head = NULL;
  tweet * node = NULL;
  //use to keep count how many nodes are in the queue
  int size = 0;

  char enter = 0;
  //show that the queue is empty
  printf("Testing isEmpty function to check if the list is empty");
  isEmpty(head);
  printf("\nPress enter to continue\n");
  enter = 0;
  while (enter != '\r' && enter != '\n') {
    enter = getchar();
  }

  //User input gets user to add 5 nodes to the queue and print the nodes
  printf("\nAdding 5 Inital Nodes:\n");
  //use loop to create multple nodes
  for (int i = 0; i < 5; i++) {
    //make the node empty
    node = NULL;
    //create the tweet and add it to the queue
    node = createTweet(head);
    enqueue( & head, & tail, node);
    //node no longer needed so just free the memory
    free(node);
    size++;
  }
  printf("\nPrint the queue\n");
  printQueue(head);

  //Test the enquee function with user input and print the queue
  //use a loop to get multple nodes
  for (int i = 0; i < 3; i++) {
    printf("\nPress enter to continue\n");
    enter = 0;
    while (enter != '\r' && enter != '\n') {
      enter = getchar();
    }
    printf("\nTest Enqueue Function %d through user input\n", i + 1);
    node = NULL;
    //create the tweet and store it into the queue and print each node
    node = createTweet(head);
    enqueue( & head, & tail, node);
    printf("\nPrint the queue\n");
    printQueue(head);
    //free the node since the tweet is no longer need and a new one is made
    free(node);
    size++;
  }
  printf("\nPress enter to continue\n");
  enter = 0;
  while (enter != '\r' && enter != '\n') {
    enter = getchar();
  }
  //check if the list is empty now and print out the results
  printf("\nTesting isEmpty Function\n");
  isEmpty(head);
  printf("\nPrint the queue\n");
  printQueue(head);

  //Test the sortid functiona and sort them in assending order and print
  printf("\nPress enter to continue\n");
  enter = 0;
  while (enter != '\r' && enter != '\n') {
    enter = getchar();
  }
  printf("\nTesting sortID Function");
  sortID( & head, & tail);
  printf("\nPrint the queue\n");
  printQueue(head);

  //Reverse the order of the queue
  printf("\nPress enter to continue\n");
  enter = 0;
  while (enter != '\r' && enter != '\n') {
    enter = getchar();
  }
  printf("\nReverse the queue");
  reverse( & head, & tail);
  printf("\nPrint the queue\n");
  printQueue(head);

  //Sort the usernames in alpha order and print the results
  printf("\nPress enter to continue\n");
  enter = 0;
  while (enter != '\r' && enter != '\n') {
    enter = getchar();
  }
  printf("\nSort the usernames by calling sort usernames");
  sortUsername( & head, & tail);
  printf("\nPrint the queue\n");
  printQueue(head);

  //Call the dequee function and delete everything in the queue and print the results
  for (int i = 0; i < size; i++) {
    printf("\nPress enter to continue\n");
    enter = 0;
    while (enter != '\r' && enter != '\n') {
      enter = getchar();
    }
    printf("\nTesting Dequeue Function");
    dequeue( & head, & tail);
    printf("\nPrint the queue\n");
    printQueue(head);
  }
  size = 0;
  //Check if the queue is empty now
  printf("\nPress enter to continue\n");
  enter = 0;
  while (enter != '\r' && enter != '\n') {
    enter = getchar();
  }
  printf("\nTesting isEmpty Function");
  isEmpty(head);
  head = NULL;
  tail = NULL;

  //User input and use enqueue to add more nodes into the program and print the queue
  //use a loop to get multple nodes
  for (int i = 0; i < 3; i++) {
    printf("\nPress enter to continue\n");
    enter = 0;
    while (enter != '\r' && enter != '\n') {
      enter = getchar();
    }
    printf("\nTest Enqueue Function %d through user input\n", i + 1);
    node = NULL;
    //get user input for tweet and then add it to the queue and print the queue
    node = createTweet(head);
    enqueue( & head, & tail, node);
    printf("\nPress enter to continue\n");
    enter = 0;
    while (enter != '\r' && enter != '\n') {
      enter = getchar();
    }
    printf("\nPrint the queue\n");
    printQueue(head);
    //free memory as its not needed and a new tweet is put in
    free(node);
    size++;
  }

  //sort the ids in assending order and print out the queue
  printf("\nPress enter to continue\n");
  enter = 0;
  while (enter != '\r' && enter != '\n') {
    enter = getchar();
  }
  printf("\nTesting sortID Function");
  sortID( & head, & tail);
  printf("\nPrint the queue\n");
  printQueue(head);

  //reverse the queue and print out the queue
  printf("\nPress enter to continue\n");
  enter = 0;
  while (enter != '\r' && enter != '\n') {
    enter = getchar();
  }
  printf("\nTesting reverse Function");
  reverse( & head, & tail);
  printf("\nPrint the queue\n");
  printQueue(head);

  //Test sort id again to see if it will switch the order back
  printf("\nPress enter to continue\n");
  enter = 0;
  while (enter != '\r' && enter != '\n') {
    enter = getchar();
  }
  printf("\nTesting sortID Function");
  sortID( & head, & tail);
  printf("\nPrint the queue\n");
  printQueue(head);

  //Test sortUsername and sort them in alpha order and print the queue
  printf("\nPress enter to continue\n");
  enter = 0;
  while (enter != '\r' && enter != '\n') {
    enter = getchar();
  }
  printf("\nTesting Sort Username");
  sortUsername( & head, & tail);
  printf("\nPrint the queue\n");
  printQueue(head);

  //reverse the order of the list and print the queue
  printf("\nPress enter to continue\n");
  enter = 0;
  while (enter != '\r' && enter != '\n') {
    enter = getchar();
  }
  printf("\nTesting reverse function");
  reverse( & head, & tail);
  printf("\nPrint the queue\n");
  printQueue(head);

  //Sort it again to see if results are the same as the previous sortUsername and print results
  printf("\nPress enter to continue\n");
  enter = 0;
  while (enter != '\r' && enter != '\n') {
    enter = getchar();
  }
  printf("\nTesting Sort Username");
  sortUsername( & head, & tail);
  printf("\nPrint the queue\n");
  printQueue(head);
  clearList(head);
  return 0;
}