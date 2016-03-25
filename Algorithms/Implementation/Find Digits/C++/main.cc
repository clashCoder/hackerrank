#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*  Input:
 *      T -> number of testcases
 *   the following is given T times
 *      N -> integer
 *  Constraints:
 *      1 <= T <= 15
 *      0 < N < 10^9
 *  Output:
 *      print the number of digits in N that evenly divide N
 */

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long long int n;
        vector<int> N;
        cin >> n;
        
        
        long long int i = 0;
        long long int tempN = n;
        
		// store digits of integer into a vector
        while (tempN != 0) {
            //N.push_back(n%10);
            N.insert(N.begin(), (tempN % 10) );
            tempN /= 10;
            i++;
        }
        
		// count the number of ways N divided by each of its digits gives a remainder of 0
        long long int divCount = 0;
        for(int i = 0; i < N.size(); i++) {
            if ( (N[i] > 0) && ((n % (N[i])) == 0) ) {
                divCount++;
            }
        }
        
        cout << divCount << endl;
    }
    return 0;
}
