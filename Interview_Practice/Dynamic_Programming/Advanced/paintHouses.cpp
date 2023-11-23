// int solution(vector<vector<int>> cost) {
//     int n = cost.size();
    
//     for(int i = 1; i < n; ++i) {
//         cost[i][0] += min(cost[i-1][1], cost[i-1][2]);
//         cost[i][1] += min(cost[i-1][0], cost[i-1][2]);
//         cost[i][2] += min(cost[i-1][0], cost[i-1][1]);
//     }
    
//     return min(min(cost[n-1][0], cost[n-1][1]), cost[n-1][2]);
// }

// int solution(vector<vector<int>> cost) {
//     int n = cost.size();
    
//     vector<vector<int>> dp(n, vector<int> {0, 0, 0});
    
//     dp[0][0] = cost[0][0]; 
//     dp[0][1] = cost[0][1];
//     dp[0][2] = cost[0][2];
    
//     for(int i = 1; i < n; ++i) {
//         dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
//         dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
//         dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
//     }
    
//     return min(min(dp[n-1][0], dp[n-1][1]), dp[n-1][2]);
// }

int solution(vector<vector<int>> cost) {
    int n = cost.size();
    
    int dp[3] = {0, 0, 0};
    
    for(int i = 0; i < n; ++i) {
        int dp0 = min(dp[1], dp[2]) + cost[i][0];
        int dp1 = min(dp[0], dp[2]) + cost[i][1];
        int dp2 = min(dp[0], dp[1]) + cost[i][2];
        dp[0] = dp0, dp[1] = dp1, dp[2] = dp2;
    }
    
    return min(min(dp[0], dp[1]), dp[2]);
}