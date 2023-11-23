bool solution(vector<string> strings, vector<string> patterns) {
    if(strings.size() != patterns.size()) return false;    
    
    for (int i = 0; i < strings.size(); ++i) {
        for (int j = i+1; j < strings.size(); ++j) {
            if ( (strings[i] == strings[j] && patterns[i] != patterns[j]) || 
                 (strings[i] != strings[j] && patterns[i] == patterns[j]) )
                 return false;
        }
    }
    return true;
}
