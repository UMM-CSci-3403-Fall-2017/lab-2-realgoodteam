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
  char vowels[11] = {'a','A','e','E','i','I','o','O','u','U','\0'};
  for (i = 0; i < len; i++){
	for(j = 0; j < 11; j++){
  		if(vowels[j] == str[i]) {
			VowelCheck++;
		}
	}
  }
  noVowel = calloc(len - VowelCheck+1,sizeof(char));
  VowelCheck = 0;
  for (i=0;i<strlen(str) + VowelCheck;i++){
	found = 0;
	for(j = 0; j < 11; j++){
  		if(vowels[j] == str[i]){
			printf("found vowel\n");
			printf(noVowel);
			found = 1;
		}
	}
	if(found == 0) {
		noVowel[nonVowelCheck] = str[i];
		nonVowelCheck++;
	}
 }
  return noVowel;
}
