#include<stdio.h>
#include<string.h>
int main() {

  int counter1[] = {0, 0, 0, 0};
  int counter2[] = {0, 0, 0, 0};

  char s1[] = "dbb cccccaacb cdbababdcdcdab dcdad";
  char s2[] = "bbbcc bdddccccad cdbbaaacaccdabdd";

  for(int i = 0; i < strlen(s1); i++) {
    char letter = s1[i];
    switch(letter) {
      case 'a':
        counter1[0]++;
        break;
      case 'b':
        counter1[1]++;
        break;
      case 'c':
        counter1[2]++;
        break;
      case 'd':
        counter1[3]++;
        break;
      default:
        // Ignore
        break;
    }
  }

  for(int i = 0; i < strlen(s2); i++) {
    char letter = s2[i];
    switch(letter) {
      case 'a':
        counter2[0]++;
        break;
      case 'b':
        counter2[1]++;
        break;
      case 'c':
        counter2[2]++;
        break;
      case 'd':
        counter2[3]++;
        break;
      default:
        // Ignore
        break;
    }
  }

  int flag = 0;
  for(int i = 0; i < sizeof(counter1) / sizeof(int); i++) {
    if(counter1[i] != counter2[i]) {
      flag = 1;
      break;
    }
  }

  if (flag == 0) {
    printf("Anagram!");
  } else {
    printf("Not Anagram!");
  }

  return 0;
}