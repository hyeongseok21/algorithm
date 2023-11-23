vector<vector<int>> adj;
void make_graph(int n, vector<vector<int>> tree) {
    adj = vector<vector<int>> (n);
    map<int, int> hash;
    int num = 0;
    hash[tree[0][0]] = num;
    for(int i = 0; i < n-1; ++i) {
        for(int j = 0; j < 2; ++j) {
            if (hash.find(tree[i][j]) == hash.end())
                hash[tree[i][j]] = ++num;
        }
        adj[hash[tree[i][0]]].push_back(hash[tree[i][1]]);
        adj[hash[tree[i][1]]].push_back(hash[tree[i][0]]);
    }
}

int dfsnum = 0;
int maxcount = 0;
int idx = 0;

void dfs(int u, int dfsnum, vector<bool> visited) {
    dfsnum++;
    visited[u] = 1;
    for(int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if (!visited[v]) {
            if (dfsnum > maxcount) {
                maxcount = dfsnum;
                idx = v;
            }
            dfs(v, dfsnum, visited);           
        }
    }
}

int solution(int n, vector<vector<int>> tree) {
    if (tree.empty()) return 0;
    
    make_graph(n, tree);
    vector<bool> visited(n, 0);
    dfs(0, 0, visited);
        
    visited = vector<bool>(n, 0);
    dfs(idx, 0, visited);
    
    return maxcount;
}