// sol1. using partial sum, 54/55 pass, execution time limit
vector<int> solution(int s, vector<int> arr) {
    if (arr.empty()) return {-1};
    if (arr.size() == 1 && s != arr[0]) return {-1};
    int n = arr.size();
    
    vector<int> psum(n+1, 0);
    psum[1] = arr[0];
    
    for(int i = 1; i < n; ++i) {
        psum[i+1] = psum[i] + arr[i];
    }
    
    int max = 0;
    vector<int> ret = {-1};
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (psum[i] - psum[j] == s) {
                if (i-j > max) {
                    max = i-j;
                    ret = {j+1, i};
                }
            }
        }
    }
    return ret;
}

// sol2. not using partial sum, using unordered map. store pair of sum and index without duplication
vector<int> solution(int s, vector<int> arr) {
    if (arr.empty()) return {-1};
    if (arr.size() == 1 && s != arr[0]) return {-1};
    int n = arr.size();
    
    unordered_map<int, int> um;
    vector<int> ret;
    int sum = 0, maxLen = INT_MIN;
    
    for(int i = 0; i < arr.size(); ++i) {
        sum += arr[i];
        if (sum == s) {
            maxLen = i + 1;
            ret = {1, i+1};
        }
        if (um.count(sum-s)) {
            if (i - um[sum-s] > maxLen) {
                maxLen = i-um[sum-s];
                ret = {um[sum-s] + 2, i+1};
            }
        }
        um[sum] = i;
    }
    
    if(maxLen == INT_MIN) return {-1};
    else return ret;
}