// string solution(string s) {
//     set<char> v;
//     v.insert('a'), v.insert('e'), v.insert('i'), v.insert('o'), v.insert('u');
    
//     int count = 0;
//     bool vfound = false, qfound = false;
//     for(int i = 0; i < s.length(); ++i) {
//         char c = s[i];
//         if (v.find(c) != v.end()) {
//             if(vfound) {
//                 count++;
//                 if(count == 3)
//                     return qfound ? "mixed" : "bad";                
//             }
//             else {
//                 if(i > 0 && s[i-1] == '?') {
//                     qfound = true;
//                     count++;
//                 }
//                 else {
//                     qfound = false;
//                     count = 1;
//                 }
//             }
//             vfound = true;
//         }
//         else if (c != '?') {
//             if(!vfound) {
//                 count++;
//                 if(count == 5)
//                     return qfound ? "mixed" : "bad";
//             }
//             else {
//                 qfound = false;
//                 count = 1;
//             }
//             vfound = false;
//         }
//         else {
//             if(( (vfound || qfound) && count == 2) || ( (!vfound || qfound) && count == 4) )
//                 return "mixed";
//             count++, qfound = true;
//         }
//         cout << c << ' ' << count << '\n';
//     }
//     return "good";
// }

unordered_set<char> vowels{'a','e','i','o','u'};

string solution(string s) {
    size_t pos = s.find('?');
    regex pattern("([aeiou]*{3}|[^aeiou]*{5})");
    if (pos == string::npos) {
        if (regex_match(s, pattern)) return "bad";
        else return "good";
    }
    // size_t pos = s.find('?');
    // if(pos==string::npos) {
    //     int v=0,c=0;
    //     for(char chr: s) {
    //         if(vowels.count(chr))
    //             ++v,c=0;
    //         else
    //             ++c,v=0;
            
    //         if(v==3 || c==5)
    //             return "bad";
    //     }
    //     return "good";
    // }
    
    s[pos]='a';
    string r1=solution(s);
    s[pos]='z';
    string r2=solution(s);
    
    if(r1=="good" && r2=="good") return "good";
    if(r1=="bad" && r2=="bad") return "bad";
    
    return "mixed";
}

// string solution(string s) {
//     regex bad(".*([aeiou]{3}|[^aeiou\\?]{5}).*");
//     if (regex_match(s,bad))
//         return "bad";
//     regex mixed(".*([aeiou\\?]{3}|[^aeiou]{5}).*");
//     if (regex_match(s,mixed))
//         return "mixed";
//     return "good";
// }