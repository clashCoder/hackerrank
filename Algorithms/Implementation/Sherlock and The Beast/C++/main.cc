#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*  Input:
 *      T -> number of testcases
 *   the following input is given T times
 *      N -> integer representing number of digits in the number that needs to be outputted
 *  Constraint:
 *      1 <= T <= 20
 *      1 <= N <= 100000
 *  Output:
 *      Largest number having N digits with only having digits 3 and/or 5, 
 *          # of 3's has to be divisible by 5
 *          # of 5's has to be divisible by 3
 *      If no such number exists, then print -1
 */


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        string result = "";
        cin >> n;
        
        if (n <= 2) {
            result = "-1";
        }
        
        while(n > 2) {
            if ( (n == 5) || (n == 10) ) {
                result.append("33333");
                n -= 5;
            }
            else {
                result.append("555");
                n -= 3;
            }
            
            if ( (n == 4) || (n == 1) ) {
                result = "-1";
                break;
            }
        }
        
        cout << result << endl;
    }
    return 0;
}
