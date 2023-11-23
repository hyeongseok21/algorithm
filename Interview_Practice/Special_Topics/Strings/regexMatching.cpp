bool solution(string pattern, string test) {
    int plen = pattern.length(), tlen = test.length();
    if (plen == tlen) return pattern == test;
    
    if (pattern[0] == '^')
    {
        pattern = pattern.substr(1);
        return test.substr(0, pattern.size()) == pattern;
    }
    
    else if (pattern[plen-1] == '$')
    {
        pattern = pattern.substr(0, pattern.length()-1);
        return test.substr(test.size() - pattern.size()) == pattern;
    }
    
    else {
        return test.find(pattern) != string::npos;
    }
}
