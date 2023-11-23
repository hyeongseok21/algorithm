// use dijkstra algorithm
// priority queue와 bfs를 이용해, source - dest 사이 최단 거리를 구하는 알고리즘

// 세 개의 data를 저장하는데, pair로 선언할 경우 pair<int, pair<int, int>>와 같이 복잡해져서 datatype을 새로 정의
// priority queue에 넣는 연산 O(lgE),E개 원소에 대해 진행되므로 O(ElgE), 대개 E가 V^2보다 작아 O(lgE) ~ O(lgV)
// 따라서 시간복잡도는 O(ElgV) -> O(mlgn)

struct Data{
    int v, t_depart, t_arrive;
    Data(int _v, int _t_depart, int _t_arrive) {
        v = _v;
        t_depart = _t_depart;
        t_arrive = _t_arrive;
    }
    
    Data(int _v, int _t_arrive) {
        v = _v;
        t_arrive = _t_arrive;
    }
    
    Data() {
        
    }
    
    // priority queue에서 data간 대소 비교할 때 사용
    bool operator <(const Data &d)const{
        return t_arrive > d.t_arrive;
    }
};

// string time을 int로 변환. 값을 graph에 저장할 때 사용
int StrtoInt(string &t) {
    int h = (t[0] - '0') * 10 + (t[1] - '0');
    int m = (t[3] - '0') * 10 + (t[4] - '0');
    return h * 60 + m;
}

// int time을 str으로 변환. 최종 값을 반환할 때 사용
string InttoStr(int &t) {
    int h = t/60, m = t % 60;
    string hh = "", mm = "";
    if(h < 10) hh = "0";
    if(m < 10) mm = "0";
    hh += to_string(h);
    mm += to_string(m);
    return hh + ":" + mm;
}

vector<vector<Data> > adj;

pair<int, int> create_graph(vector<vector<string> > &times, string source, string dest) {
    int V = 0;
    map<string, int> hash;
    // source, dest index 초기화
    hash[source] = hash[dest] = 0;
    
    // times를 순회하며 각 location에 대응되는 index 매핑. 중복 제거를 위해 map사용
    for(int i = 0; i < times.size(); ++i) {
        string su = times[i][0], sv = times[i][1];
        // 처음엔 value를 0으로 초기화하고,
        hash[su] = hash[sv] = 0;
    }
    for(auto &it : hash) {
        // 앞에서부터 1씩 증가시키며 index 매핑
        it.second = V++;
    }
    
    // Data들로 이루어진 adjcency list 그래프 생성
    adj = vector<vector<Data> >(V+1);
    
    // times를 순회하며 source location에서 출발하는 정보가 담긴 graph 생성
    for(int i = 0; i < times.size(); ++i) {
        string su = times[i][0], sv = times[i][1];
        // hash에 매핑된 str의 index 반환
        int u = hash[su], v = hash[sv];
        // source idx마다 dest idx, t_depart, t_arrive로 이루어진 list 생성
        adj[u].push_back(Data(v, StrtoInt(times[i][2]), StrtoInt(times[i][3])));
    }
    
    // source idx와 dest idx의 pair 반환
    return make_pair(hash[source], hash[dest]);
}

#define INF 1<<30
string dijkstra(int start, int end) {
    priority_queue<Data> pq;
    int V = adj.size();
    
    // start loc에서 갈 수 있는 loc들을 pq에 넣음. t_arrive가 작은 loc가 가장 위에 옴
    for(int i = 0; i < adj[start].size(); ++i) {
        int v = adj[start][i].v, t_arrive = adj[start][i].t_arrive;
        pq.push(Data(v, t_arrive));
    }
    
    // dijkstra 알고리즘. source loc에서 bfs를 수행하며 짧은 arrive time을 가진 loc을 탐색
    while(!pq.empty()) {
        // arrive time이 작은 순서대로 loc이 pq에서 꺼내짐.
        Data cur = pq.top(); pq.pop();
        int u = cur.v, t_depart = cur.t_arrive + 60; // 다음 출발까지 60분이 필요하므로 꺼내진 노드의 도착 시간에서 60을 더한 값을 t_depart로 설정
        // 꺼내진 노드의 loc이 dest일 경우, 해당 노드의 t_arrive를 반환. t_arrive가 짧은 순서대로 선택하여 왔으므로 해당 t_arrive가 최소임이 정당함.
        if(u == end) {
            return InttoStr(cur.t_arrive);
        }
        // 꺼내진 loc에서 인접한 노드를 탐색. 출발 시간이 t_depart 이후인 loc들을 pq에 넣음
        for(int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].v, tv_depart = adj[u][i].t_depart;
            int tv_arrive = adj[u][i].t_arrive;
            if(tv_depart >= t_depart) {
                pq.push(Data(v, tv_arrive));
            }
        }
    }
    // 경로가 없으면 -1 반환
    return "-1";
}

string solution(vector<vector<string>> times, string source, string dest) {
    pair<int, int> ids = create_graph(times, source, dest);
    return dijkstra(ids.first, ids.second);
}