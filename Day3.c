#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
  FILE * pFile;
  pFile = fopen("rucksack.txt", "r");

  if (pFile == NULL) {
    puts("Error opening file");
  }

  int sumPriority=0;

  
  char rucksack[100];
  char* group[3];
  int count, count3=0, i, j, k;
  while (fgets(rucksack, 300, pFile) != NULL) {
    count++;

    if (count%3 == 1) {group[0] = rucksack;}
    //printf("%d %s", count, rucksack);}
    else if (count%3 == 2) {group[1] = rucksack;}
      //printf("%d %s", count, rucksack);}
    
    else if (count%3 == 0) {
      group[2] = rucksack;
      //printf("%d %s", count, rucksack);
      count3++;
      //printf("%d ", count3);
      for (i=0; i<strlen(group[0]); i++) {
	printf("%d out of %lu ", i, strlen(group[0]));
	for (j=0; j<strlen(group[1]); j++) {
	  printf("j: %d /", j);
	  for (k=0; k<strlen(group[2]); k++) {
	    printf("k: %d /", k);
	    if ((group[0][i] == group[1][j]) && group[0][i] == group[2][k] && group[1][j] == group[2][k]) {
	      
	      printf("%d %d %d: %c %c %c\n", i, j, k, group[0][i], group[1][j], group[2][k]);
	      if (islower(group[0][i])) {
		//printf("%c %d\n", group[0][i], (int)group[0][i] - 96);
		sumPriority += ((int)group[0][i])-96;
	      }
	      else if (isupper(group[0][i])) {
		//printf("%c %d\n", group[0][i], (int)group[0][i] - 38);
		sumPriority += ((int)group[0][i])-38;
	      }
	      //printf("%d ", sumPriority);
	      i=strlen(group[0]);
	      j=strlen(group[1]);
	      k=strlen(group[2]);
	    }
	  }
	}
      }
    }
  }

  printf("%d\n", count);
  printf("%d\n", sumPriority);
   
    /* part 1
    int length = strlen(rucksack);
    int i, j;
    for (i=0; i<length/2; i++) {
      
      for (j=length/2; j<length; j++) {
	if (rucksack[i] == rucksack[j]) {
	  printf("%c ", rucksack[i]);
	 
	  if (islower(rucksack[i])) {
	    printf("lower %c\n", rucksack[i]);
	    //printf("%c %d\n", rucksack[i], (int)rucksack[i] - 96);
	    sumPriority += ((int)rucksack[i] - 96);
	    //i=length/2;
	  }
	  else if (isupper(rucksack[i])) {
	    printf("upper %c\n", rucksack[i]);
	    sumPriority += ((int)rucksack[i] - 38);
	    //i=length/2;
	  }
	  i = length/2;
	  j = length;

	}
      }
    }
    puts("");
  }
  printf("%d\n", sumPriority);*/
  return 0;
}
