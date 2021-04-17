#include "headerA4.h"

//This function is used to add nodes to the end of the queue or the tail
void enqueue(tweet ** head, tweet ** tail, tweet * node) {
  //Allocate space for the node that will be added to the queue
  tweet * newNode = (tweet * )(malloc(sizeof(tweet)));

  // Assign the information from the node like id,username and tweet into the new node
  newNode -> id = node -> id;
  strcpy(newNode -> user, node -> user);
  strcpy(newNode -> text, node -> text);

  // Initially new node does not point anything
  newNode -> next = NULL;

  // Link new node with existing last node 
  if ( * tail != NULL) {
    ( * tail) -> next = newNode;
  }
  // Make sure newly created node is at rear
  * tail = newNode;

  // check if head it null since nodes can only be added to queue if the head is null then tail=head
  if ( (* head) == NULL) {
    * head = * tail;
  } else {
    return;
  }

}


//This function is used to delete the node at the front or head of the queue
void dequeue(tweet ** head, tweet ** tail) {
  //Checks if the head is null otherwise functions returns and stops
  if (head == NULL) {
    printf("\nThere nothing in the list that can be Deleted\n");
    return;
    //Proceeds to delete the node
  } else {
    //lets delete be temperory variable and make it equal to head and then delete it
    tweet * Delete = NULL;
    Delete = * head;
    * head = ( * head) -> next;
    free(Delete);
  }

}
//This function checks to see if queue is empty
int isEmpty(tweet * head) {
  //if there is nothing in the queue return true otherwise return false
  if (head == NULL) {
    printf("\nThe Queue is Empty");
    return 1;
  } else {
    printf("\nThe Queue is Not Empty");
    return 0;
  }
}
//this function is used to print out the queue
void printQueue(tweet * head) {
  //Check if the queue is empty
  if (head == NULL) {
    printf("\nNothing can be printed from the queue");
    return;
  } else {
    //prints out the queue and move to the next node
    while (head != NULL) {
      printf("%d: created by %s: %s\n", head -> id, head -> user, head -> text);
      head = head -> next;
    }
  }

}