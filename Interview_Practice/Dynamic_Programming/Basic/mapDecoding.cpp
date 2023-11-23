const int MOD = 1000000007;

int solution(string message) {
    int n = message.length();
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = message[0] == '0' ? 0 : 1;
    for(int i = 2; i < n+1; ++i) {
        int sub1 = stoi(message.substr(i-1, 1));
        int sub2 = stoi(message.substr(i-2, 2));
        if(sub1 != 0) dp[i] = dp[i-1] % MOD;
        if(sub2 > 9 && sub2 < 27) dp[i] = (dp[i] + dp[i-2]) % MOD;
    }
    return dp[n];
}