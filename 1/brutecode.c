#include <stdio.h>
#include <math.h>

// Vi behöver en array som kan storea värdena. Vore fett om detta kan läsas in från en txt.

// Global scope

    void findfactors();
    int numbers[199] = {0};


// This first part scans the numbers.txt file for values and adding to array
int main() {

    int productcode, fac1, fac2, j = 0, i = 0;
    // int *p_fac1, *p_fac2;

    FILE *fp;    // Declaring fp as a file pointer

    if (fp = fopen("numbers.txt", "r")) {    // Let fp point to numbers.txt and open with read command
	while (fscanf(fp, "%d", &numbers[i]) != EOF && i < 200) {    // While using fscanf (fscanf true and value of numbers[i] != EOF, increment i
	// fscanf(what, type of, store where) 
	    ++i;
	    //printf("%d", i);
	}

    fclose(fp);    // Close fp when read is done
    }

    //printf("%d",i);

/*    for (--i; i>= 0; --i) {    // Starting with --i to print in place [199]
	printf("numbers[%d] = %d\n", i, numbers[i]);
    }
*/

    findfactors(&fac1, &fac2, i, j);    // Sending address to fac1 and fac2 to pointers in function findfactors
    productcode = fac1 * fac2;
    printf("%d\n%d\n%d\n", fac1, fac2, productcode);

    return 0;
}

void findfactors(int *p_fac1, int *p_fac2, int i, int j){
    int testvalue, numsum;    // Check if this works as local without affecting returned values

    for (--i; i>= 0; --i) {
	testvalue = numbers[i];    // Simple optimisation for later operation
	for (j = i - 1; j>= 0; j--) { 
	    numsum = testvalue + numbers[j];    // Having numsum as global just because of good measures
	    if (numsum == 2020) {
		*p_fac1 = numbers[i];    // Storing with pointers to enable change of value for fac1 and fac2
		*p_fac2 = numbers[j];
		return;
	    }
	}
    }
}


