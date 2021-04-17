#include "fleschIndex.h"

char * readFile(char * fileName) { //This function is used to read the file
  FILE * fp;
  char ** sPtr;
  char * sPtr2;
  int counter = 0;
  int i = 0;
  int k = 0;
  int size;
	//Open the file
  fp = fopen(fileName, "r");
	//If file does not exist the program will exit
  if (fp == NULL) {
    printf("file cannot be found");
		exit(0);
  } else {
		//if file is found get the size of the file  and allocate memory for that size and then read the file
    size = getSize(fileName);
    rewind(fp);
    sPtr = malloc(size);
    sPtr2 = malloc(size);
    char words[size];
    while (!feof(fp)) {
      fgets(words, size, fp);
      counter++;
    }
    printf("%d",counter);
		//After getting the size of the file use rewind to go back to the file
    rewind(fp);
		//using a loop to ensure only a certain amount of time the loop is moving 
    while (i != counter + 1) {
			//store the string in the pointer
      sPtr[k] = malloc(size);
      fgets(sPtr[k], size, fp);
      k++;
      i++;
    }
		//close the file
    fclose(fp);
		//put all the strings allocated into one pointer
    for (int p = 0; p < i; p++) {
      strcat(sPtr2, sPtr[p]);
    }
  }
//return the string
  return sPtr2;
}
//This function is used to calculate the flesch index
int calculateFleschIndex(int syllables, int words, int sentences) {
	//calculate the index and round if needed using math.h
  double index;
  index = (206.835 - 84.6 * (syllables / words)) - (1.015 * (words / sentences));
  return round(index);
}
//This function is used to count the amount of words
int countWords(char * str) {
  int trueFalse = 0;
  int wc = 0;
	//Using a while loop to go through each character
  while ( * str) {
		//Checks if a space,newline or tab exists will go to if else if the character is not a space,newline and tab
    if ( * str == ' ' || * str == '\n' || * str == '\t'){
			 trueFalse = 0;
		}else if (trueFalse == 0) {
      trueFalse = 1;
			//add to words count
      ++wc;
    }
		//move the string forward
    ++str;
  }
	//return the word count
  return wc;
}
//This function is used to count the sentences
int countSentences(char * ptr) {
	
  int trueFalse = 0;
  int sc = 0;
//Go through the string
  while ( * ptr) {
		//While going through the loop is check for a ending puncation and will only accept one more than one puncuation 
    if ( * ptr == '.' || * ptr == ':' || * ptr == ';' || * ptr == '!' || * ptr == '?'){
			  trueFalse = 0;
		} else if (trueFalse == 0) {
      trueFalse = 1;
			//sentenceCount goes up
      ++sc;
    }
		//Move the string up a character
    ++ptr;
  }
	//subtract one
  sc--;
  return sc;
}
//This function is used to count the syllables
int counterSylables(char * ptr) {
  int Sylllables = 0;
  int count = 0;
	//Using a while loop to go through the program
  while ( * ptr) {
		//Check if a character has hit a end of a word
    if ( * ptr == ' ' || * ptr == '\n' || * ptr == '\t' || * ptr == '\0') {
			//resets the syllables variable
      Sylllables = 0;
    }
		//Check if the character are numbers consective number are worth one syllable
    if (isdigit( * ptr)) {
      count++;
      if (isdigit( * (ptr - 1))) {
        count--;
      }
    }
		//If a ptr is a vowel
    if (tolower( * ptr == 'a') || tolower( * ptr == 'e') || tolower( * ptr) == 'i' || tolower( * ptr) == 'o' || tolower( * ptr == 'u') || tolower( * ptr == 'y')) {
			//the count of syllables
      count++;
			//the amount of Sylllables for the word goes up
      Sylllables++;
			//If a char is a is a conective vowel from before
      if (tolower( * (ptr - 1) == 'a') || tolower( * (ptr - 1) == 'e') || tolower( * (ptr - 1) == 'i') || tolower( * (ptr - 1) == 'o') || tolower( * (ptr - 1) == 'u') || tolower( * (ptr - 1) == 'y')) {
        //consective vowels are worth only one syllables so we subtract the count the amount of syllable in the word
				count--;
        Sylllables--;
      }
			//this function is used to check if there is a letter e at the end
      if ((tolower( * ptr) == 'e') && ( * (ptr + 1) == ' ' || * (ptr - 1) == '\n' || * (ptr + 1) == '\0' || * (ptr + 1) == '\t')) {
       //The e is slient and therefore is not a syllable
			  count--;
        Sylllables--;
      }
			//if a word has no vowels but a word exists then the number of syllables will increase by 1
      if (Sylllables == 0) {
        count++;
      }
    }
		//moves the string forward
    ptr++;
  }
	//returns the total count
  return count;
}
//This will get the size of the file which is need to allocate a certain amount of memory
int getSize(char * fileName) {
	//read the file
  FILE * fp;
  int size;
  fp = fopen(fileName, "r");
  if (fp == NULL) {
    printf("file cannot be found");
		exit(0);
		//using fseek and ftell to find the size of the file
  } else {
    fseek(fp, 0l, SEEK_END);
    size = ftell(fp);
		//use rewind to reread the file again
    rewind(fp);
  }
	//retrun the size
  return size;
}
//This function is used to output everything done from the program
void outputFormattedFleschScores(int syllables, int words, int fleshIndex, int sentenceCount) {
  printf("Flesch Index = %d\n", fleshIndex);
  printf("Syllable Count = %d\n", syllables);
  printf("Word Count = %d\n", words);
  printf("Sentence Count = %d\n", sentenceCount);
}