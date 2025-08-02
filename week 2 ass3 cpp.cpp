#include <iostream>
#include <vector>
using namespace std;

// Function to calculate sum of principal diagonal
int sumDiagonal(int N, vector<vector<int>>& M) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += M[i][i]; // principal diagonal: row index == col index
    }
    return sum;
}

int main() {
    int T;
    cout << "Enter number of test cases: ";
    cin >> T;

    while (T--) {
        int N;
        cout << "Enter matrix size N: ";
        cin >> N;

        vector<vector<int>> M(N, vector<int>(N));
        cout << "Enter " << N*N << " matrix elements:\n";
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> M[i][j];

        int result = sumDiagonal(N, M);
        cout << "Sum of principal diagonal: " << result << endl;
    }

    return 0;
}
