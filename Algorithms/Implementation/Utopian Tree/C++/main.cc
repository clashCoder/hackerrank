#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*  Input:
 *      T -> number of testcases
 *    the following input is given T times:
 *      N -> number of cycles to go trough
 *  Constraint:
 *      1 <= T <= 10
 *      0 <= N <= 60
 *  Output:
 *      print height of tree after N cycles... 2 differenct cycles each year...spring and summer
 *              in spring tree grows by 1 meter, in summer tree doubles its height
 */

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        
        int treeHeight = 1;		//tree begins at 1 meter
        int counter = 1;		//counter to keep track of cycles.
        
        for(int i = 0; i < n; i++) {
            int cycle = counter % 2;		//current cycle
            
			//each summer (even cycle) tree doubles height
            if (cycle == 0) {
                treeHeight += 1;
            }
			//each spring (odd cycle) tree increases height by 1 meter
            else {
                treeHeight *= 2;
            }
            counter++;
        }
        cout << treeHeight << endl;
    }
    return 0;
}
