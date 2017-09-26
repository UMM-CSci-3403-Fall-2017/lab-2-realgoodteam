#include <gtest/gtest.h>

#include "disemvowel.h"

//The following tests were changed
// simply to free up deReturn after being used.
TEST(Disemvowel, HandleEmptyString) {
  char* deReturn = disemvowel((char*) "");
  ASSERT_STREQ("", deReturn);
  free(deReturn);
}

TEST(Disemvowel, HandleNoVowels) {
  char* deReturn = disemvowel((char*) "pqrst");
  ASSERT_STREQ("pqrst", deReturn);
  free(deReturn);
}

TEST(Disemvowel, HandleOnlyVowels) {
  char* deReturn = disemvowel((char*) "aeiouAEIOUOIEAuoiea");
  ASSERT_STREQ("", deReturn);
  free(deReturn);
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  char* deReturn = disemvowel((char*) "Morris, Minnesota");
  ASSERT_STREQ("Mrrs, Mnnst", deReturn);
  free(deReturn);
}

TEST(Disemvowel, HandlePunctuation) {
  char* deReturn = disemvowel((char*) "An (Unexplained) Elephant!");
  ASSERT_STREQ("n (nxplnd) lphnt!",
		      deReturn);
  free(deReturn);
}

TEST(Disemvowel, HandleLongString) {
  char* str;
  int size;
  int i;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';

  char* deReturn = disemvowel(str);
  ASSERT_STREQ("xyz", deReturn);
  free(deReturn);
  free(str);
  // free up deReturn and str after they have been utilized
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
