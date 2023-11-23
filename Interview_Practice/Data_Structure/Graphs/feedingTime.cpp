// same as m-coloring problem,
// cause if the same element(animal) exists on other list(class), the list should be assigned to different day


// build integer adjacency list graph, consist of index of linked nodes for each node
// if an element in ith list(node) is also in jth list(node), there's a path from i to j
vector<vector<int>> adj;
void create_graph(vector<vector<string>> &classes) {
    int n = classes.size();
    adj = vector<vector<int> > (n);
    unordered_set<string> hash;
    for(int i = 0; i < n; ++i) {
        hash.clear();
        // make a set containing unduplicated elements of ith list
        for(int j = 0; j < classes[i].size(); ++j) {
            hash.insert(classes[i][j]);
        }
        // iterate from next node to the end. cause the path related to previous node is already written on adjacency list graph
        for(int j = i + 1; j < n; ++j) {
            bool exists = false;
            for(int k = 0; k < classes[j].size(); ++k) {
                if(hash.find(classes[j][k]) != hash.end()) {
                    exists = true;
                    break;
                }
            }
            if (exists) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
}

#define INF 1<<30
vector<int> color;

// check if there is a node colored with given colorID 
bool checkColor(int u, int colorID) {
    for(int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if (color[v] == colorID)
            return true;
    }
    return false;
}

int dfs(int maxColor, int node, int V) {
    if (node == V) return maxColor;
    
    int minimum = INF;
    if(color[node] == -1) {
        for(int i = 1; i <= 5; ++i) {
            if (checkColor(node, i)) continue;
            color[node] = i;
            int res = dfs(max(maxColor, i), node+1, V);
            minimum = min(minimum, res);
            color[node] = -1;
        }
    }
    return minimum;
}

int graph_coloring(int V) {
    color = vector<int>(V, -1);
    int minimum = dfs(-1, 0, V);
    if (minimum == INF) minimum = -1;
    return minimum;    
}

int solution(vector<vector<string>> classes) {
    create_graph(classes);
    return graph_coloring(classes.size());
}