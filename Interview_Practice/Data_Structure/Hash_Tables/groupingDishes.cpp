vector<vector<string>> solution(vector<vector<string>> dishes) {
    map<string, vector<string>> m;
    
    for(int i = 0; i < dishes.size(); ++i) {
        vector<string> v = dishes[i];
        for(int j = 1; j < v.size(); ++j) {
            if(m.find(v[j]) == m.end()) {
                vector<string> s;
                s.push_back(v[0]);
                m[v[j]] = s;
            }
            else
                m[v[j]].push_back(v[0]);
        }
    }
    
    vector<vector<string>> result;
    for(auto ele : m) {
        vector<string> v = ele.second;
        sort(v.begin(), v.end());
        v.insert(v.begin(), ele.first);
        if(v.size() > 2) result.push_back(v);
    }
    
    return result;
}