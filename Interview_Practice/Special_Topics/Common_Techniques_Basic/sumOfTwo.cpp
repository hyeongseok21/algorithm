bool solution(vector<int> a, vector<int> b, int v) {
    unordered_set<int> s(b.begin(), b.end());
    for(int i = 0; i < a.size(); ++i) {
        if (s.find(v-a[i]) != s.end()) return true;
    }
    return false;
}