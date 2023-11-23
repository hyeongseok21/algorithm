char solution(string s) {
    vector<int> alpha(26, 0);
    vector<char> cand;
    priority_queue<int, vector<int>, greater<int>> index;
    for(int i = 0; i < s.length(); ++i) {
        alpha[s[i] - 'a']++;
    }
    // for(int i = 0; i < alpha.size(); ++i)
    //     cout << alpha[i];
    // cout << '\n';
    for(int i = 0; i < alpha.size(); ++i) {
        if(alpha[i] == 1)
            cand.push_back((char)(i+'a'));
    }
    // for(int i = 0; i < cand.size(); ++i)
    //     cout << cand[i];
    if(cand.empty()) return '_';
    cout << '\n';
    for(int i = 0; i < cand.size(); ++i) {
        for(int j = 0; j < s.length(); ++j) {
            if(s[j] == cand[i]) {
                index.push(j);
                break;
            }
        }
    }
    return s[index.top()];
}