#include "fleschIndex.h"
int main(int argc,char *argv[]) {
	//Allocated space for the strings
	char *ptr= malloc(sizeof(char)*getSize(argv[1]));
	//read the file and store in the pointer
	ptr = readFile(argv[1]);
	 printf("%s",ptr);
	//Use this variable to count the syllables
	int syllables=counterSylables(ptr);
	//use this to count the countWords
	int wordCount=countWords(ptr);
	//use this to count the sentenceCount
	int sentenceCount = countSentences(ptr);
	//use this to calculate the index
	int fleschIndex = calculateFleschIndex(syllables, wordCount, sentenceCount);
	//output everything
	outputFormattedFleschScores(syllables, wordCount, fleschIndex, sentenceCount);
	
  return 0;
}

