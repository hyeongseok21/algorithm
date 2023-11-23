string solution(string s) {
    string ret = "";
    ret += tolower(s[0]);
    for(int i = 1; i < s.length(); ++i) {
        if (islower(s[i])) ret += s[i];
        else {
            ret = ret + " ";
            ret += tolower(s[i]);
        }
    }
    return ret;
}