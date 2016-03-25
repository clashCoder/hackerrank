#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*  Input:
 *      T -> number of testcases
 *    the following inputs are given T times:
 *      N -> integer representing total number of 'money' at hand
 *      C -> cost of each piece of chocolate/candy
 *      M -> number of wrappers needed to exchange for an additional piece of chocolate/candy
 *  Constraint:
 *      1 <= T <= 1000
 *      2 <= N <= 10^5
 *      1 <= C <= N
 *      2 <= M <= N
 *  Output:
 *      max number of candies one can get with N amount of money at C cost with wrapper to candy exchange
 *          rate of M:1
 */

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int c;
        int m;
        cin >> n >> c >> m;
        
		// initial number of candies that can be bought with $N  if each cost $C
        int numOfCandies = n / c;

		// the wrappers that can be exchanged for extra pieces of candies and thus the extra wrappers
        int extraWrappers = numOfCandies / m;
		
		// total number of candies bought
        int totalCandies = numOfCandies + extraWrappers;

		//leftover wrappers that were not able to be exchange
        int leftoverWrappers = numOfCandies % m;
        
		// total number of wrappers after buying any extra candy 
        int totalWrappers = extraWrappers + leftoverWrappers;
        

		// keep exchanging wrappers until no longer able to
        while (totalWrappers >= m) {
            extraWrappers = totalWrappers / m;
            leftoverWrappers = totalWrappers % m;
            
            totalCandies += extraWrappers;
            totalWrappers = extraWrappers + leftoverWrappers;
        }
        cout << totalCandies << endl;
    }
    return 0;
}
