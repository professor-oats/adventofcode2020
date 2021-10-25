#include <stdio.h>
#include <math.h>

// Vi behöver en array som kan storea värdena. Vore fett om detta kan läsas in från en txt.

// Fas två: Den här gången ska vi addera tre värden som sedan ska multipliceras ihop till en kod. För enkelhets skull gör jag en sortering mellan värdena för vilka som är under tusen

// Jag kommer att göra en relativt generell lösning för detta och låtsas som att jag inte helt styr värdena som plockas ur listan numbers.txt

// Global scope

    void findfactors();
    int numbers[199] = {0};
    int underthousand[199] = {0};

int main() {

    int productcode, fac1, fac2, fac3, k = 0, j = 0, i = 0;
    // int *p_fac1, *p_fac2;

    FILE *fp;    // Declaring fp as a file pointer

// This first part scans the numbers.txt file for values and adding to array

    if (fp = fopen("numbers.txt", "r")) {    // Let fp point to numbers.txt and open with read command
	while (fscanf(fp, "%d", &numbers[i]) != EOF && i < 200) {    // While using fscanf (fscanf true and value of numbers[i] != EOF, increment i
	// fscanf(what, type of, store where) 
	    ++i;
	    //printf("%d", i);
	}

    fclose(fp);    // Close fp when read is done
    }

    for (--i; i>= 0; --i) {    // Starting with --i to start in place [199]
	if (numbers[i] < 1000) {
	    underthousand[k] = numbers[i];
	    ++k;
	}
    }

/*    for (--k; k>=0; --k) {
	printf("underthousand[%d] = %d\n", k, underthousand[k]);
    } 
*/

    //printf("%d", k);    // k == 7 here, makes 7 underthousand elements from [0] to [6]


    findfactors(&fac1, &fac2, &fac3, i, j, k);    // Sending address to fac1 and fac2 to pointers in function findfactors
    productcode = fac1 * fac2 * fac3;
    printf("%d\n%d\n%d\n%d\n", fac1, fac2, fac3, productcode);


    return 0;
}

void findfactors(int *p_fac1, int *p_fac2, int *p_fac3, int i, int j, int k) {
    int testvalue, numsum1, numsumtotal;    // Check if this works as local without affecting returned values

    int k_orig, l = 0;

    i = 199;    // Max array index
    k_orig = k - 1;

    for (i; i>= 0; --i) {
	testvalue = numbers[i];    // Simple optimisation for later operation
	for (j = i - 1; j>= 0; j--) { 
	    numsum1 = testvalue + numbers[j]; 
	    if (numsum1 > 1020 && numsum1 < 2020) {
		for (k = k_orig; k>= 0; k--) {
		    numsumtotal = numsum1 + underthousand[k];
		    if (numsumtotal == 2020) {
			*p_fac1 = numbers[i];
			*p_fac2 = numbers[j];
			*p_fac3 = underthousand[k];
			return;
		    }
		}
	    }
	    else {    // With this numbers.txt using this case is a little unnecessary but it's good for code completion
		for(l = j - 1; l>=0; l--) {
		    numsumtotal = numsum1 + numbers[l];
		    if (numsumtotal == 2020) {
			*p_fac1 = numbers[i];
			*p_fac2 = numbers[j];
			*p_fac3 = numbers[k];
			return;
		    }
		}
	    }
	}
    }
}


