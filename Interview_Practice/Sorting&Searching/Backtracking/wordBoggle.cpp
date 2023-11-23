// sol1. backtracking or DFS. Execution time error on 7/10.

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool isword (string &s, vector<string> &words) {
    for(int i = 0; i < words.size(); ++i) {
        if (s == words[i]) return true;
    }
    return false;
}

void findwords (vector<vector<char>> &board, vector<string> &words, vector<vector<bool>> &visited, int i, int j, string &str, vector<string> &ret) {
    
    if (i < 0 || i >= board.size() || j < 0 ||  j >= board[0].size() || board[i][j] != '0') {
        return;
    }
    
    visited[i][j] = true;
    // board[i][j] = '0';
    // char tmp = board[i][j];
    str = str + board[i][j];
    
    if (isword(str, words)) {
        if(find(ret.begin(), ret.end(), str) == ret.end()) {
            ret.push_back(str);
            cout << str << '\n'; 
        }
    }
        
    for (int k = 0; k < 8; ++k) {
        int row = dx[k] + i;
        int col = dy[k] + j;
        if (row >= 0 && row < board.size() && col >= 0 && col < board[0].size() && !visited[row][col]) {
            findwords(board, words, visited, row, col, str, ret);
            cout << str << ' ' << row << ' ' << col << '\n';
        }
    }
    
    // findwords(board, words, visited, i+1, j, str, ret);
    // findwords(board, words, visited, i+1, j-1, str, ret);
    // findwords(board, words, visited, i+1, j+1, str, ret);
    // findwords(board, words, visited, i, j+1, str, ret);
    // findwords(board, words, visited, i, j-1, str, ret);
    // findwords(board, words, visited, i-1, j+1, str, ret);
    // findwords(board, words, visited, i-1, j, str, ret);
    // findwords(board, words, visited, i-1, j-1, str, ret);
    
    str.erase(str.length() - 1);
    // board[i][j] = tmp;
    visited[i][j] = false;
    //cout << "end search" << '\n';
}

vector<string> solution(vector<vector<char>> board, vector<string> words) {
    vector<string> ret;
    int n = board.size();
    int m = board[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    string str = "";
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cout << "start" << '\n';
            findwords(board, words, visited, i, j, str, ret);
        }
    }
    sort(ret.begin(), ret.end());
    ret.erase(unique(ret.begin(), ret.end()), ret.end());
    cout << "end";
    return ret;
}


// sol 2. trie
// int n, m;
// struct trie {
//     trie* chil[26] = {NULL};
//     int last = -1;
// };

// void solve(vector<vector<char>> &board, trie* tt, int i, int j, string &str, vector<string> &ret) {
    
//     if (tt == NULL || tt->chil[board[i][j]-'A'] == NULL)
//         return;
    
//     str += board[i][j];
//     tt = tt -> chil[board[i][j]-'A'];
    
//     char tmp = board[i][j];
//     board[i][j] = '0';
    
//     cout << str << ' ' << tt->last << '\n';
    
//     if(tt->last == 0) {
//         cout << '1';
//         tt->last = 1;
//         ret.push_back(str);
//     }
    
//     for(int k = 0; k < 8; ++k) {
//         int x = i + dx[k], y = j + dy[k];
//         if(x >= 0 && x < n && y >= 0 && y < m && board[x][y]!='0')
//             solve(board, tt, x, y, str, ret);
//     }
    
//     board[i][j] = tmp;
//     str.pop_back();
// }


// vector<string> solution(vector<vector<char>> board, vector<string> words) {
//     vector<string> ret;
//     n = board.size();
//     m = board[0].size();
//     //vector<vector<bool>> visited(n, vector<bool>(m, false));
    
//     // build trie
//     trie* tt = new trie();
//     for(auto word: words) {
//         trie* k = tt;
//         for(int i = 0; i < word.size(); i++) {
//             if(k->chil[word[i] - 'A'] == NULL)
//                 k->chil[word[i] - 'A'] = new trie();
//             k = k->chil[word[i] - 'A'];
//             if(i == (word.size()-1))
//                 k->last = 0;
//         }
//     }
    
//     cout << "start" << '\n';
//     string str = "";
//     for(int i = 0; i < n; ++i) {
//         for(int j = 0; j < m; ++j) {
//             solve(board, tt, i, j, str, ret);
//         }
//     }
//     cout << "end";
//     sort(ret.begin(), ret.end());
//     ret.erase(unique(ret.begin(), ret.end()), ret.end());
//     return ret;
// }