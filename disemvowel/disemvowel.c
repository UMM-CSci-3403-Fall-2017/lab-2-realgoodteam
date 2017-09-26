#include <stdlib.h>
#include <string.h>
#include "disemvowel.h"

char* disemvowel(char* str) {
  int i;
  int j;
  int found;
  int VowelCheck=0;
  int nonVowelCheck = 0;
  char* noVowel;
  int len = strlen(str);
  //char* vowels = calloc(11, sizeof(char));
  // This is a string of all vowels that is used to check
  char vowels[11] = {'a','A','e','E','i','I','o','O','u','U','\0'};
  //This first loop simply allocates memory for the 'no vowel' string
  for (i = 0; i < len; i++){
	   for(j = 0; j < 11; j++){
  		   if(vowels[j] == str[i]) {
			        VowelCheck++;
		          }
	   }
  }
  noVowel = (char*) calloc(len - VowelCheck + 1,sizeof(char));
  VowelCheck = 0;
  // Now that the memory is allocated for noVowel,
  // a very similar loop is run to actually add characters to it.
  for (i=0;i<len;i++){
	found = 0;
	for(j = 0; j < 11; j++){
  		if(vowels[j] == str[i]){
			found = 1;
			VowelCheck++;

		}
	}
  //The found variable is essentially a boolean
  // equivalent. If a vowel is not found,
  // then that character is added to noVowel.
	if(found == 0) {
		noVowel[nonVowelCheck] = str[i];
		nonVowelCheck++;
	}
 }
  return noVowel;
}
