vector<int> solution(vector<string> operations) {
    vector<int> ret;
    stack<int> st;
    string res = "";
    for(int i = 0; i < operations.size(); ++i) {
        stringstream ss(operations[i]);
        string op; ss >> op;
        if (op == "min") {
            ret.push_back(st.top());
        } else if (op == "push") {
            int val; ss >> val;
            if (st.empty()) st.push(val);
            else st.push(min(val, st.top()));
        } else if (op == "pop")
            st.pop();
    }
    return ret;
}