const int INF = 987654321;

// prim's algorithm - assume graphs are all connected

// int solution(int n, vector<vector<int>> wires) {
//     sort(wires.begin(), wires.end());
    
//     // make adjacency list
//     vector<pair<int,int>> adj[n];
//     for(int i = 0; i < wires.size(); ++i) {
//         int u = wires[i][0], v = wires[i][1], weight = wires[i][2];
//         adj[u].push_back(make_pair(v, weight));
//     }
//     // for(int i = 0; i < n; ++i) {
//     //     for (int j = 0; j < adj[i].size(); ++j) {
//     //         cout << i << ' ' << adj[i][j].first << ' ' << adj[i][j].second << ',';
//     //     }
//     //     cout << '\n';
//     // }
        
//     vector<bool> added(n, false);
//     vector<int> minWeight(n, INF), parent(n, -1);
    
//     int ret = 0;
//     minWeight[0] = parent[0] = 0;
    
//     for (int iter = 0; iter < n; ++iter) {
//         // find next node to be added in minimum spanning tree
//         int u = -1;
//         for(int v = 0; v < n; ++v) {
//             if(!added[v] && (u == -1 || minWeight[u] > minWeight[v]))
//                 u = v;
//         }
//         if (minWeight[u] == INF) minWeight[u] = 0;
//         ret += minWeight[u];
//         added[u] = true;
        
//         cout << minWeight[u] << ' ';
        
//         int next = 0;
//         // find edge (u, v) connected to u
//         for(int i = 0; i < adj[u].size(); ++i) {
//             int v = adj[u][i].first, weight = adj[u][i].second;
//             if(!added[v] && minWeight[v] > weight) {
//                 parent[v] = u;
//                 minWeight[v] = weight;
//                 next = v;
//             }
//         }
//         cout << minWeight[next] << '\n';
//     }
//     return ret;    
// }


// kruskal's algorithm

struct DisjointSet {
    vector<int> parent, rank;
    DisjointSet(int n) : parent(n), rank(n, 1) {
        for(int i = 0; i < n; ++i)
            parent[i] = i;
    }
    
    int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    
    void merge(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return;
        if (rank[u] > rank[v]) swap(u, v);
        parent[u] = v;
        if(rank[u] == rank[v]) ++rank[v];
    }
};

int solution(int n, vector<vector<int>> wires) {
    
    // build adjacency list
    vector<pair<int, pair<int, int> > > edges;

    for(int i = 0; i < wires.size(); ++i) {
        int u = wires[i][0], v = wires[i][1], weight = wires[i][2];
        edges.push_back(make_pair(weight, make_pair(u, v)));
    }
    
    sort(edges.begin(), edges.end());
    
    int ret = 0;
    DisjointSet sets(n);
    for(int i = 0; i < edges.size(); ++i) {
        int cost = edges[i].first;
        int u = edges[i].second.first, v = edges[i].second.second;
        
        if(sets.find(u) == sets.find(v)) continue;
        
        sets.merge(u, v);
        ret += cost;
    }
    return ret;
}