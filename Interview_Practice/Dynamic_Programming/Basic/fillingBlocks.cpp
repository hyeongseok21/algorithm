int solution(int n) {
    vector<int> dp(n+1, 0);
    dp[1] = 1;
    dp[2] = 5;
    dp[3] = 11;
    dp[4] = 36;
    for(int i = 5; i < n+1; ++i) {
        dp[i] = dp[i-1] + 5 * dp[i-2] + dp[i-3] - dp[i-4];
    }
    return dp[n];
}

// https://math.stackexchange.com/questions/664113/count-the-ways-to-fill-a-4-times-n-board-with-dominoes
