
#include <bits/stdc++.h>
using namespace std;
#define N 4

void getCofactor(int mat[N][N], int temp[N][N], int p, 
                                         int q, int n)
{
    int i = 0, j = 0;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {

          
            if (row != p && col != q) {
                temp[i][j++] = mat[row][col];

               
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

bool isSingular(int mat[N][N], int n)
{
    int D = 0; 

   
    if (n == 1)
        return mat[0][0];

    int temp[N][N]; 

    int sign = 1;

    for (int f = 0; f < n; f++) {

        getCofactor(mat, temp, 0, f, n);
        D += sign * mat[0][f] * isSingular(temp, n - 1);
        sign = -sign;
    }

    return D;
}
int main()
{
    int mat[N][N] = { { 4, 10, 1 },
                      { 0, 0, 0 },
                      { 1, 4, -3 } };
    if (isSingular(mat, N))
        cout << "Matrix is Singular" << endl;
    else
        cout << "Matrix is non-singular" << endl;
    return 0;
}