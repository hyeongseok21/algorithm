// floyd-warshall algorithm
// : 모든 i에서 j로 가는 경로에 대해, 중간점 k를 경유하는 경로가 더 작을 경우 업데이트
// 한 쌍의 최단 거리는 다익스트라 알고리즘으로 구하고, 모든 쌍의 최단 거리를 구할 땐 플로이드 알고리즘으로 구함

bool solution(vector<vector<double>> exchange) {
    int n = exchange.size();
    
    for (int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                // i통화에서 최종 j통화로 바꾸고 싶을 때, 중간 k통화를 경유해 교환한 것이 더 클 경우, 
                // 큰 값으로 업데이트
                exchange[i][j] = max(exchange[i][j], exchange[i][k] * exchange[k][j]);
            }
        }
    }
    
    // 모든 교환비를 큰 값으로 업데이트 한 결과, 특정 통화를 교환하다 다시 해당 통화로 돌아왔을 때 1보다 커지면 arbitrage가 존재.
    for(int i = 0; i < n; ++i) {
        if (exchange[i][i] > 1) return true;
    }
    return false;
}