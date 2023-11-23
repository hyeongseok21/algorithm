// sol1. naive approach, 24/27, time out error
// int solution(string s, string x) {
//     int n = x.length(), m = s.length();
//     if (n > m) return -1;
//     if (n == 0) return 0;
//     if (n == m) {
//         if (s[0] != x[0]) return -1;
//     }
    
//     for(int begin = 0; begin < s.length()-x.length()+1; ++begin) {
//         bool matched = true;
//         for(int i = 0; i < x.length(); i++) {
//             if(x[i] != s[begin+i]) {
//                 matched = false;
//                 break;
//             }
//         }
//         if (matched) return begin;
//     }
//     return -1;
    
//     // int index = s.find(x);
//     // if (index != string::npos) return index;
//     // else return -1;
// }

int solution(string s, string x) {
    int n = s.length(), m = x.length();
    if (m > n || s.empty() || x.empty()) return -1;
    if (n == m && s[0] != x[0]) return -1;
    if (n == m == 1) return s[0] == x[0] ? 0 : -1;
    
    int begin = 1, match = 0;
    while(begin <= n-m) {
        if(match < m && s[begin+match] == x[match]) {
            ++match;
            if (match == m) return begin;
        } 
        else {
            if (match == 0) ++begin;
            else {
                begin = begin + match;
                match = 0;
            }
        }
    }
    return -1;
}