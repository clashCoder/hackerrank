#include <iostream>
using namespace std;

int main() {
	
	long int N;
    long int Q;
    cin >> N >> Q;
    long int** varArr = new long int*[N];
    long int* kArr = new long int[N];

    // store values of series into a double array; as well as the values of k for reference later
    for(int i = 0; i < N; i++) {
        long int k;
        cin >> k;
        kArr[i] = k;
        
        varArr[i] = new long int[k];
        
        for(int j = 0; j < k; j++) {
            long int nextVal;
            cin >> nextVal;
            varArr[i][j] = nextVal;
        }
    }

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
