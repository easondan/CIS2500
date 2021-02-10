#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LENGTH 100
int main(void) {
  char ** sptr;
  int counter, trueFalse, sum,i = 0;
  int k=0;
	 char * token;
	 char words[LENGTH];
	int counter28=0;
  sptr = malloc(sizeof(char * ) * i);
  int * sptr2;
  sptr2 = malloc(sizeof(int * ) * i);
  while (trueFalse != 1) {
    sptr[k] = malloc(sizeof(char) * LENGTH);
    i++;
    fgets(sptr[k], LENGTH + 2, stdin);
    if (strlen(sptr[k]) > LENGTH) {
      exit(EXIT_FAILURE);
    }
    if (sptr[k][0] == 10) {
      exit(EXIT_FAILURE);
    }
		if(sptr[k][0]=='.'){
			trueFalse=1;
		}
    sptr[k][strlen(sptr[k]) - 1] = '\0';
		token = strtok(sptr[k]," ");
		while(token!=NULL){
			strcpy(words, token);
			if(strlen(words)>20){
			exit(EXIT_FAILURE);
			}else{
			counter28++;
		 token = strtok(NULL, " ");
		 	strcpy(words,"\0");	
			}

		}
    sptr2[counter] = counter28;
    counter++;
		if(token==NULL){
			counter28=0;
		}
    sptr = realloc(sptr, i * sizeof(char * ));
		sptr2 = realloc(sptr2,i*sizeof(int*));
	}
	free(sptr);
	counter--;
	 for (int i = 0; i < counter; i++) {
    sum +=sptr2[i];
  }
  printf("%d words on %d lines\n", sum, counter);
	for(int i=0;i<counter;i++){
			
		printf("%d ",sptr2[i]);
	}
	free(sptr2);
  return 0;
}
