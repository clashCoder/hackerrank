// Note: N sequences numbered 0 to N - 1
//Not allowed to use c++ vector library...in fact could not modify anything above and including "int main() {}" line

// running time of program: 
// to store values of series we have O(N * k)
// to output answer we have O(Q)
// so overall we have a running time of O( (N * k) + Q)

#include <iostream>
using namespace std;

int main() {
// -- code had to be inserted below this line
	long int N;						// number of sequences
    long int Q;						// number of queries
    cin >> N >> Q;

	// create 2D array to hold the N sequences 
	// (and thus both the index of the Sequence and the index of the elements in the sequence)
    long int** varArr = new long int*[N];

	// kArr is not really needed...further more it is causing a memory leak....remove it
    //long int* kArr = new long int[N];

    // store values of series into a double array
    for(int i = 0; i < N; i++) {
        long int k;				// 'k' indicates the number of elements in the Sequence
        cin >> k;
        //kArr[i] = k;
        
        varArr[i] = new long int[k];	//store value of 'k' of Sequence 'i'
        
        for(int j = 0; j < k; j++) {
            long int nextVal;
            cin >> nextVal;
            varArr[i][j] = nextVal;
        }
    }

	// output answer to the queries: the answer should be the following
	//		index of the Sequence which would be found in the rows of the '2D array' -> a
	//		index of the elements which would be found in the columns of the '2D array' -> b
    long int a,b;
    for(int i = 0; i < Q; i++) {
        cin >> a >> b;
        cout << varArr[a][b] << endl;
    }

    //print out values of double array
/*
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < kArr[i]; j++) {
            cout << varArr[i][j] << " ";
        }
        cout << endl;
    }
*/
    /* NOTE: deallocation code was obtained from following URL:
    
        http://www.csee.umbc.edu/courses/undergraduate/202/spring07/Lectures/ChangSynopses/modules/m16-2D-array/slides.php?print
    
        Attempt to cite source of code.
    */
    for (int row = 0; row < N; row++) {
        delete [] varArr[row];
        varArr[row] = 0;
    }

    delete [] varArr;
    varArr = 0;
    
	return 0;
}
