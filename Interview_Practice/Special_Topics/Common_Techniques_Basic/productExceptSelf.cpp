// approach 1. multiply all element, divided ith element and obtain sum
// int solution(vector<int> nums, int m) {
//     long long mult = 1;
//     for(int i = 0; i < nums.size(); ++i) {
//         mult *= nums[i]; 
//     }
//     vector<long long> f(nums.size(), 0);
//     int ret = 0;
//     for(int i = 0; i < nums.size(); ++i) {
//         ret += (mult / nums[i]);
//     }
//     return ((ret % m) + m) % m;
// }

// approach 2. using horner's method
int solution(vector<int> nums, int m) {
    int s = 0, p = 1;
    for(int i = 0; i < nums.size(); ++i) {
        s = (p + s * nums[i]) % m;
        p = (p * nums[i]) % m;
    }
    return s % m;
}

// approach 3. 
int solution(vector<int> nums, int m) {
    vector<int> ret(nums.size(), 0);
    int prefix = 1;
    for(int i = 0; i < nums.size(); ++i) {
        ret[i] = prefix;
        prefix = prefix * nums[i] % m;
    }
    int postfix = 1;
    for(int i = nums.size()-1; i >= 0; --i) {
        ret[i] *= postfix;
        postfix = postfix * nums[i] % m;
    }
    int res = 0;
    for(int i = 0; i < ret.size(); ++i) {
        res += ret[i] % m;
    }
    return res % m;
}