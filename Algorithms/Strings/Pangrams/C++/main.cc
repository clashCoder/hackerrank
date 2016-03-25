#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

/*  Input:
 *      s -> string
 *  Constraints:
 *      1 <= |s| <= 10^3
 *      s will only contain spaces, upper and lower case letters
 *  Output:
 *      output whether or not the string is a pangram
 */


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    string s;
    getline(cin, s);
    int stringLength = s.size();
    set<char> alphabet;
    
    for (int i = 0; i < stringLength; i++) {
        if (isalpha(s[i])) {
            alphabet.insert(tolower(s[i]));
            if (alphabet.size() == 26) {
                cout << "pangram" << endl;
                return 0;
            }
        }
    }
    
    cout << "not pangram" << endl;
    return 0;
}
