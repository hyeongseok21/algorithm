// cut-edge(bridge) counting problem

int dfsNum = 0; // dfs 호출 횟수
int bridges = 0; // bridge 개수
vector<int> low; // 각 노드의 방문 순서 중 최소값을 저장
vector<int> seen; // 각 노드의 방문 순서. dfs 호출 횟수와 동일 

// 역방향 간선의 존재여부를 판별하고, 없는 노드의 수를 count
void dfs(vector<vector<int>> &adj, int u, int p = -1) {
    low[u] = seen[u] = dfsNum++;
    int V = adj.size();
    for(int v = 0; v < V; ++v) {
        if(adj[u][v] && v != p) {
            if (seen[v] == -1) { // v가 아직 방문되지 않은 노드라면 v는 u의 하위.
                dfs(adj, v, u); // v에서 u로 역방향 dfs를 수행해 u의 상위 노드로 향하는 간선이 있는지 확인 
                low[u] = min(low[u], low[v]); // u의 깊이를 u, v 둘 중 최소값으로 업데이트
                
                // v의 깊이가 방문 순서와 동일하다면, 역방향 경로가 없다는 뜻이므로 해당 간선이 bridge에 해당
                if (low[v] == seen[v]) bridges++; 
                
            } else {
                // v가 방문된 노드라면 u는 v의 하위. low[u]를 u의 깊이와 v의 방문 순서중 더 작은 값으로 업데이트
                low[u] = min( low[u], seen[v] );
            }
        }
    }
}

int solution(vector<vector<int>> connections) {
    int V = connections.size();
    low = vector<int>(V, -1);
    seen = vector<int>(V, -1);
    dfs(connections, 0);
    return bridges;
}