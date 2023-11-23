// cycle check problem

vector<bool> visited, currentlyInStack;

bool dfs(vector<vector<int>> graph, int index) {
    if(currentlyInStack[index]) return true;
    if(visited[index]) return false;
    
    currentlyInStack[index] = true;
    visited[index] = true;
    
    for (auto curIndex : graph[index]) {
        bool isCycleExists = dfs(graph, curIndex);
        if (isCycleExists) return true;
    }

    // if dfs is still exploring, visited nodes are all in currentlyInStack
    currentlyInStack[index] = false;
    return false;
}

bool solution(vector<vector<int>> connections) {
    visited = vector<bool>(connections.size(), false);
    currentlyInStack = vector<bool>(connections.size(), false);
    
    for (int i = 0; i < connections.size(); ++i) {
        if(visited[i]) continue;
        bool isCycleExists = dfs(connections, i);
        if(isCycleExists) return true;
    }
    
    return false;
}