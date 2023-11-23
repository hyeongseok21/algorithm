// approach 1. exhaustive search, 10/12 test case pass
// int solution(vector<int> sequence) {
//     if (sequence.empty()) return 0;
//     int ret = 0;
//     for(int i = 0; i < sequence.size(); ++i) {
//         vector<int> s;
//         for(int j = i + 1; j < sequence.size(); ++j) {
//             if (sequence[i] < sequence[j])
//                 s.push_back(sequence[j]);
//         }
//         ret = max(ret, 1 + solution(s));
//     }
//     return ret;
// }

// approach 2. dp, O(n^2) sol.
// int solution(vector<int> sequence) {
//     int n = sequence.size();
//     vector<int> LIS(n, 1);
//     for(int i = 1; i < n; ++i) {
//         for(int j = 0; j < i; ++j) {
//             if (sequence[j] < sequence[i])
//                 LIS[i] = max(LIS[i], LIS[j] + 1);
//         }
//         // for(int i = 0; i < LIS.size(); ++i) {
//         //     cout << LIS[i] << ' ';
//         // }
//         // cout << '\n';
//     }
    
//     return *max_element(LIS.begin(), LIS.end());
// }

// approach 3. dp, O(nlgn) sol.
int solution(vector<int> sequence) {
    vector<int> dp;
    for(int i = 0; i < sequence.size(); ++i) {
        int pos = lower_bound(dp.begin(), dp.end(), sequence[i]) - dp.begin();
        
        if (pos == dp.size()) {
            dp.push_back(sequence[i]);
        }
        else
            dp[pos] = sequence[i];
        for(int i = 0; i < dp.size(); ++i) {
            cout << dp[i] << ' ';
        }
        cout << '\n';
    }
    
    return dp.size();
}