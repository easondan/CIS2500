#include "headerA3.h"
void loadTweetsFromFile(tweet ** tweetList){
  FILE *fp=NULL;  
    char fileName[1000];
     char arrays[1000];
   char *token;
  tweet *temp2;
  printf("Enter a filename to load from: ");
  getchar();
  fgets(fileName, 1000, stdin);
  fileName[strlen(fileName)-1]='\0';
  fp=fopen(fileName,"r");
  if(fp==NULL){
    printf("File Cannot be found");
    return;
  }
    while(!feof(fp)){
      temp2 = malloc(sizeof(tweet));
      fgets(arrays, 1000, fp);
      temp2->next=NULL;
    token =strtok(arrays,",");
    temp2->id=atoi(token);
    token = strtok(NULL,",");
    strcpy(temp2->user, token);
    token = strtok(NULL,"\n");
    token[(strlen(token)-1)]='\0';
    strcpy(temp2->text, token);
    addNodeToList(tweetList, temp2);
    }
  
  fclose(fp);
 printf("Tweets imported!"); 
}