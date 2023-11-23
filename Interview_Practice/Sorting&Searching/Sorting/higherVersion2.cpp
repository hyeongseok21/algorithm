int solution(string ver1, string ver2) {
    string temp1, temp2;
    stringstream ss1(ver1), ss2(ver2);
    vector<int> a1, a2;
    
    while(getline(ss1, temp1, '.')) {
        a1.push_back(stoi(temp1));
    }
    while(getline(ss2, temp2, '.')) {
        a2.push_back((stoi(temp2)));
    }
    
    for(int i = 0; i < a1.size(); ++i) {
        int a = a1[i] - a2[i];
        if(a < 0) return -1;
        else if (a > 0) return 1;
    }
    return 0;  
}