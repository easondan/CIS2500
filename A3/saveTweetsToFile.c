#include "headerA3.h"
//This function is used to save the list of tweets into a data file and takes a linked list tweet
void saveTweetsToFile(tweet * tweetList){
  //Make a new variable called temp and make it equal to the list
  tweet *temp = tweetList;
  //Clear the input buffer and get userinput for the filename and remove the newline so it prevents seg faults
  char fileName[100];
  printf("Enter the filename where you would like to store your tweets: ");
  getchar();
  fgets(fileName,sizeof(fileName),stdin);
  fileName[strlen(fileName)-1]='\0';
  //writing to file
   FILE *fp;
  fp=fopen(fileName, "w");
  //check if file can be open if not prints that its unable to access the file
  if(fp==NULL){
    printf("Unable to write to the file");
  }
  //use a loop to go through the linked list
  while(temp!=NULL){
    //save stuff into the data file from the linked list and the move on to the next list until it reaches the end

      if(temp!=NULL){
        fprintf(fp,"%d,%s,%s,\n",temp->id,temp->user,temp->text);
      }
      temp=temp->next;
      //when it hits the end of the list output is then successful
      if(temp==NULL){
        printf("Output successful!");
      }
  }
  //close the file

  fclose(fp);
}