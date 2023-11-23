bool solution(string s, string p) {
    vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));
    dp[0][0] = true;
    for (int j = 1; j <= p.size(); j++) {
        if (p[j-1] == '*' && dp[0][j - 2]) {                
            dp[0][j] = true;            
        }            
    }        
    for (int i = 0; i < s.size(); i++) {           
        for (int j = 0; j < p.size(); j++) {              
            if (p[j] == '.') {                  
                dp[i + 1][j + 1] = dp[i][j];                   
            }
            if (p[j] == s[i]) {                  
                dp[i + 1][j + 1] = dp[i][j];                   
            }       
            if (p[j] == '*') {                  
                if (p[j - 1] != s[i] && p[j - 1] != '.') {                        
                    dp[i + 1][j + 1] = dp[i + 1][j - 1];
                } else {
                    dp[i + 1][j + 1] = (dp[i + 1][j] || dp[i][j + 1] || dp[i + 1][j - 1]);
                }
            }
        }
    }
    for(int i = 0; i < s.size()+1; ++i) {
        for(int j = 0; j < p.size()+1; ++j) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    return dp[s.size()][p.size()];  
}