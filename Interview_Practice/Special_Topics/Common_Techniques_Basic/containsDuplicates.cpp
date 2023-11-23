bool solution(vector<int> a) {
    if (a.empty()) return false;
    unordered_set<int> s;
    s.insert(a[0]);
    for(int i = 1; i < a.size(); ++i) {
        if(s.find(a[i]) == s.end()) s.insert(a[i]);
        else return true;
    }
    return false;
}