#include "gryphflix.h"
/*
  Student Name: Eason Liang
  Student ID: 1146154
  Due Date: 01/29,2021
  Course: CIS*2500
I have exclusive control over this submission via my password. By including this header comment, I certify that:
1) I have read and understood the policy on academic integrity. 2) I have completed Moodle's module on academic integrity.
3) I have achieved at least 80% on the academic integrity quiz
I assert that this work is my own. I have appropriate acknowledged any and all material that I have used, be it directly quoted or paraphrased. Furthermore, I certify that this assignment was written by me in its entirety.
*/	

//function is used to open the file accepts string for the file name
FILE * openFileForReading(char * fileName) {
	//Make a new variable called infile and then open the file return null if file cannot open or else return the file 
  FILE * infile;
  infile = fopen(fileName, "r");
	if(infile==NULL){
		printf("hihihihih");
		return NULL;
	}else{
		 return infile;
	}
 

}
//Function Used to read the data files movies take a file parameter an a 2d array for strings
int readMovies(FILE * file, char movieNames[NUMBER_MOVIES][MAX_STR]) {
  int i = 0;
	int j;
  int lenMovieNames[NUMBER_MOVIES];
	//Check if the file accesable or else it will return 0;
	if(file==NULL){
		return 0;
	}
	//Using a loop to go through the file and check if eof has been hit 
  while (!feof(file)) {
		//Read the data in the file 
    fgets(movieNames[i], MAX_STR, file);
		//Add to counter to check how many lines are read 
    i++;
  }
	i-=1;
	//Check if the amount of lines read are the same as the Number of movies if not return 0
	if(i>NUMBER_MOVIES){
		return 0;
	}else if(i<NUMBER_MOVIES){
		return 0;
	}
  fclose(file);
	//Using a loop and a if statement to remove the newlines on the movies
  for (j = 0; j < NUMBER_MOVIES-1; j++) {
    lenMovieNames[j] = strlen(movieNames[j]);
    movieNames[j][lenMovieNames[j] - 1] = '\0';
  }
  if (movieNames[NUMBER_MOVIES - 1][strlen(movieNames[NUMBER_MOVIES - 1]) - 1] == '\n') {
    lenMovieNames[NUMBER_MOVIES - 1] = strlen(movieNames[NUMBER_MOVIES - 1]);
    movieNames[NUMBER_MOVIES - 1][lenMovieNames[NUMBER_MOVIES - 1] - 1] = '\0';
  }
	// returns 1 if the file is read correctly 
  return 1;

}
//This function is used to read the reviews file 
int readReviews(FILE * file, struct reviewStruct reviews[NUMBER_REVIEWERS]) {
  int i = 0;
  char movies[NUMBER_REVIEWERS][NUMBER_MOVIES];
	char loner[50];
	//Check if the file is accesable and return 0 if not 
	if(file==NULL){
		return 0;
	}
//Using a while loop to check if end of the file exists 
 while(!feof(file)){
	 //Read the reviewr's name
 fscanf(file, "%s", reviews[i].reviewer);
 //Use fgetc to to indicate a new data to read 
    fgetc(file);
		//Using a loop to read the reviewrs feed back
    for (int j = 0; j < NUMBER_MOVIES; j++) {
      fscanf(file, "%c", & movies[i][j]);
      fgetc(file);
			//Converts the y and n in the file to 0 and 1
      if (movies[i][j] == 'y' || movies[i][j] == 'Y') {
        reviews[i].feedback[j] = 1;
      } else {
        reviews[i].feedback[j] = 0;
      }
			//Due to the new line it will store the new line character into a array 
				if(i==NUMBER_REVIEWERS-1&&j==NUMBER_MOVIES-1){
				fscanf(file,"%c", &loner[i]);
			}
    }
		//counts how many reviewers it reads 
  i++;
 }
 //if the amont of lines is less or more than NUMBER_REVIEWERS returns 0
	if(i>NUMBER_REVIEWERS){
		return 0;
	}else if(i<NUMBER_REVIEWERS){
		return 0;
	}
	fclose(file);

  // if data file is read sucessfully then it will return 1
  return 1;
}
//This function is used to get the most critical reviewers it takes in a parameter for a structure and a string array 
int getMostCriticalReviewers(struct reviewStruct reviews[NUMBER_REVIEWERS], char mostCriticalReviewers[NUMBER_REVIEWERS][MAX_STR]) {
  int total[NUMBER_REVIEWERS];
	int total2[NUMBER_REVIEWERS];
  int counter = 0;
  int returnCounter = 0;
	//Using a loop go through the array of 0 and 1s in the reviewrs feedback to check if which reviewers has said no
  for (int i = 0; i < NUMBER_REVIEWERS; i++) {
    for (int j = 0; j < NUMBER_MOVIES; j++) {
			//If the feedback is 0 then a counter will go up 
      if (reviews[i].feedback[j] == 0) {
        counter++;
      }
    }
		//Add total amount another array which will be used again to find the largest number
    total[i] = counter;
		total2[i] = counter;
    counter = 0;
  }
	//Find the largest element in the array using a sorting algorithum 
	Sort(total2, NUMBER_REVIEWERS);
	//Using a for loop go through the reviewrs amount of 0
  for (int i = 0; i < NUMBER_REVIEWERS; i++) {
		//If any reviwers has the same amount of 0 as the max
    if (total2[0] == total[i]) {
			//THe reviewers name is then copied on to the most getMostCriticalReviewers
      strcpy(mostCriticalReviewers[i], reviews[i].reviewer);
			//counts how many critcal reviewers there are 
      returnCounter++;
    }
  }
	//returns the amount of critical reviewers
  return returnCounter;
}
/*This function is used to find the most recommended movies it accepts a string array 
	and a structure reviewer array and a mostrecommend movie string array 
*/
int getMostRecommendedMovies(const char movies[NUMBER_MOVIES][MAX_STR],
  const struct reviewStruct reviews[NUMBER_REVIEWERS], char mostRecommendedMovies[NUMBER_MOVIES][MAX_STR]) {
  int counterYes = 0;
  int returnCounter = 0;
  int i, j;
  int yesCounter[NUMBER_MOVIES];
	int yesCounter2[NUMBER_MOVIES];
	//using a loop to look at the reviewers and the look at each rating for the movie 
  for (i = 0; i < NUMBER_MOVIES; i++) {
    for (j = 0; j < NUMBER_REVIEWERS; j++) {
			//Check if the movie has a 1 or a y in them 
      if (reviews[j].feedback[i] == 1) {
				// for each 1 it encounters the counter for goes 
        counterYes++;
      }
    }
		//Adds the amount of 1 for each movie into an array 
    yesCounter[i] = counterYes;
		yesCounter2[i]=counterYes;
		 counterYes = 0;
  }
	//find the largest integer value in the array 
	Sort(yesCounter2, NUMBER_MOVIES);
  for (i = 0; i < NUMBER_MOVIES; i++) {
		//Check if any movies has the same rating as the most recommended movies 
    if (yesCounter[i] == yesCounter2[0]) {
			//Writes the most recommended movies to the array most recommended movies 
      strcpy(mostRecommendedMovies[i], movies[i]);
			//Counter for most recommended movies goes up
      returnCounter++;
    }
  }
	//return the amount of recommended movies 
  return returnCounter;
}

