#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*  Input: 
 *      T -> number of testcases
 *    Then will be asked for following input T times:
 *      N -> size of array
 *      N integers of the array
 *  Constraints:
 *      1 <= T <= 10
 *      1 <= N <= 10^5
 *      -10^4 <= ai <= 10^4
 *  Output:
 *      2 integers seperated by a space. The 1st integer represents the maximum sum of a contiguous subarray in
 *      the array. The 2nd integer represents the maximum sum of a non-contiguous subarray in the array.
 */

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    int T;
    
    cin >> T;
    
    //vector<int> A(n);
    
    for (int i = 0; i < T; i++) {
        
        int N;
        
        cin >> N;
        
        long int maxSumCont = 0;
        long int maxSumNonCont = 0;
        long int curSum = 0;
        int smallestNeg = -100000;      //basically negative Infinity due to input constraint
        vector<int> A;
        
        bool nonNeg = false;
        
        //check to see if all numbers are negative and if so return smallest one
        //as well as store all values in a vector
        for (int j = 0; j < N; j++) {
            int a;
            cin >> a;
            
            if (a >= 0) {
                nonNeg = true;
            }
            else {
                if (a > smallestNeg) {
                    smallestNeg = a;
                }
            }
            
            A.push_back(a);
        }
       
         //below works only if all values in the array are positive
            for (int j = 0; j < N; j++) {
            
                //int a;
                //cin >> a;
            
                //non-contigous will have only positive integers present
                if(A[j] > 0) {
                    maxSumNonCont += A[j];
                }
            
            
                //long int temp = curMax + a;
            
                curSum += A[j];
            
                if (curSum < 0) {
                    curSum = 0;
                }
            
                if (curSum > maxSumCont) {
                    maxSumCont = curSum;
                }
            }   
        
        if (nonNeg) {
           cout << maxSumCont << " " << maxSumNonCont << endl; 
        }
        else {
           cout << smallestNeg << " " << smallestNeg << endl; 
        }
        
    }
    
    return 0;
}
