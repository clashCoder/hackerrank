#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*  Input: 
 *      T -> number of testcases
 *   the following input is given T times:
 *      A -> integer
 *      B -> integer
 *  Constraints:
 *      1 <= T <= 100
 *      1 <= A <= B <= 10^9
 *  Output:
 *      the number of square integers between A (inclusive) and B (inclusive)
 */

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        double A, B;
        long long int sqrtIntCount = 0;
        cin >> A >> B;
        
        double nextSqrtInt = 1;
        double position = 2;
        
		// every square integer can be calculated via following series:
        // 1 + 3 + 5 + 7 + 9 + ... + 2n - 1
		// so simply count all the values within the series that are
		// within the range [A, B] (including endpoints)
        while (nextSqrtInt < A) {
            nextSqrtInt += ((2*position) - 1);
            position++;
        }
        
        while (nextSqrtInt <= B) {
            sqrtIntCount++;
            nextSqrtInt += ((2*position) - 1);
            position++;
        }
        
        cout << sqrtIntCount << endl;

		//slower implementation
        /*for (long long int i = A; i < (B + 1); i++) {
            double num = i;
            double numSqrt = sqrt(num);
            double numFloor = floor(numSqrt);
            
            if (numSqrt == numFloor) {
                sqrtIntCount++;
            }    
        }*/
        //cout << sqrtIntCount << endl;
    }
    return 0;
}
