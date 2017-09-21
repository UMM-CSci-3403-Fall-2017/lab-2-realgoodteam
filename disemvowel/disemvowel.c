#include <stdlib.h>
#include <string.h>
#include "disemvowel.h"

char* disemvowel(char* str) {
  int i;
  int nonVowelCheck=0;
  char* noVowel;
  int len = strlen(str);
  //char* vowels = calloc(11, sizeof(char));
  char vowels[11] = {'a','A','e','E','i','I','o','O','u','U','\0'};
  char* strPointer;  
  for (i = 0; i < len; i++){
	strPointer = str+i;
  	if(strstr(vowels,strPointer)==NULL){
		nonVowelCheck++;	
	}
  }
  noVowel = calloc(nonVowelCheck+1,sizeof(char));
  nonVowelCheck = 0;
  for (i=0;i<strlen(str);i++){
	strPointer = str+i;
  	if(strstr(vowels,strPointer)==NULL){
		nonVowelCheck++;
		noVowel[nonVowelCheck] = str[i];
	}

  }
  return noVowel;
}
