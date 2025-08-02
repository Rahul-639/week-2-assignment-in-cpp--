#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> multiply(vector<int> &A, vector<int> &B) {
        int n = A.size();
        int m = B.size();
        vector<int> result(n + m - 1, 0);

        // Multiply every term of A with every term of B
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                result[i + j] += A[i] * B[j];
            }
        }

        return result;
    }
};

int main() {
    // Example input
    vector<int> A = {5, 0, 10, 6};
    vector<int> B = {1, 2, 4};

    Solution sol;
    vector<int> product = sol.multiply(A, B);

    // Output the result
    cout << "Product Polynomial: ";
    for (int coeff : product) {
        cout << coeff << " ";
    }
    cout << endl;

    return 0;
}
