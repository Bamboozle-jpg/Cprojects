#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define RANDSTRUC rand()%6
#define NUMLYMERICS 1

int main() {

  //Limerick Organization
  ENUM sentenceStructure{VERB, NOUN, ADJECTIVE}
  sentenceStructure req;

  //Arrays to hold rhymes
  //3 Nouns, 2 Adjectives, 2 Verbs per (in that order)
  char* rhyme1[] = {"gross bug", "warm rug", "full jug", "kerplug", "kerplug" "to glug", "to mug"};
  char* rhyme2[] = {"green bean", "latrine", "long spleen", "light green", "too mean", "to preen", "to clean"}

  //Arrays with limerick templates
  //6 syllables
  char* lim1[] = {"There once was a little ", "A good friend of mine was ", "I once had a hefty pet ", "Hey man, your shoe is quite ", "At the party he wants ", "One time someone wanted "};
  //7 syllables
  char* lim2[] = {"They were looking a little ", "I did not like that they were ", "They were walking next to a ", "Careening at them was a ", "They seemed as though they wanted ", "When they then decided not "};
  //3 syllables
  char* lim3[] = {"Up came a ", "In walked a ", "They then went ", "They started ", "They looked quite ", "They were quite "};
  //4 syllables
  char* lim4[] = {"They were very ", "They seemed slightly ", "They were going ", "They then began ", "Down jumped a big ", "Around walked the "};
  //6 syllables
  char* lim5[] = {"And they all went over ", "And then they all started ", "They ended up looking  ", "In the end they were all ", "They all turned into a ", "They all were smooshed by a "};

  //matching array with what sentence structure needs to be added
  int lim1struct[] = {NOUN, ADJECTIVE, NOUN, ADJECTIVE, VERB, VERB};
  int lim2struct[] = {ADJECTIVE, ADJECTIVE, NOUN, NOUN, VERB, VERB};
  int lim3struct[] = {NOUN, NOUN, VERB, VERB, ADJECTIVE, ADJECTIVE};
  int lim4struct[] = {ADJECTIVE, ADJECTIVE, VERB, VERB, NOUN, NOUN};
  int lim5struct[] = {VERB, VERB, ADJECTIVE, ADJECTIVE, NOUN, NOUN};

  //Seeds rand with time
  srand(time(NULL));

  //Prints out Limerick
  for (int i = NUMLYMERICS) {
    //Lym1 prep
    int structure = RANDSTRUC;
    req = lim1struct[structure];
    if (req = VERB) {
      
    }
    printf(lim1[structure]
  }

  return 0;
}
