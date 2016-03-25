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
 *      n -> integer representing number of cities
 *      m -> integer representing number of cities with space stations
 *      m integers representing index of each city that has a space station
 *  Constraints:
 *      1 <= n <= 10^5
 *      1 <= m <= n
 *  Output Format:
 *      Print the maximum distance one would need to travel from any city to reach the
 *      nearest space station.
 */


int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<int> c(m);
    for(int c_i = 0;c_i < m;c_i++){
       cin >> c[c_i];
    }
    
    sort(c.begin(),c.end());
    
    long int currentStationPos = 0;
    long int closestLeftStation = c[currentStationPos];
    long int closestRightStation; //= c[currentStationPos + 1];
    
    if(currentStationPos + 1 == m) {
        closestRightStation = 1000000;
    }
    else {
        closestRightStation = c[currentStationPos + 1];
    }
        
    
    vector<long int> distances(n);
    
    for(long int i = 0; i < n; i++)
        distances[i] = -1;
    
    for(long int i = 0; i < m; i++) {
        long int index = c[i];
        distances[index] = 0;
    }
    
    for(long int i = 0; i < n; i++) {
        if(distances[i] != 0) {
            
            if(i < closestLeftStation) {
                long int smallest = closestLeftStation - i;
                distances[i] = smallest;
            }
            else {
                long int smallest = min( (i - closestLeftStation), (closestRightStation - i) );
                distances[i] = smallest;
            }
        }
        else {
            if(i == closestRightStation) {
                currentStationPos++;
                closestLeftStation = c[currentStationPos];
                if(currentStationPos == m - 1) {
                    closestRightStation = 1000000;          // due to input given...this serves as infinity
                }
                else {
                    closestRightStation = c[currentStationPos + 1];
                }
            }
        }
    }
    
    long int maxDistance = 0;
    
    for(long int i= 0; i < n; i++) {
        if(distances[i] > maxDistance) {
            maxDistance = distances[i];
        }
    }
    
    cout << maxDistance;
    
    return 0;
}