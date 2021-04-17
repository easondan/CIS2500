#include "gryphflix.h"
int main(void) {
  char movieNames[NUMBER_MOVIES][MAX_STR];
  int charCounts[MAX_WORDS];
  struct reviewStruct critics[NUMBER_REVIEWERS];
  char people[NUMBER_REVIEWERS][MAX_STR];
  char movie[NUMBER_MOVIES][MAX_STR];
	if(readMovies(openFileForReading("movies.txt"), movieNames)==1){
		printf("%d File Open sucessfully\n", readMovies(openFileForReading("movies.txt"), movieNames));
	}else if(readMovies(openFileForReading("movies.txt"), movieNames)==0){
		printf("%d Cannot open file or passing a file more or less than NUMBER_MOVIES Lines\n", readMovies(openFileForReading("movies.txt"), movieNames));
	}
  for (int i = 0; i < NUMBER_MOVIES; i++) {
    printf("%s\n", movieNames[i]);
  }


  if(readReviews(openFileForReading("reviews.txt"), critics)==1){
		printf("%d File Open sucessfully\n", readReviews(openFileForReading("reviews.txt"), critics));
	}else if(readReviews(openFileForReading("reviews.txt"), critics)==0){
		printf("%d Cannot open file or passing a file more or less than NUMBER_REVIEWERS Lines\n", readReviews(openFileForReading("reviews.txt"), critics));
	}
  for (int i = 0; i < NUMBER_REVIEWERS; i++) {
    printf("%s ", critics[i].reviewer);
    for (int j = 0; j < NUMBER_MOVIES; j++) {
      printf("%d ", critics[i].feedback[j]);
    }
    printf("\n");
  }


  printf("Number of haters:%d\n", getMostCriticalReviewers(critics, people));
  for (int i = 0; i < NUMBER_REVIEWERS; i++) {
    if (strcmp(people[i], "") != 0) {
      printf("People you should avoid:%s\n", people[i]);
    } 
  }

  printf("How many Movies are Recommended: %d\n", getMostRecommendedMovies(movieNames, critics, movie));
  for (int i = 0; i < NUMBER_MOVIES; i++) {
		 if (strcmp(movie[i], "") != 0) {
			 printf("Most Popular Movie:%s\n", movie[i]);
    } 
  }

  printf("Score:%d\n", predictMovie(movieNames[0]));
  printf("How many words does this movie have:%d\n", enumerateMovie(movieNames[2], charCounts));
  for (int i = 0; i < MAX_WORDS; i++) {
    printf("%d Letters in the %d word\n", charCounts[i],i+1);
  }
  return 0;
}