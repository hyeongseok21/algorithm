vector<vector<int>> solution(vector<vector<int>> a) {
    reverse(a.begin(), a.end());
    for(int i = 0; i < a.size(); ++i) {
        for(int j = i; j < a.size(); ++j) {
            swap(a[i][j], a[j][i]);
        }
    }
    return a;
    
    // int m = a.size();
    // vector<vector<int>> ret = a;
    
    // for(int c = 0; c < m; ++c)  {
    //     int colcount = 0;
    //     for(int r = m-1; r > -1; --r) {
    //         int current = a[r][c];
    //         ret[c][colcount++] = current;
    //     }
    // }
    // return ret;
}