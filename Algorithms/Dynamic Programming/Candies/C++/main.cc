#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/* Input:
 *      N -> integer representing the number of children
 *      N integers indicating the rating for each child
 * Constraints: 
 *      1 <= N <= 10^5
 *      1 <= ratingi <= 10^5
 * Output:
 *  minimum number of candies to pass given that each child must have 1 piece of candy
 *  and each child must have more pieces of candies than the child to the left and right of 
 *  that child if such child has higher rating.
 */

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    int N;
    cin >> N;
    
    vector<int> ratings(N);
    
    vector<long long int> candies(N,1);
    
    for (int i = 0; i < N; i++) {
        int candy;
        cin >> candy;
        ratings[i] = candy;
    }
    
    //loop 1 to give left-to-right correctness
    //in other words gives the correct number of candies
    //   for every child 'j' with a rating higher than child
    // 'j-1'
    for (int j = 1; j < N; j++) {
        if (ratings[j] > ratings[j-1]) {
            candies[j] = candies[j-1] + 1;
        }
    }
    
    //loop 2 to give right-to-left correctness
    //in other words gives the correct number of candies 
    //  for every child 'k' with a rating higher than child
    //  'k+1'
    for (int k = N - 2; k >= 0; k--) {
        
        if (ratings[k] > ratings[k+1]) {
            candies[k] = max(candies[k], candies[k+1] + 1);   
        }
    }
    
    long long int numOfCandies = 0;
    
    for (int l = 0; l < N; l++) {
        numOfCandies += candies[l];
    }
    
    cout << numOfCandies;
    return 0;
}
