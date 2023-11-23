// approach 1. count from back using nested loop - 19/22 pass
// long long solution(vector<int> nums) {
//     long long res = 0;
//     for(int i = nums.size()-2; i >= 0; --i) {
//         int count = 0;
//         for(int j = i + 1; j < nums.size(); ++j) {
//             if(nums[i] > nums[j]) count++;
//         }
//         res += count;
//     }
//     return res;
// }


long long solution(std::vector<int> nums) {
    std::vector<int> aux;
    long long int cnt = 0;
    for(int i=nums.size()-1; i>=0; --i){
        std::vector<int>:: iterator it;
        it = lower_bound(aux.begin(), aux.end(), nums[i]);
        int pos = it - aux.begin();
        cnt += pos;
        aux.insert(it, nums[i]);
        for(int i = 0; i < aux.size(); ++i) {
            cout << aux[i] << ' ';
        }
        cout << ' '  << pos << ' ' << cnt << '\n';
    }
    
    return cnt;
}