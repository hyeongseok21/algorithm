int solution(vector<int> nums, vector<vector<int>> queries) {
    int mod = 1000000007;
    vector<long long> psum(nums.size()+1, 0);
    for(int i = 1; i < nums.size()+1; ++i) {
        psum[i] = (psum[i-1] + nums[i-1]);
    }
    
    long long ans = 0;
    for(int i = 0; i < queries.size(); ++i) {
        int start = queries[i][0], end = queries[i][1];
        ans += (psum[end+1] - psum[start]);
    }
    return ((ans % mod) + mod) % mod;
}