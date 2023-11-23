int solution(vector<int> a) {
    set<int> num;
    for(int i = 0; i < a.size(); ++i) {
        if (num.find(a[i]) == num.end()) {
            num.insert(a[i]);
        }
        else
            return a[i];
    }
    return -1;
}