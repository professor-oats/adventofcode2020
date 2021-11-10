#include <stdio.h>

// Make a program that scans a file by each line and check the different symbols and having a certain type as a break before having a new operation on following value.

// Current plan is to read it with fgetc() and do different operations depending on what is stored in c.

// One could use an array of array and store strings in but I will make the program do sequential tests using fgetc() and only storing important values in variables

int main(void) {
    int positionfp = 0, i = 0;    // positionfp be used as marker for position of fgetc(fp)
    int passcount = 0, minvaluearr[2] = {0}, maxvaluearr[2] = {0};
    char dec = 0, lettcount = 0, tenbaseinc = 1, notminvalue = 0, notmaxvalue = 1, minvalue = 0, maxvalue = 0, letter = 0, c = 0;

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
    
    
        while((c= fgetc(fp)) != '\n') { 

	    if (c == letter) {
	        lettcount++;
	    }
    
        }

    // Summarising the amount of valid passwords

    if (lettcount >= minvalue && lettcount <= maxvalue) {
        passcount++;
    }	

    // Zeroing important values

    lettcount = 0;
    maxvalue = 0;
    minvalue = 0;

    }

    break_out:
    printf("\nThe amount of correct passwords are: %d", passcount);

    fclose(fp);
    return 0;

}
