// int count(int n, int dp[]) {
//     if (n==1) return dp[1] = 1;
//     if (n==2) return dp[2] = 2;
//     if (n >= 3) {
//         dp[n] = count(n-1, dp) + count(n-2, dp);
//     }
//     return dp[n];
// }

// int solution(int n) {
//     int dp[n];
//     int ret = count(n, dp);
//     return ret;
// }

int solution(int n) {
    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;
    
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
