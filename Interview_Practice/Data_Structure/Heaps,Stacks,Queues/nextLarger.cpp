vector<int> solution(vector<int> a) {
    stack<int> st;
    vector<int> ret;
    
    // store larger element from back
    for(int i = a.size()-1; i >= 0; --i) {
        if (st.empty())
            ret.push_back(-1);
        else if (st.top() > a[i])
            ret.push_back(st.top());
        else {
            while(!st.empty() && st.top() < a[i]) st.pop();
            ret.push_back(st.empty() ? -1 : st.top());
        }
        st.push(a[i]);
    }
    reverse(ret.begin(), ret.end());
    
    return ret;
}