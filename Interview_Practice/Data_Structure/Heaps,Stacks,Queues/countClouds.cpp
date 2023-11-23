void check(vector<vector<char>> &skyMap, int &n, int &m, int x, int y) {
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    
    skyMap[x][y] = '0';
    for (int d = 0; d < 4; ++d) {
        int nx = dx[d] + x;
        int ny = dy[d] + y;
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && skyMap[nx][ny] == '1') {
            check(skyMap, n, m, nx, ny);
        }
    }
}


int solution(vector<vector<char>> skyMap) {
    int n = skyMap.size();
    int m = n ? skyMap[0].size() : 0;
    int ret = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(skyMap[i][j] == '1') {
                ++ret;
                check(skyMap, n, m, i, j);
            }
        }
    }
    return ret;
}