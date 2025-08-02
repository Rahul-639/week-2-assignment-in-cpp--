// C++ Program to check matrix is Identity matrix or not.
#include <bits/stdc++.h>
using namespace std;

// Function to check matrix
// is Identity matrix or not.
bool isIdentityMatrix(vector<vector<int>> &mat) {
    int n = mat.size();
    for (int i = 0; i < n; i++) {

        // condition to check main diagonal
        // elements are equal to 1 or not.
        if(mat[i][i] != 1)
            return false;

        for (int j = 0; j < n; j++) {

            // condition to check other elements 
            // except main diagonal are zero or not.
            if ((i != j) && (mat[i][j] != 0))
                return false;
            
        }
    }
    return true;
}

int main() {
    vector<vector<int>> mat = { { 1, 0, 0, 0 },
                      { 0, 1, 0, 0 },
                      { 0, 0, 1, 0 },
                      { 0, 0, 0, 1 } };

    if (isIdentityMatrix(mat))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}