const int mod = 1000000007;

int solution(vector<int> a) {
    vector<int> aux;
    long long cnt = 0;
    for(int i = a.size()-1; i >= 0; --i) {
        auto it = lower_bound(aux.begin(), aux.end(), a[i]);
        cnt += (it - aux.begin());
        aux.insert(it, a[i]);
    }
    return cnt % mod;
}