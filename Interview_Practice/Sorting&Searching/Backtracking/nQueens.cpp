// sol 1. backtracking
bool isvalid(vector<int> &board, int idx) {
    for(int i = 0; i < idx; ++i) {
        if (board[idx] == board[i] || idx - i == abs(board[idx] - board[i]))
            return false;
    }
    return true;
}

void backtrack(vector<vector<int>> &ret, vector<int> &board, int n, int idx) {
    if(n == idx) {
        ret.push_back(board);
        return;
    }
 
    for (int i = 1; i < n+1; ++i) {
        board[idx] = i;
        if (isvalid(board, idx)) {
            // for(int i = 0; i < board.size(); ++i) {
            //     cout << board[i] << ' ';
            // }
            // cout << '\n';
            backtrack(ret, board, n, idx+1);
        }
    }
}

vector<vector<int>> solution(int n) {
    vector<int> board(n, 0);
    vector<vector<int>> ret;
    backtrack(ret, board, n, 0);
    return ret;
}


// sol 2. using next_permutation in C++
vector<vector<int>> solution(int n) {
    vector<int> board(n);
    vector<vector<int>> ret;
    
    for(int i = 0; i < n; ++i) {
        board[i] = i + 1;
    }
    
    do {
        bool ans = true;
        for(int i = 0; i < n; ++i)
            for(int j = i + 1; j < n; ++j)
                if (j - i == abs(board[i] - board[j]))
                    ans = false;
        if(ans)
            ret.push_back(board);
    }while(next_permutation(board.begin(), board.end()));
    
    // backtrack(ret, board, n, 0);
    return ret;
}