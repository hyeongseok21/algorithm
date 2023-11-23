int solution(string fileSystem) {
    vector<string> folder;
    string temp;
    stringstream ss(fileSystem);
    
    while(getline(ss, temp, '\f')) {
        folder.push_back(temp);
    }
    
    map<int, int> pathdict;
    pathdict[0] = 0;
    int maxlen = 0;
    for(auto file : folder) {
        int depth = count(file.begin(), file.end(), '\t');
        int namelen = file.length() - depth;
        if (file.find('.') == string::npos) {
            pathdict[depth+1] = pathdict[depth] + namelen + 1;
        }
        else
            maxlen = max(maxlen, pathdict[depth] + namelen);
    }
    return maxlen;
}