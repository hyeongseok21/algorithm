void findsol(vector<int> &arr, vector<int> &sol, vector<vector<int>> &ret, int idx, int cursum, int num) {    
    
    // for(int i = 0; i < sol.size(); ++i) {
    //     cout << sol[i] << ' ';
    // }
    // cout << '\n';
    
    if (cursum == num) {
        if (find(ret.begin(), ret.end(), sol) == ret.end()) {
            ret.push_back(sol);
        }
        return;
    }
    
    if (cursum > num || idx == arr.size()) return;
    
    // if(idx == arr.size()) return;

    sol.push_back(arr[idx]);
    findsol(arr, sol, ret, idx+1, cursum + arr[idx], num);
    
    sol.pop_back();
    findsol(arr, sol, ret, idx+1, cursum, num);
}

vector<vector<int>> solution(vector<int> arr, int num) {
    vector<vector<int>> ret;
    vector<int> sol;
    findsol(arr, sol, ret, 0, 0, num);
    return ret;
}