string solution(string path) {
    
    string temp;
    stack<string> st;
    stringstream ss(path);
    
    // put string on stack parsed by '/'
    while(getline(ss, temp, '/')) {
        // preventing case 1 & 3, partial case of 2
        if(temp == "" || temp == "." || temp == ".." && st.empty())
            continue;
        // prevent case 2
        if(temp == "..")
            st.pop();
        else
            st.push(temp);
    }
    
    // pop stack and push to array
    vector<string> array;
    while(!st.empty()) {
        array.push_back(st.top());
        st.pop();
    }
    
    // build return string
    string ret = array.empty() ? "/" : "";
    
    // reverse order of array
    reverse(array.begin(), array.end());
    
    for(string t : array) {
        ret += "/" + t;
    }
    return ret;
}