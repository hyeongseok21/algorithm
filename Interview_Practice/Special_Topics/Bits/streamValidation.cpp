bool solution(vector<int> stream) {
    
    int cnt = 0;
    for(int x : stream){
        if(cnt) {
            --cnt;
            if((x & 0b11000000) != 0b10000000)
                return false;
        }
        else {
            int m = 0;
            while(x & (128 >> m)) ++m;
            if(m == 1 || m > 4) return false;
            if(m) cnt = m - 1;
        }
    }
    
    return cnt == 0;
}