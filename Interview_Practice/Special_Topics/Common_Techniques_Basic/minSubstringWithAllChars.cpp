string solution(string s, string t) {
    // if (t.length() > s.length()) return "";
    
    for(int win = t.length(); win <= s.length(); ++win) {
        cout << win << '\n';
        for(int pos = 0; pos <= s.length()-win; ++pos) {
            bool found = true;
            string tmp = s.substr(pos, win);
            for(char a : t) {
                if(tmp.find(a) == string::npos) {
                    found = false;
                    break;
                }
            }
            if (found) return tmp;
        }
    }
    return "";
}