//This function is used to predict how a movie will do and will only accept one string 
int predictMovie(const char movie[MAX_STR]) {
  char movie2[MAX_STR];
  int counter = 0;
  int sum = 0;
  int j = 0;
  int counterEven = 0;
	//Due to the string being constant we have to make another copy so the string can be manipulated
  strcpy(movie2, movie);
	//Using a loop to go through the string 
  for (int i = 0; movie2[i] != '\0'; i++) {
		//Check if there is a space in between a word 
    if (movie2[i] == ' ') {
			//Using a accumlator to count the amount of spaces 
      counter++;
    }
  }
	//If there are no spaces 
  if (counter == 0) {
		//Sum counter goes down by 2 
    sum -= 2;
		//If there is more than one space 
  } else if (counter > 0) {
		//Sum counter goes down by 
    sum -=1;
  }
	//Using strtok to find a space and seperate the string
  char * token = strtok(movie2, " ");
  char * moviesSplit[counter + 1];
  int counterCharacters[counter + 1];
	//Goes through the string and finds the space and then seperates the word and stops when null in the token cannot be found
  while (token != NULL) {
		//Split the word and put each word into the array 
    moviesSplit[j++] = token;
		//Make the space not represent anything after that 
    token = strtok(NULL, " ");
  }
	//use a loop to take each word in the array and count the length of each word 
  for (int i = 0; i < counter + 1; i++) {
    counterCharacters[i] = strlen(moviesSplit[i]);
  }
	//using a loop to go through the array for the amount of charcters
  for (int i = 0; i < counter + 1; i++) {
		//Checks each word is an even amount 
    if (counterCharacters[i] % 2 == 0) {
			//Adds it to a counter for the amount of even words 
      counterEven++;
    }
  }
	//If more than more one has an even number of characters 
  if (counterEven > 1) {
		//sum plus equal to 1
    sum += 1;
  }
	//This is used to check if the word has the same amount of character with all the other words 
  if (checkArrayValues(counterCharacters, counter + 1) == 1) {
    sum += 2;

  }
	//returns the result of the moviepredict
  return sum;
}
//This function is used to find the amount of words and each character count of each word 
int enumerateMovie(const char movie[MAX_STR], int charCounts[MAX_WORDS]) {
	char movie2[MAX_STR];
  int counter = 0;
  int j = 0;
	int stringCounter;
	//Copy the string in const char movie into another string in the function 
  strcpy(movie2, movie);
	//using a for loop to go through the string for movie 
  for (int i = 0; movie2[i] != '\0'; i++) {
		//checks if there a space and use a count to count the amount of spaces 
    if (movie2[i] == ' ') {
      counter++;
    }
  }
	//string counter is used to count the amount of words in the movie 
		stringCounter = counter+1;
		//Using strtok to break down the string that has a space in it 
	 char * token = strtok(movie2, " ");
  char * moviesSplit[stringCounter];
  int counterCharacters[stringCounter];
	//loops and stop when there are no spaces in the string for it to be processed 
  while (token != NULL) {
    moviesSplit[j++] = token;
    token = strtok(NULL, " ");
  }
	//Using a loop to add the amount of character in each word to the char counts array in the parameter 
	for (int i = 0; i < stringCounter; i++) {
    counterCharacters[i] = strlen(moviesSplit[i]);
		charCounts[i] = counterCharacters[i];
  }
	//returns the amount of words in the movie string 
  return stringCounter;
}


//This function is used to check if the element in the array are the same 
int checkArrayValues(int numbers[], int counter) {
	//using a loop to look through the array except the last array 
  for (int i = 0; i < counter - 1; i++) {
		//compare the i array and the next i array and check if the values are the same 
    if (numbers[i] != numbers[i + 1]) {
			//return 0 if the values are not the same 
      return 0;
    }
  }
	//return 1 if values are the same 
  return 1;
}
//Using a sorting algorithum(BUBBLE) to sort the values from high to low using bubble sort which compares one value from the next and swtiches them
void Sort(int numbers[], int counter) {
  for (int step = 0; step < counter - 1; ++step) {
    for (int i = 0; i <counter - step - 1; ++i) {
    
      if (numbers[i] < numbers[i + 1]) {
        
        int temp = numbers[i];
        numbers[i] = numbers[i + 1];
        numbers[i + 1] = temp;
      }
    }
  }
}
