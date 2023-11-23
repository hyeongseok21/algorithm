sol1. dp with O(nm) space
int solution(vector<vector<char>> matrix) {
    if (matrix.empty()) return 0;
    
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    
    int ans = -1;
    for(int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 || j == 0) {
                if (matrix[i][j] == '1') dp[i][j] = 1;
            }
            else {
                if(matrix[i][j] == '1') {
                    dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
                }
            }
            ans = max(ans, dp[i][j]);
        }
    }
    
    return ans * ans;
}

// sol2. dp with O(m) space. applying sliding window
int solution(vector<vector<char>> matrix) {
    if (matrix.empty()) return 0;
    
    int n = matrix.size(), m = matrix[0].size();
    vector<int> pre(m, 0), cur(m, 0);
    
    int ans = -1;
    for(int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 || j == 0) {
                if (matrix[i][j] == '1') cur[j] = 1;
            }
            else {
                if(matrix[i][j] == '1') {
                    cur[j] = min(pre[j], min(pre[j-1], cur[j-1])) + 1;
                }
            }
            ans = max(ans, cur[j]);
        }
        fill(pre.begin(), pre.end(), 0);
        swap(pre, cur);
    }
    
    return ans * ans;
}