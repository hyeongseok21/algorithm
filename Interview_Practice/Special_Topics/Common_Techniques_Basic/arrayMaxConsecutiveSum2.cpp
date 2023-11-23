int solution(vector<int> inputArray) {
    int n = inputArray.size();
    vector<int> maxconsum(n);
    int maxsum = INT_MIN;
    for(int i = 0; i < inputArray.size(); ++i) {
        if (i == 0) maxconsum[i] = inputArray[i];
        else {
            maxconsum[i] = max(maxconsum[i-1] + inputArray[i], inputArray[i]);
            maxsum = max(maxsum, maxconsum[i]);
        }
    }
    
    for(int i = 0; i < n; ++i) {
        cout << maxconsum[i] << ' ';
    }

    return maxsum;
}