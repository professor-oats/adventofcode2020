#include <stdio.h>
#include <string.h>

// Make a program that checks for keywords to see what passports are
// valid or not. 

// Obligatory one occurence of: ecl, pid, eyr, hcl, byr, iyr, hgt.

// Optional: cid - Let program also check for cid but when validating account use AND function to put the obligatory ones together.

// One reasonal approach is to take the data and load into array. After that check for keywords by looking for ':' and take the three letters before then and check for the double \n to get new person.

// When data is loaded I will step through the full array one time and do a sort on each string on keywords and strcmp with an obligatory string.

// One drawback of working with strings is that the common string commands take a lot of resources.

void sortstring();

int main() {

    int i = 0, j = 0, k = 0, li = 0, il, _21matches = 0, _24matches, decrement = 0, amountc = 0, amounth = 0, currentkeylength = 0, validpasses = 0, amountkeyletters, test;
    char personalinf[1056][79]; 
    char keywords[25], oblstring[21] = "bccdeeghhiillprrrtyyy", allstring[24] = "bcccddeeghhiiillprrrtyyy";    // Maximum amount of letters are 24, filling obl for strcmp sake
    char c = 0, setnewline = 0;

    FILE *fp;    // Declaring fp as file pointer

    fp = fopen("personalinf.txt", "r");     // Let fp point to trees.txt and open with read command
    if (fp == NULL) {
	perror("Error in opening file");
	return 1;
    } 

    /*
    // Dirty man's string zero, resource hogging
    for (i = 0; i < 24; i++) {
        keywords[i] = '0';
    }
*/

    for (i = 0; (c = personalinf[j][i] = fgetc(fp)) != EOF && i <= 79 && j <= 1056; i++) {
	if (c == '\n') {
	    j++;
	    i = -1;    // This is -1
	}
    }

    j = 0;

    fclose(fp);


    //putchar(personalinf[0][19]);
    printf("%s", keywords);

    amountkeyletters = 3;    // Opting for more general solution
	// The thing needing tested is the first character in each keyword

    for(i=0; ((c = personalinf[j][i])) != EOF; i++) {
    // Since double '\n' is a delimiter one can do a while to loop as long as c != '\n' if one does not want to keep unsetting variable setnewline. Cleanest code can often come from not putting delimiter inside loops.
    // Did try alt actually and so far this is a fine solution.
    // Only caveat here is that the double '\n' is the delimiter and that makes it so the last person, when EOF is reached, is not tested and included.
    // Solution: Add extra delimiter to the data or change the for loop to run without delimiter.

	putchar(c);
	if (c == ':') {
	    for(il = amountkeyletters; il > 0; il--, li++) {
		keywords[li] = personalinf[j][i-il];
		printf("[%d][%d]", j, (i - il));
		//putchar(keywords[li]);
		//putchar('\n');
		currentkeylength++;
	    }
	    printf("currentkeylength = %d\n", currentkeylength); 
	}
	if (c == '\n') {
	    if (setnewline == 1) { 
		printf("Tjopahejpi");
		keywords[li] = '\0';    // Keyword string ends
		printf("\n%s", keywords);
		sortstring(keywords, li);
		li = 0;
		printf("\n%s\n", keywords);

		if (currentkeylength == 21 ) {
		// Good dirty solution in this case, very specific 
		_21matches++;

		    printf("\n21match\n");
		    for(k = 0; k < currentkeylength; k++) {
			if (keywords[k] == 'c') {
			    amountc++;
			}
			else if (keywords[k] == 'h') {
			    amounth++;
			}
		    }
		    if(amountc > 2) {
			decrement++;
		    }
		    else if(amountc >= 1 && amounth != 2){
			decrement++;
		    }
		}
		else if (currentkeylength == 24) {
		    _24matches++;
		    printf("\n24match\n");
		}
		printf("\nDecrement = %d\n", decrement);
		printf("\n21matches = %d\n", _21matches);
		printf("\n24matches = %d\n", _24matches);
		//printf("\n J1 = %d\n", j);
		currentkeylength = 0;
		amountc = 0;
		amounth = 0;
	    }
	    setnewline = 1;
	    j++;
	    //printf("\n J2 = %d\n", j);

	    // Resetting
	    i = -1;
	}
	else {
	    setnewline = 0;    // Quirky. For other assignments change this
	}
    }

    validpasses = _21matches + _24matches - decrement;
    printf("\nTotal amount of valid passes are: %d\n", validpasses);
    printf("%s", oblstring);

    return 0;
}

void sortstring(char keywords[], int li) {

    char temp;
    int i;

    for(--li; li>0; li--) { 
	for(i=li-1; i>=0; i--) {
	    if(keywords[li] < keywords[i]) {
		temp = keywords[li];
		keywords[li] = keywords[i];
		keywords[i] = temp;
	    }
	}
    }
		
    return;
}
