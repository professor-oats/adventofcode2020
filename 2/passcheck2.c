#include <stdio.h>

// First plan was to make a program to read line by line and store strings of letters in arrays.

// Changed the idea to an array-minimal approach only utilising fgetc and putting it in loops of different segments of each line.

// A straight and somewhat minimalistic approach

// Part 2:

// Now we will have the min and maxvalue as position determinators for the letters in the password strings. According to Tobbogan policies the positions must contain 'only one' exclusively occurance of the given letter on the places in the string. So 0 and 2 (1 + 1) occurances end up false. I think of XOR.

// Caveats of this program is that it is very dependent on the \n as a delimiter for when reading the next string. That means if HAS to read every character in the string to find the delimiter.

// Use of other methods of reading strings from file could be beneficial but for such low data as this case current method works okay.


int main(void) {
    int positionfp = 0, i = 0;    // positionfp be used as marker for position of fgetc(fp)
    int passcount = 0, minvaluearr[2] = {0}, maxvaluearr[2] = {0};
    char xor_result = 0, minpostrue = 0, maxpostrue = 0, dec = 0, lettcount = 0, tenbaseinc = 1, notminvalue = 0, notmaxvalue = 1, minvalue = 0, maxvalue = 0, letter = 0, c = 0;

    FILE *fp;    // Declaring fp as file pointer

    fp = fopen("passwords.txt", "r");
    if(fp == NULL) {
        perror("Error in opening file");
        return 1;
    } 


    while(!feof(fp)) {

        while((c = fgetc(fp)) != '-') {
    
	    if (feof(fp)) {    // Break if file pointer stores end of file
	        goto break_out;
	    }
    
	    dec = c - '0';
	    minvaluearr[i] = dec;
	    i++;

        } 

        for(--i; i>=0; i--) {    // In this case scenario this operation is overkill but it's also the general solution
	    minvalue += minvaluearr[i] * tenbaseinc;
	    tenbaseinc *= 10;
        }

	// Reset

        tenbaseinc = 1; 
	i = 0;
    
        while((c = fgetc(fp)) != ' ') {
    
	    dec = c - '0';
	    maxvaluearr[i] = dec;
	    i++;
        } 	
    
        for(--i; i>=0; i--) {
	    maxvalue += maxvaluearr[i] * tenbaseinc;
	    tenbaseinc *= 10;
        }


	// Reset

        tenbaseinc = 1;
	i = 0;
    
        while((c = fgetc(fp)) != ':') {
	    letter = c;
        }    	
    
        while((c = fgetc(fp)) != '\n') { 

	    if (lettcount == minvalue) {
		if (c == letter) {
		    minpostrue = 1;
		    printf("Minposletter = %c\n", c);
		}
	    }
	    if (lettcount == maxvalue) {
		if (c == letter) {
		    maxpostrue = 1;
		    printf("Maxposletter = %c\n", c);
		}
	    }
	    lettcount++;    // Incrementing after first iterations since the first c is ' ' acting as index 0 in this case
        }

    // Calculating result and summarising the amount of valid passwords

    xor_result = minpostrue ^ maxpostrue;

    if (xor_result == 1) {
        passcount++;
    }	

    // Zeroing important values

    lettcount = 0;
    maxvalue = 0;
    minvalue = 0;
    minpostrue = 0;
    maxpostrue = 0;
    xor_result = 0;

    }

    break_out:
    printf("\nThe amount of correct passwords are: %d\n", passcount);

    fclose(fp);
    return 0;

}
