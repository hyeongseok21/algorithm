// sol 1. hard-coded solution
vector<string> solution(vector<int> nums) {
    if (nums.empty()) return {};
    if (nums.size() == 1) return {to_string(nums[0])};
   
    vector<string> ret;
    string tmp = to_string(nums[0]);
    // tmp += '-';
    // tmp += '>';
    
    if (nums.size() == 2) {
        if (nums[1] - nums[0] == 1) {
            tmp = tmp + "->" + to_string(nums[1]);
            ret.push_back(tmp);
        } 
        else {
            ret.push_back(tmp);
            tmp = to_string(nums[1]);
            ret.push_back(tmp);
        }
    }
    

    if (nums.size() > 2) {
        for(int i = 1; i < nums.size(); ++i) {
            if (nums[i] - nums[i-1] != 1) {
                if (nums[i-1] - nums[i-2] == 1) {
                    tmp = tmp + "->" + to_string(nums[i-1]);
                    ret.push_back(tmp);
                    tmp = to_string(nums[i]);
                }
                else {
                    ret.push_back(tmp);
                    tmp = to_string(nums[i]);
                }
            }
            if (i == nums.size()-1) {
                if (nums[i] - nums[i-1] == 1) {
                    tmp = tmp + "->" + to_string(nums[i]);
                    ret.push_back(tmp);
                }
                else {
                    tmp = to_string(nums[i]);
                    ret.push_back(tmp);
                }
            }
        }
    }
    
    return ret;
}

// sol 2. dp
