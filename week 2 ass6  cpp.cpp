#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> multiply(vector<int> &A, vector<int> &B) {
        int n = A.size();
        int m = B.size();
        vector<int> result(n + m - 1, 0); // Degree of result = (n-1) + (m-1)

        // Multiply each term of A with each term of B
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[i + j] += A[i] * B[j];
            }
        }

        return result;
    }
};

// Utility to print the polynomial
void printPolynomial(const vector<int>& poly) {
    for (int i = 0; i < poly.size(); i++) {
        cout << poly[i];
        if (i != 0) cout << "x^" << i;
        if (i != poly.size() - 1) cout << " + ";
    }
    cout << endl;
}

// Driver code
int main() {
    Solution sol;
    vector<int> A, B;

    int n1, n2;
    cout << "Enter size of first polynomial: ";
    cin >> n1;
    A.resize(n1);
    cout << "Enter " << n1 << " coefficients for first polynomial:\n";
    for (int i = 0; i < n1; ++i) {
        cin >> A[i];
    }

    cout << "Enter size of second polynomial: ";
    cin >> n2;
    B.resize(n2);
    cout << "Enter " << n2 << " coefficients for second polynomial:\n";
    for (int i = 0; i < n2; ++i) {
        cin >> B[i];
    }

    vector<int> result = sol.multiply(A, B);

    cout << "Resultant Polynomial: ";
    printPolynomial(result);

    return 0;
}
