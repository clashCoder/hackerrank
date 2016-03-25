#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*  Input:
 *      T -> number of testcases
 *    the following input is given T times
 *      N -> length of freeway
 *  Constraints:
 *      2 <= N <= 100000
 *      1 <= T <= 1000
 *      0 <= i < j < N
 *      2 <= j - i + 1 <= min(N, 1000)
 *      1 <= width[k] <= 3, where 0 <= k < N , k indicates type of car and width[k] is the width of that
 *                                                  type of car.
 *  Output:
 *      largest vehicle type that can pass through all segments
 */

int main(){
    int n;
    int t;
    cin >> n >> t;
    vector<int> width(n);
    for(int width_i = 0;width_i < n;width_i++){
       cin >> width[width_i];
    }
    for(int a0 = 0; a0 < t; a0++){
        int i;
        int j;
        cin >> i >> j;
        
        int minLane = 3;
		// determine which Lane is the smallest from i to j
        for(int k = i; k < (j + 1); k++) {
            if (width[k] < minLane) {
                minLane = width[k];
            }
        }
        //output the smallest Lane; indicating the largest vehicle that can pass through
        cout << minLane << endl;
    }
    return 0;
}
