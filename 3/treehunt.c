#include <stdio.h>

// Will make a program that scans through trees.txt and putting the symbols/trees in arrays and I will make sure to have an array of array to make it indexed.

// The symbols themselves form av slope which is repeated when the last character of each string finishes, it starts again with the first character of the string.

// In first assignment the slope has the pattern 3 right, 1 down, whereat 1 will be the indeces of the array themselves. If we will traverse more downwards one will have to make sure to check if trees are hit at every index following the specific slope.

// This could perhaps be used somewhat in object oriented but will continue in C for now.

// Since the amount of lines (height of slope) is known to be 323 I can easily traverse with the fp with i value from 0 up to 324 to make sure scanf ends correctly without overflowing.

// The string length in the trees.txt is maximum 31 so I need an array of at least 32 elements. Indexed 31 should suffice.

int main() {

    int counttrees = 0, x = 0, y = 0, i = 0;
    char trees[324][31];
    char current;

    FILE *fp;    // Declaring fp as file pointer


    fp = fopen("trees.txt", "r");     // Let fp point to trees.txt and open with read command
    if (fp == NULL) {
	perror("Error in opening file");
	return 1;
    } 

    while(fscanf(fp, "%s", &trees[i]) != EOF && i < 324) {
	// fgets(what, type of, store where)
	    ++i;
    }

    fclose(fp);

    //putchar(trees[4][30]); 

    //x = 3;    // Stepped 3 from index 0

    while(y < 324) {

	x += 3;
	y++;

	if (x > 30) {
	    x-= 31;    // Substracting amount of elements to reset/repeat pattern
	    //printf("y = %d, x = %d\n", y, x);
	}

	current = trees[y][x];
	if (current == '#') {
	    counttrees++;
	}	

    }

    printf("The amount of trees hit are: %d\n", counttrees);

    return 0;
}
