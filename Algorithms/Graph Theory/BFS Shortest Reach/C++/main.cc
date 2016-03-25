#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <queue>
using namespace std;


/*  Input:
 *      T -> number of testcases
 *      N -> number of nodes in graph
 *      M -> number of edges in graph
 *      next M lines consist of two integers(x and y) separated by spaces that represent
 *          the two nodes that have an edge between them.
 *      S -> starting position
 *  Constraints:
 *      1 <= T <= 10
 *      2 <= N <= 1000
 *      1 <= M <= (N * (N-1)) / 2
 *      1 <= x, y, S <= N
 *  Output:
 *      shortest distance for each of the N-1 nodes from the starting position S
 *      unreachable nodes should be printed with value of -1
 */

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int T;
    cin >> T;
    
    for(int i = 0; i < T; i++) {
        int N;
        int M;
        int S;
        cin >> N >> M;
        
        vector< list<int> > graph(N);                    //graph to be filled in 
        vector<bool> explored(N,false);                  //determines which nodes have been visited
        vector<int> dist(N,-1);                          //distance from starting node for each node in the graph
        queue<int> L;                                   // discovered nodes starting from Starting node 'S'
        
        //fill in given graph from given edges between nodes x and y
        for(int i = 0; i < M; i++) {
            int x;
            int y;
            cin >> x >> y;
            
            //connect the undirected edge between node 'x' and node 'y'
            graph[x-1].push_back(y);
            graph[y-1].push_back(x);
        }
        
        
        
        //print to determine if edges are properly being connected
        /*
        for(int i = 0; i < N; i++) {
            cout << i+1 << " has edges to:";
            
            for(list<int>::iterator it=graph[i].begin(); it != graph[i].end(); it++) {
                cout << ' ' << *it;
            }
            cout << endl;
        }*/
        cin >> S;
        
        //BFS search algorithm with modifications to count distance
        L.push(S);
        explored[S - 1] = true;
        //int currentLevel = 1;
        
        while(!L.empty()) {
            int currNode = L.front();
            L.pop();
            //explored[currNode - 1] = true;
            //cout << currNode << ", ";
            
            for(list<int>::iterator it = graph[currNode - 1].begin(); it != graph[currNode - 1].end(); it++) {
                if(!explored[(*it) - 1]) {
                    explored[(*it) - 1] = true;                    
                    L.push(*it);
                    
                    if(dist[currNode - 1] == -1) {
                        dist[(*it) - 1] = 6;
                    }
                    else {
                        dist[(*it) - 1] = dist[currNode - 1] + 6;
                    }
                }
            }
            //currentLevel++;
            //explored[currNode - 1] = true;
        }
        
        for(int i = 0; (i < N); i++) {
            
            if( i != S - 1) {
                cout << dist[i] << " ";
            }
            //cout << dist[i] << " ";
        }
        cout << endl;
        
        //below works but adds unecessary works towards end
        /*while(!L.empty()) {
            int currNode = L.front();
            cout << currNode << ", ";
            L.pop();
            if(!explored[currNode - 1]) {
                explored[currNode - 1] = true;
                
                for(list<int>::iterator it=graph[currNode - 1].begin(); it != graph[currNode - 1].end(); it++) {
                    L.push(*it);
                }
            }
        }*/
               
    }
    return 0;
}
