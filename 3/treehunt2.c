#include <stdio.h>

// Will make a program that scans through trees.txt and putting the symbols/trees in arrays and I will make sure to have an array of array to make it indexed.

// The symbols themselves form av slope which is repeated when the last character of each string finishes, it starts again with the first character of the string.

// In first assignment the slope has the pattern 3 right, 1 down, whereat 1 will be the indeces of the array themselves. If we will traverse more downwards one will have to make sure to check if trees are hit at every index following the specific slope.

// This could perhaps be used somewhat in object oriented but will continue in C for now.

// Since the amount of lines (height of slope) is known to be 323 I can easily traverse with the fp with i value from 0 up to 324 to make sure scanf ends correctly without overflowing.

// The string length in the trees.txt is maximum 31 so I need an array of at least 32 elements. Indexed 31 should suffice.

// Part 2: We will now have different ways of going down the slope and we will count all trees we hit and at the end we multiply the sum of trees hit each way.

// The approach will be with straight forward changes. The only other thing to take in accordance is if we hit extra trees going down the slope with an y value greater than 1.


void getslope();

int main() {

    int treesum = 0, treeprod = 1, amount_slopes, amount_slopes_left, px, py, xstep, ystep, counttrees = 0, x = 0, y = 0, i = 0;
    int *storecounttrees;
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
   
    printf("Welcome to your personal slope program!\nHow many slopes do you want to go today?\n");
    scanf("%d", &amount_slopes);

    if (amount_slopes == 0) {
	printf("Come back again!\n");
	return 0;
    }

    storecounttrees = calloc ( amount_slopes * sizeof(int));
    amount_slopes_left = amount_slopes;

    while(amount_slopes_left > 0){
	getslope(&xstep, &ystep);

        //printf("xstep = %d, ystep = %d\n", xstep, ystep);

	while(y < 324) {

            x += xstep;
            y += ystep;

            if (x > 30) {
                x-= 31;    // Substracting amount of elements to reset/repeat pattern
            }

            current = trees[y][x];
            if (current == '#') {
                counttrees++;
                py = y + 1;
                px = x + 1;
                printf("y = %d, x = %d\n", py, px);
	    }	

	}

        printf("The amount of trees hit in this slope are: %d\n", counttrees);
	
	storecounttrees[amount_slopes_left] = counttrees;        
        amount_slopes_left--;
	counttrees = 0;
	x = y = 0;

	printf("Prepare for your next slope!\n");
    }
    
    for (; amount_slopes > 0; amount_slopes--) {

	treesum += storecounttrees[amount_slopes];
	treeprod *= storecounttrees[amount_slopes];
    }


    printf("Congratulations, you made all slopes. Total of trees hit are: %d\n", treesum);

    printf("The product of all trees hit are: %d\n", treeprod);

    free(storecounttrees);
    return 0;
}

void getslope(int *xstep, int *ystep) {    // Getter function
    printf("Enter how many steps to the right:\n");
    scanf("%d", xstep);
    printf("Enter how many steps down:\n");
    scanf("%d", ystep);

    return;
}
