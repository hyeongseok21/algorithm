int solution(vector<vector<char>> field) {
    int m = field.size();
    int n = m > 0 ? field[0].size() : 0;
    
    int maxcnt = 0;
    for(int y = 0; y < m; ++y) {
        for(int x = 0; x < n; ++x) {
            if (field[y][x] != '0') continue;
            
            int cnt = 0;
            
            // right
            for(int k = x; k < n; ++k) {
                if (field[y][k] == 'W') break;
                if (field[y][k] == 'E') cnt++;
            }
            
            // left
            for(int k = x; k >= 0; --k) {
                if (field[y][k] == 'W') break;
                if (field[y][k] == 'E') cnt++;
            }
            
            // up
            for(int k = y; k >= 0; --k) {
                if (field[k][x] == 'W') break;
                if (field[k][x] == 'E') cnt++;
            }
            
            // down
            for(int k = y; k < m; ++k) {
                if (field[k][x] == 'W') break;
                if (field[k][x] == 'E') cnt++;
            }
            
            maxcnt = max(maxcnt, cnt);
        }
    }
    
    return maxcnt;
}