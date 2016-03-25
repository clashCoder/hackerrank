#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
   Determines the number of ways we can give change 'n' with 'm' coins in the set 'coins'
   coins -> contains the value of the coins to be used
   n -> amount of change
   m -> number of items that will be used from set coins 
            (must be within 0 and n)

	1 <= Ci <= 50
	1 <= N <= 250
	1 <= M <= 50
	
	NOTE: List of coins will contain distinct integers

            
   Complexity: takes O(m * n) to fill in necessary values and then from values can output result in O(1)
                    so the running time for this algorithm is O(m * n)
*/
long long int coinChange(vector<int> coins, int n, int m);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int N;				// total change
    int M;				// number of coins in set 'C'
    
    cin >> N >> M;
    
    vector<int> C(M);
    
	//fill in set 'C' with appropriate coin values
    for (int i = 0; i < M; i++) {
        int Ci;
        cin >> Ci;
        C[i] = Ci;
    }
    
	// return the number of ways one can make change for the amount 'N' with given list 'C' and 
	// using 'M' of the items in 'C'
    long long int numOfWays = coinChange(C,N,M);
    cout << numOfWays;
    
    return 0;
}

/*

*/

long long int coinChange(vector<int> coins, int n, int m) {
    
    /*
       There is no way to give negative change -- commented out due to constraints of problem
    */
    
    /*if (n < 0) 
        return 0;
    */
    
    if (n == 0)
        return 1;
    
    /*
      There is no way to give change 'n' (if n < 0) with zero or less coins
			--commented out due to constraints of problem
    */
    /*if (m <= 0) {
        return 0;
    }*/
    
	// 2D vector that will hold solutions to subproblems
	// subProb[N+1][m] -> example subProb[0][0] tells us how many ways one can give change
	//								when we have to give '0' change and have 0 coins from set 'C'
	
    vector< vector<long long int> > subProb(n+1, vector<long long int>(m,0));
    
	/*
		base case: one can give change of 0 cents exactly one way and that is
						to give no coins
	*/
    for (int i = 0; i < m; i++) {
        subProb[0][i] = 1;
    }
    
    /*
		follow the recursive relation to use memoization:
		     subproblem solution either cointains Cm or it does not
		if solution contains Cm then recursive call function on (N - Cm, m)
		if solution does not contain Cm then recursive call function on (N, m-1)
		the solution to the subproblem is the number of ways that the solution does not contain Cm 
		   plus the number of ways that the solution contains Cm
	*/
    for (int i = 1; i < n + 1; i++) {
        for (int j = 0; j < m; j++) {
            long long int includeCi = i - coins[j];
            long long int containCi;
            long long int noCi;
            
            if (includeCi >= 0) {
                containCi = subProb[i-coins[j]][j];
            }
            else {
                containCi = 0;
            }
            
            if (j >= 1) {
                noCi = subProb[i][j-1];
            }
            else {
                noCi = 0;
            }
            subProb[i][j] = containCi + noCi;
        }
    }
    
    return subProb[n][m-1];
    
}
