#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*  Input:
 *      T -> number of testcases
 *    the following input is given T times
 *      N -> number of prisoners
 *      M -> number of sweets
 *      S -> prisoner ID
 *  Constraints:
 *      1 <= T <= 100
 *      1 <= N <= 10^9
 *      1 <= M <= 10^9
 *      1 <= S <= 10^9
 *  Output:
 *      print the ID number of prisoner who receives poisoned sweet if one starts at position S and
 *          continues in a cyclic manner until we get to the S + M prisoner
 */

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    long long int T;
    cin >> T;
    
    for (long long int i = 0; i < T; i++) {
        long long int N;
        long long int M;
        long long int S;
        
        cin >> N >> M >> S;
        
		// handle case when S > N: S should be within N...so if it is larger than N
		// 		then that means it wraps around so modulo will help find where it wraps
		//		around.
        long long int modOfS = S % N;
        
		// if it wraps around and we get a result of zero...we can only be at the end
		//		of the array or N
		// else it should be the result of the modulo
        if (S > N) {
            if(modOfS == 0) {
                S = N;
            }
            else {
                S = modOfS;
            }
        }

		/* we have inputs N(number of prisoners), M(number of sweets to distribute), 
		 * 		S(the position to start distributing sweets):
		 *	 the index of the position to end distribution is for the most part given by:
		 *   	(M + S) % N if we are going based on 0-index but the problem
		 *   is based on 1-index so in order to fix this we subtract for all indexes
		 *   except for those that (M + S) % N give 0 or 1... these cases are further adjusted
		 *   as seen below.
		 */
		
        long long int index;
        if (N == 1) {
            index = N;
        }
        else {
            index = (M + S) % N;
        }
        //long long int index = (M + S) % N;
        //cout << index << endl;
        
        if (index == 0) {
            index = N - 1;
        }
        else if (index == 1) {
            index = N;
        }
        else {
            index = index - 1;
        }
        
        cout << index << endl;
        
    }
    return 0;
}
