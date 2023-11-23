int solution(string s, string t) {
    int m = s.length();
    int n = t.length();
    
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    int lcs = 0;
    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(s[i-1] == t[j-1]) {
                if (i == 1 || j == 1) dp[i][j] = 1;
                else {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }

                lcs = max(lcs, dp[i][j]);
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    return lcs;
}