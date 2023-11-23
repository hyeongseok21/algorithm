vector<int> solution(vector<int> a) {
    // store greater number and its index in array
    stack<pair<int, int>> st;
    
    vector<int> l, r;
    // store nearest index of greater element on left
    for (int i = 0; i < a.size(); ++i) {
        while(!st.empty() && st.top().first <= a[i]) st.pop();
        l.push_back(st.empty() ? -1 : st.top().second);
        st.push(make_pair(a[i], i));
    }
    while(!st.empty()) st.pop();
    
    // store nearest index of greater element on right
    for (int i = a.size()-1; i >= 0; --i) {
        while(!st.empty() && st.top().first <= a[i]) st.pop();
        r.push_back(st.empty() ? -1: st.top().second);
        st.push(make_pair(a[i], i));
    }
    reverse(r.begin(), r.end());
    
    // compare two index and store nearest one
    vector<int> ret;
    for(int i = 0; i < a.size(); ++i) {
        if (l[i] == -1 && r[i] == -1) ret.push_back(-1);
        else if (l[i] == -1) ret.push_back(r[i]);
        else if (r[i] == -1) ret.push_back(l[i]);
        
        else if (i - l[i] <= r[i] - i) ret.push_back(l[i]);
        else ret.push_back(r[i]);
    }
    return ret;  
}