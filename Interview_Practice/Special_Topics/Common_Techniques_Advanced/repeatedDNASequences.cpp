// vector<string> solution(string s) {
//     if (s.length() < 11) return {};
    
//     unordered_map<string, int> hash;
    
//     for(int i = 0; i < s.size()-9; ++i) {
//         string cur = s.substr(i, 10);
//         hash[cur]++;
//     }
    
//     vector<string> ret;
//     for (auto it : hash) {
//         if (it.second >= 2) {
//             ret.push_back(it.first);
//         }
//     }
//     sort(ret.begin(), ret.end());
    
//     return ret;
// }

vector<string> solution(string s) {
    if (s.length() < 11) return {};
    set<string> hash_set, result;
        
    string start = s.substr(0, 10);
    hash_set.insert(start);
    for(int i = 1; i < s.length()-9; ++i) {
        string cur = s.substr(i, 10);
        if (hash_set.find(cur) == hash_set.end()) {
            hash_set.insert(cur);
        }
        else {
            result.insert(cur);
        }
    }
    
    vector<string> ret(result.begin(), result.end());
    return ret;
}