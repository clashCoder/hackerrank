#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


/*  Input:
 *      N -> length of string to be encrypted
 *      S -> string to be encrypted
 *      K -> encryption key (number of letters to rotate)
 *  Constraints:
 *      1 <= N <= 100
 *      0 <= K <= 100
 *      S is a valid ASCII string (no spaces), only letters [a-zA-Z]
 * Function modifies string passed in by converting the string
 * to a Ceasar Cipher with a given key. 
 */
void ceasarCipher(string &s, int stringSize, int key) {
    
    const int UPPER_CASE_LOW_VALUE = 65;
    const int UPPER_CASE_HIGH_VALUE = 90;
    const int LOWER_CASE_LOW_VALUE = 97;
    const int LOWER_CASE_HIGH_VALUE = 122;
    

	// key values greater than 26 simply corresponding to
	// a digit between 1 and 26 
    int k = key % 26;
    
    if ( (k == 0) && (key != 0) ) {
        k = 26;
    } 
    
    for (int i = 0; i < stringSize; i++) {
        
		//modify character only if it is part of the alphabet
        if (isalpha(s[i])) {
            int charNum = s[i];
            
			// case to handle upper case characters
            if ( (charNum >= UPPER_CASE_LOW_VALUE) && (charNum <= UPPER_CASE_HIGH_VALUE) ) {
                charNum += k;
                
				// handle overflow case
                if (charNum > UPPER_CASE_HIGH_VALUE) {
                    charNum = charNum % UPPER_CASE_HIGH_VALUE;
                    charNum += (UPPER_CASE_LOW_VALUE - 1);
                }
            }
            
			// case to handle lower case characters
            if ( (charNum >= LOWER_CASE_LOW_VALUE) && (charNum <= LOWER_CASE_HIGH_VALUE) ) {
                charNum += k;
                
				// handle overflow case
                if (charNum > 122) {
                    charNum = charNum % LOWER_CASE_HIGH_VALUE;
                    charNum += (LOWER_CASE_LOW_VALUE - 1);
                }
            }
            s[i] = charNum;
        }
    }
}

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;
    
    ceasarCipher(s,n,k);
    cout << s;
    
    return 0;
}
