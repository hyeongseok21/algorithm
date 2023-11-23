// long long determinant(vector<vector<long long>> matrix) {
//     int n = matrix.size();
//     for(int i = 0; i < n-2; ++i) {
//         for (int j = i+1; j < n-1; ++j) {
//             for (int k = i+1; k < n-1; ++k) {
//                 matrix[j][k] = matrix[j][k] * matrix[i][i] - matrix[j][i] * matrix[i][k];
//                 if (i > 0)
//                     matrix[j][k] = matrix[j][k] / matrix[i-1][i-1];
//             }
//         }
//     }
//     return matrix[-2][-2];
// }

// counting number of minimum spanning tree
// determinant of laplacian matrix is a number of minimum spanning tree by Kirchhoff’s theorem

long long mod = pow(10, 9) + 7;

int pwr(int a, int p) {
    if (!p) return 1;
    int x = pwr(a, p / 2);
    x = (long long) x * x % mod;
    if (p & 1) x = (long long) x * a % mod;
    return x;
}

int determinant(vector<vector<int> > a) {
    int n = a.size();
    int res = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (a[j][i] != 0) {
                swap(a[i], a[j]);
                break;
            }
        }
        int k = pwr(a[i][i], mod - 2);
        res = (long long) res * a[i][i] % mod;
        for (int j = 0; j < n; ++j) {
            a[i][j] = (long long) a[i][j] * k % mod;
        }
        for (int j = i + 1; j < n; ++j) {
            int q = a[j][i];
            for (int z = 0; z < n; ++z) {
                a[j][z] = (a[j][z] - (long long) a[i][z] * q) % mod;
                if (a[j][z] < 0) a[j][z] += mod;
            }
        }
    }
    return res;
}

int solution(int n, vector<vector<int>> respectList) {
    if (n == 1) return 1;
    vector<vector<int>> laplacian(n, vector<int>(n, 0));
    
    for (int a = 0; a < respectList.size(); ++a) {
        int i = respectList[a][0], j = respectList[a][1];
        laplacian[i][i] += 1;
        laplacian[j][j] += 1;
        laplacian[i][j] = -1;
        laplacian[j][i] = -1;
    }
    
    int result = (determinant(laplacian)) * n;
    
    return result;
}