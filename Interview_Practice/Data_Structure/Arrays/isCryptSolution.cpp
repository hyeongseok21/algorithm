bool solution(vector<string> crypt, vector<vector<char>> solution) {
    unordered_map<char, int> hash;
    for(auto s : solution)
        hash[s[0]] = s[1] - '0';
    vector<int> w(3);
    for(int i = 0; i < 3; ++i) {
        if (hash[crypt[i][0]] == 0 && crypt[i].size() > 1) 
            return false;
        for(auto c : crypt[i])
            w[i] = w[i] * 10 + hash[c];
    }
    return w[0] + w[1] == w[2];
}