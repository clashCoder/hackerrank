#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*  Input:
 *      N -> number of sticks
 *      next N lines indicate the length of sticks
 *  Constraints:
 *      1 <= N <= 1000
 *      1 <= ai <= 1000     , where ai represents the length of stick i
 *  Output:
 *      at each step, determine/output how many sticks can be cut by the minimum length of all the sticks
 *          until the length of all sticks is zero.
 */

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }
    
    sort(arr.begin(), arr.end());
    
    int position = 0;
    int size = arr.size();
    
    while (position < size) {
        int min = arr[position];
        
        cout << size - position << endl;
        
        for (int i = position; i < size; i++) {
            arr[i] -= min;
            
            if (arr[i] <= 0) {
                position++;
            }
        }
    }
    
    return 0;
}
