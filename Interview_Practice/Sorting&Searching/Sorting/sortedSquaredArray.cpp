// sol 1-1. two pointer, initialize return vector, O(n)
vector<int> solution(vector<int> array) {
    vector<int> ret(array.size(), 0);
    int i = 0, j = array.size()-1;
    for(int k = array.size()-1; k >= 0; --k) {
        int n = array[-array[i] > array[j] ? i++ : j--];
        ret[k] = n * n;
    }
    
    return ret;
}


// sol 1-2. two pointer, non-initialization return vector, O(n)
vector<int> solution(vector<int> array) {
    vector<int> ret;
    int i = 0, j = array.size()-1;
    for(int k = 0; k < array.size(); ++k) {
        if(-array[i] > array[j])
            ret.push_back(pow(array[i++], 2));
        else
            ret.push_back(pow(array[j--], 2));
    }
    reverse(ret.begin(), ret.end());
    return ret;
}


// sol 2. in-place sorting solution O(nlgn) but likely O(n)
vector<int> solution(vector<int> array) {
    auto it = lower_bound(array.begin(), array.end(), 0);
    reverse(array.begin(), it);
    transform(array.begin(), array.end(), array.begin(), [](int n) {return n * n;});
    inplace_merge(array.begin(), it, array.end());
    return array;
}


// sol 3. using sort function, O(nlgn)
vector<int> solution(vector<int> array) {
    vector<int> ret;
    for(int i = 0; i < array.size(); ++i) {
        ret.push_back(pow(array[i], 2));
    }
    sort(ret.begin(), ret.end());
    return ret;
}