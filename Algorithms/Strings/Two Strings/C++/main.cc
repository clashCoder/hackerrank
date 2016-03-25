#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
 * function checks to see if there is a character in common between the two strings
 * passed in. Returns true on 1st shared character when both are sorted. If they share
 * no common character then the function returns false.
 */
bool shareChar(string a, string b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    size_t aPos = 0;
    size_t bPos = 0;
    
    size_t aSize = a.size();
    size_t bSize = b.size();
    
    while ( (aPos < aSize) && (bPos < bSize) ) {
        if (a[aPos] == b[bPos]) {
            return true;
        }
        else if (a[aPos] < b[bPos]) {
            aPos++;
        }
        else {
            bPos++;
        }
    }
    return false;
}

/*  Input:
 *      T -> number of testcases
 *   the following input will be given T times
 *      A -> string
 *      B -> string
 *  Constraint:
 *      All the string contain lower case letters
 *      1 <= T <= 10
 *      1 <= |A|, |B| <= 10^5
 *  Output:
 *      output whether A and B share a common substring
 */

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    
    cin.ignore(1000, '\n');
    
    for (int i = 0; i < T; i++) {
        string a;
        string b;
        
        getline(cin, a);
        getline(cin, b);
        
		// to find a substring that appears in both A and B...simply
		// find a character that they have in common.
        bool commonChar = shareChar(a, b);
        
        if (commonChar) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
    
}
