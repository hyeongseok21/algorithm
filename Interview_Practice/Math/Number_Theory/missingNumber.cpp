int solution(vector<int> arr) {
    if (arr.size() == 1 && arr[0] == 0) return 1;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size(); ++i) {
        if (i != arr[i]) return i;
    }
    return arr.size();
}