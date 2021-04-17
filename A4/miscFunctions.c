#include "headerA4.h"

//Bubble sort to sort id
void sortID(tweet ** head, tweet ** tail) {
  //current represents the current node and next represent the next node in from of the current node
  tweet * currentNode = * head, * nextNode = NULL;
  //temp variable for tweet
  tweet temp;
  //checks if the queue is Empty and functions stops after if it is NULL
  if (head == NULL && tail == NULL) {
    printf("\nUnable To sort List Due to it being Empty");
    return;
  } else {
    //Use a while loop to move through the queue
    while (currentNode != NULL) {
      //Node index will point to node next to current  
      nextNode = currentNode -> next;
      //use a while loop to move through the queue for the nextNode
      while (nextNode != NULL) {
        //If current node's data is greater than index's node data, swap the data between them  
        if (currentNode -> id > nextNode -> id) {
          //tempoary tweet equal to current node
          temp.id = currentNode -> id;
          strcpy(temp.user, currentNode -> user);
          strcpy(temp.text, currentNode -> text);
          //current info = to the next node
          currentNode -> id = nextNode -> id;
          strcpy(currentNode -> user, nextNode -> user);
          strcpy(currentNode -> text, nextNode -> text);
          //next node is equal to temp node
          nextNode -> id = temp.id;
          strcpy(nextNode -> user, temp.user);
          strcpy(nextNode -> text, temp.text);
        }
        //moves through the next node for the next node
        nextNode = nextNode -> next;
      }
      //for the current node go to the next node
      currentNode = currentNode -> next;
    }
    //print statement to show it was a Success
    printf("\nSucesss List of id was sorted");
  }
}
//This function is used to put te list in reverse 
void reverse(tweet ** head, tweet ** tail) {
  tweet * prev = NULL;
  tweet * current = * head;
  tweet * next;
  //Checks if the queue is Empty which then returns void to end the function
  if (head == NULL && tail == NULL) {
    printf("\nThere is nothing in the list that can be used to reverse");
    return;
  } else {
    //moves through the queue
    while (current != NULL) {
      //Swap each nodes until the list becomes reverse
      next = current -> next;
      current -> next = prev;
      prev = current;
      current = next;
    }
    //swap head with the last node at the tail
    * head = prev;
  }
  printf("\nSuccess List has been reversed");
}
//Use bubble sort and string compare to sort the Usernames in alpha order
void sortUsername(tweet ** head, tweet ** tail) {

  //variables for current and the next node after current
  tweet * currentNode = * head, * nextNode = NULL;
  //temp variable for tweet
  tweet temp;
  //checks if the queue is Empty and functions stops after if it is NULL
  if (head == NULL && tail == NULL) {
    printf("\nUnable to Sort List due to it being Empty");
    return;
  } else {
    //Use a while loop to move through the queue
    while (currentNode != NULL) {
      //Node index will point to node next to current  
      nextNode = currentNode -> next;
      //use a while loop to move through the queue for the nextNode
      while (nextNode != NULL) {
        //If current node's data is greater than index's node data, swap the data between them  
        if (strcasecmp(currentNode -> user, nextNode -> user) > 0) {
          
          //tempoary tweet equal to current node
          temp.id = currentNode -> id;
          strcpy(temp.user, currentNode -> user);
          strcpy(temp.text, currentNode -> text);
          //current info = to the next node
          currentNode -> id = nextNode -> id;
          strcpy(currentNode -> user, nextNode -> user);
          strcpy(currentNode -> text, nextNode -> text);
          //next node is equal to temp node
          nextNode -> id = temp.id;
          strcpy(nextNode -> user, temp.user);
          strcpy(nextNode -> text, temp.text);
        }
        //moves through the next node for the next node
        nextNode = nextNode -> next;
      }
      //for the current node go to the next node
      currentNode = currentNode -> next;
    }
    //print statement to show it was a Success
    printf("\nSucesss List of usernames was sorted");
  }
}