#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        vector<int> result;
        
        if (mat.empty()) return result;

        int top = 0;
        int bottom = mat.size() - 1;
        int left = 0;
        int right = mat[0].size() - 1;

        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; ++i)
                result.push_back(mat[top][i]);
            top++;

            for (int i = top; i <= bottom; ++i)
                result.push_back(mat[i][right]);
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; --i)
                    result.push_back(mat[bottom][i]);
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; --i)
                    result.push_back(mat[i][left]);
                left++;
            }
        }

        return result;
    }
};

int main() {
    // Sample input matrix
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}, 
        {13, 14, 15, 16}
    };

    Solution sol;
    vector<int> output = sol.spirallyTraverse(mat);

    // Print output
    cout << "Spiral Traversal: ";
    for (int num : output)
        cout << num << " ";
    cout << endl;

    return 0;
}
