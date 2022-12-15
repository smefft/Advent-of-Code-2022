//Day 8 Advent Calendar 2022
//checks outside in and inside out of a grid of numbers for the nearest number that is the same or greater 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkLeftRight(int, int, int, int[]);
int scenicScore(int, int, int, int, int[]);

int main() {
  int numRows=0, numCols=0;
  char temp[102]; //holds numbers as characters
  int trees[300][100];

  //populate 2D array of trees from file
  FILE * pD8;
  pD8 = fopen("d8.txt", "r");

  if (pD8 == NULL) { //check successful open
    puts("Error opening file");
  }

  int i;
  while (fgets(temp, 102, pD8) != NULL) {
    for (i=0; i<strlen(temp); i++) {
      //put characters as int into row of "trees"
      if (temp[i] != '\n') {
	trees[numRows][i] = (int)temp[i]-'0';
      }
    }
    numRows++;
    numCols = strlen(temp);
  }
  fclose(pD8);

  //printf("Number of rows: %d\n", numRows);
  //printf("Number of columns: %d\n", numCols);
  
  int row, col, column[numRows];

  int maxScenicScore = 0;
  int visibleTrees = 0;
  for (row=0; row<numRows; row++) {
    for (col=0; col<numCols; col++) {

      //construct column
      for (i=0; i<numRows; i++) {
	column[i] = trees[i][col];
      }

      //calculate scenic score (inside out)  //original, index, start, end, column
      int left = scenicScore(trees[row][col], col, -1, col, trees[row]); //starts at 1 to the left and ends at index 0 or where number is same or bigger
      int right = scenicScore(trees[row][col], col, 1, numCols-1-col, trees[row]); //starts at 1 to the right and ends at the end of the row
      int up = scenicScore(trees[row][col], row, -1, row, column);
      int down = scenicScore(trees[row][col], row, 1, numRows-1-row, column); //starts 1 down (right) and ends at bottom row

      int scenicScore = left * right * up * down;
      if (scenicScore>maxScenicScore) {
	maxScenicScore = scenicScore;
	}

      //calculate and print how many trees visible from outside in
      //first and last row
      if (row==0) {
	printf("-");
	visibleTrees++;
      }
      else if (row==(numRows-1)) {
	printf("-");
	visibleTrees++;
      }

      //left and right column
      else if (col == 0 && row != 0) {
	printf("|%d", trees[row][col]);
	visibleTrees++;
      }
      else if (col == (numCols-1) && row != (numRows-1)) {
	printf("%d|", trees[row][col]);
	visibleTrees++;
      }

      //middle
      else {
	//check left
	if (checkLeftRight(trees[row][col], 0, col, trees[row]) == 0) {
	  printf("%d", trees[row][col]);
	  visibleTrees++;
	}
	//check right
	else if (checkLeftRight(trees[row][col], col+1, numCols, trees[row]) == 0) {
	  printf("%d", trees[row][col]);
	  visibleTrees++;
	}

	//check up 
	else if (checkLeftRight(trees[row][col], 0, row, column) == 0) {
	  printf("%d", trees[row][col]);
	  visibleTrees++;
	}
	//check down
	else if (checkLeftRight(trees[row][col], row+1, numRows, column) == 0) {
	  printf("%d", trees[row][col]);
	  visibleTrees++;
	}
	
	else {
	  printf(" ");
	}
      }
    }
    puts("");
  }
  
  printf("\nVisible trees: %d\n", visibleTrees);
  printf("Max scenic score: %d\n", maxScenicScore); //2661040 too high
  return 0;
}

//calculate how many "trees" can be seen from the edge (from outside in)
int checkLeftRight(int original, int start, int end, int row[]) {
  int numBigger=0;
  int i, compare;
  for (i=start; i<end; i++) {
    compare = row[i];
    if (compare >= original) {
      //printf("compare: %d, original: %d\n", compare, original);
      return 1;
    }
  }
  return numBigger;
}

//calculate how many "trees" can be seen from each "tree" in the grid (from inside out)
int scenicScore(int original, int index, int start, int end, int row[]) { //make start neg to move left or up
  int count = 0;
  int i, compare;
  
  for (i=1; i<=end; i++) {
    
    if (start<0) { 
      compare = row[index-i]; //move left or up the column
    }
    else {
      compare = row[index+i]; //move right or down the column
    }
    
    if (compare < original) { //keep going 
      count++;
    }
    else { //found number >= to original, return count
      count++;
      return count;
      
    }
  }
  return count;
}
