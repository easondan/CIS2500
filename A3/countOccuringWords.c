#include "headerA3.h"
#include "functionA3.h"

int countOccuringWords(char tweet[], char stopWord[])
{
    int i;
    int n;
    int l;
    int j=0;
    int k=0;
    int matchWord=0;
    int counter=0;
    int arrays[1000];
    //Using a while loop this goes though and checks if there are spaces which will account for a word in the string
    for(i=0;tweet[i];i++)
    {
      //if array is equal to space the position of the space is saved and k is used to show how many space there are
    	if(tweet[i]==' ')
    	{
    		arrays[k++]=i;
		}
	}
	arrays[k++]=i;
  //using k as the end
	for(i=0;i<k;i++)
	{
    //the loop iterates through the white spaces of the string  
    //and initialize n=index for the whitespace.
		n=arrays[i]-j;
    // if the length of the word is equal then you want to compare this with the stopwords and the string
    // if they match then increase the value 
		if(strlen(stopWord)==n)
		{
			counter=0;
			for(l=0;stopWord[l];l++)
			{
				if(stopWord[l]==tweet[l+j])
				{
					counter++;
				}
			}
      //this check if the count is the same length as the stop word or search word 
			if(strlen(stopWord)==counter)
      //if they match they the values add up 
		    {
				matchWord++;
				 
		    }
		}
  //reillalize j for the next word
		j=arrays[i]+1;
	}
	 
    return matchWord;
 
	
}
