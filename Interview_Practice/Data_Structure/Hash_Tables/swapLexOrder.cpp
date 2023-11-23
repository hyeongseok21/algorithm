// string solution(string str, vector<vector<int>> pairs) {
//     set<string, greater<string>> dict;
//     dict.insert(str);
//     while(dict.find(str) != dict.end()) {
//        for(int i = 0; i < pairs.size(); ++i) {
//             swap(str[pairs[i][0]-1], str[pairs[i][1]-1]);
//             if (dict.find(str) != dict.end())
//                 dict.insert(str);
//         } 
//     }
//     for(set<string>::iterator iter = dict.begin(); iter != dict.end(); iter++) {
//         cout << *iter << " ";
//     }
    
//     return *dict.begin();
// }


//using dfs
void dfs(vector <vector <int>> &adj, vector <bool> &vis, int node, vector <int> &idxs) {
    if (vis[node]) return;
    vis[node] = 1;
    
    idxs.push_back(node);
    
    for (int i = 0; i < adj[node].size(); ++i) {
        dfs(adj, vis, adj[node][i], idxs);
    }
}

string solution(string str, vector<vector<int>> pairs) {
    vector <vector <int>> adj(str.size(), vector <int> ());
    for (int i = 0; i < pairs.size(); ++i) {
        adj[pairs[i][0] - 1].push_back(pairs[i][1] - 1);
        adj[pairs[i][1] - 1].push_back(pairs[i][0] - 1);
    }
    
    string ret = str;
    
    vector <bool> vis(str.size());
    for (int i = 0; i < str.size(); ++i) {
        if (!vis[i]) {
            vector <int> idxs;
            dfs(adj, vis, i, idxs);
            vector <char> chrs;
            for (int i = 0; i < idxs.size(); ++i) {
                chrs.push_back(str[idxs[i]]);
            }
            sort(idxs.begin(), idxs.end());
            sort(chrs.begin(), chrs.end());
            for (int i = 0; i < chrs.size(); ++i) {
                ret[idxs[i]] = chrs[chrs.size() - 1 - i];
            }
        }
    }
    
    return ret;
}


// using union-find
int root(int u, vector<int>& parent) {
    if (parent[u] < 0) return u;
    return parent[u] = root(parent[u], parent);
}

void unite(int u, int v, vector<int>& parent) {
    if (parent[u] > parent[v]) swap(u, v);
    parent[u] += parent[v];
    parent[v] = u;
}

string solution(string str, vector<vector<int> > pairs) {
    vector<int> parent(str.length());
    for (int i = 0; i < str.length(); i++)
        parent[i] = -1;

    for (int i = 0; i < pairs.size(); i++) {
        int u = pairs[i][0] - 1, v = pairs[i][1] - 1;
        u = root(u, parent), v = root(v, parent);
        if (u != v) unite(u, v, parent);
    }

    multiset<char> S[str.length()];
    for (int i = 0; i < str.length(); i++) {
        int u = root(i, parent);

        S[u].insert(str[i]);
    }

    for (int i = 0; i < str.length(); i++) {
        int u = root(i, parent);

        str[i] = *S[u].rbegin();
        S[u].erase(--S[u].end());
    }

    return str;
}