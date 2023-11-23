int solution(vector<int> nums, int k) {
    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());
    if (nums.size() == 1) return nums[0];
    return nums[k-1];
}

int solution(vector<int> nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int v : nums) {
        pq.push(v);
        if (pq.size() > k)
            pq.pop();
    }
    return pq.top();
}