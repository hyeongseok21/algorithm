string solution(string s, string t) {
    vector<int> s_alpha(26, 0);
    for(int i = 0; i < s.length(); ++i) {
        s_alpha[s[i] - 'a']++;
    }
    
    string ret = "";
    for(int i = 0; i < t.length(); ++i) {
        int idx = t[i] - 'a';
        while (s_alpha[idx] > 0) {
            ret += t[i];
            s_alpha[idx]--;
        }
    }
    return ret;
}