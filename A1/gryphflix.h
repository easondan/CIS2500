#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUMBER_REVIEWERS 10
#define NUMBER_MOVIES 3
#define MAX_STR 50
#define MAX_WORDS 10

struct reviewStruct {
 char reviewer[MAX_STR];
 int feedback[NUMBER_MOVIES];
};

FILE *openFileForReading(char *fileName);
int readMovies(FILE *file, char movieNames[NUMBER_MOVIES][MAX_STR]);
int readReviews(FILE *file, struct reviewStruct reviews[NUMBER_REVIEWERS]);
int getMostCriticalReviewers(struct reviewStruct reviews[NUMBER_REVIEWERS],char mostCriticalReviewers[NUMBER_REVIEWERS][MAX_STR]);
int getMostRecommendedMovies(const char movies[NUMBER_MOVIES][MAX_STR],const struct reviewStruct reviews[NUMBER_REVIEWERS],char mostRecommendedMovies[NUMBER_MOVIES][MAX_STR]);
int predictMovie(const char movie[MAX_STR]);
int enumerateMovie(const char movie[MAX_STR], int charCounts[MAX_WORDS]);
//Check if all the values in the array are the same 
int checkArrayValues(int numbers[],int counter); 
//Using a sorting algo bubble sort to sort the array
void Sort(int array[], int size);