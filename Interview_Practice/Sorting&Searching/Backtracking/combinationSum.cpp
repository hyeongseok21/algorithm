void bt(int sum, int cursum, int idx, vector<int> &a, vector<int> &tmp, vector<vector<int>> &ret) {
    // for(int i = 0; i < tmp.size(); ++i) {
    //     cout << tmp[i] << ' ';
    // }
    // cout << '\n';
    
    if(cursum == sum) {
        // int s = 0;
        // for (int i = 0; i < tmp.size(); ++i) {
        //     s += tmp[i];
        // }
        // if (s == sum) {
            vector<int> res = tmp;
            sort(res.begin(), res.end());
            ret.push_back(res);
        // }
        return;
    }
    if (cursum > sum || idx == a.size()) return;
    
    // for(int index = idx; index < a.size(); ++index) {
    //     if (cursum < sum) {
    //         tmp.push_back(a[index]);
    //         bt(sum, cursum + a[index], index, a, tmp, ret);
    //         tmp.pop_back();
    //     }
    // }
    // if (idx == a.size()) return;
        
    tmp.push_back(a[idx]);
    bt(sum, cursum + a[idx], idx, a , tmp, ret);
    
    tmp.pop_back();
    bt(sum, cursum, idx+1, a, tmp, ret);

}

string solution(vector<int> a, int sum) {
    vector<vector<int>> ret;
    vector<int> tmp;
    string ans = "";
    
    bt(sum, 0, 0, a, tmp, ret);
    
    sort(ret.begin(), ret.end());
    ret.erase(unique(ret.begin(), ret.end()), ret.end());

    for(int i = 0; i < ret.size(); ++i) {
        string str = "", tmp = "";
        for(int j = 0; j < ret[i].size(); ++j) {
            tmp += to_string(ret[i][j]) + " ";
        }
        str = "(" + tmp.substr(0, tmp.length()-1) + ")";
        ans += str;
    }
    
    return ans == "" ? ans = "Empty" : ans;
}