// void climb(vector<vector<int>> ret, vector<int> v, int n, int k) {
//     if (n == 0) {
//         ret.push_back(v);
//         return;
//     }

//     for (int i = 1; i < k + 1; ++i) {
//         if (n-i >= 0) {
//             vector<int> v1(v);
//             v1.push_back(i);
//             climb(ret, v1, n-i, k);
//         }
//     }
// }

// vector<vector<int>> solution(int n, int k) {
//     vector<vector<int>> ret;
//     vector<int> v;
//     climb(ret, v, n, k);
//     return ret;
// }

void bt(int n, int k, vector<int> curPath, vector<vector<int>> &ans) {
    if (n < 0) return;
    
    if (n == 0) {
        ans.push_back(curPath);
    }
    
    for (int i = 0; i < curPath.size(); ++i) {
        cout << curPath[i] << ' ';
    }
    cout << '\n';
    
    for (int i = 1; i <= k; ++i) {
        curPath.push_back(i);
        bt(n - i, k, curPath, ans);
        curPath.pop_back();
    }
}

vector<vector<int>> solution(int n, int k) {
    vector<vector<int>> ans;
    bt(n, k, vector<int> {}, ans);
    return ans;
}