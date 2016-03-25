#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*  Input:
 *      S -> string / message
 *              original message is SOS repeated n times
 *  Constraint:
 *      1 <= |S| <= 99
 *      |S| % 3 = 0
 *      S will contain only uppercase English letters
 *  Output:
 *      print the number of letters that have been altered in the message.
 */

int main(){
    string S;
    cin >> S;
    
    int numAltered = 0;
    int strSize = S.size();
    
    for(int i = 0; i < strSize; i++) {
        if((i+1) % 3 == 1) {
            if(S[i] !=  'S')
                numAltered++;
        }
        if((i+1) % 3 == 2) {
            if(S[i] != 'O') 
                numAltered++;
        }
        if((i+1) % 3 == 0) {
            if(S[i] != 'S')
                numAltered++;
        }
    }
    
    cout << numAltered;
    
    return 0;
}
