vector<int> solution(vector<vector<int>> g, int s) {
    int n = g.size();
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(g[i][j] == -1) g[i][j] = 100;
        }
    }
    
    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    g[s][s] = 0;
    
    return g[s];
}