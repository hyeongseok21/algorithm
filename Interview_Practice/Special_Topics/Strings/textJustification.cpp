vector<string> solution(vector<string> words, int l) {
    
    vector<string> ret, line;
    string sentence = "";
    int len = 0;
        
    for(int i = 0; i < words.size(); ++i) {
        if (len + line.size() + words[i].length() > l) {
            
            int denom = line.size()-1 > 0 ? line.size()-1 : 1;
            int space = (l - len) / denom;
            int res = (l - len) % denom;
            
            for(int j = 0; j < denom; ++j) {
                line[j].append(space, ' ');
                if (res) {
                    line[j] = line[j] + " ";
                    res -= 1;
                }
            }
            
            for(int k = 0; k < line.size(); ++k) {
                sentence.append(line[k]);
            }
            
            ret.push_back(sentence);
            line.clear();
            len = 0;
            sentence = "";
        }
        
        len += words[i].length();
        line.push_back(words[i]);
    }
    
    sentence = "";
    for(int i = 0; i < line.size(); ++i) {
        if (i == line.size()-1) sentence.append(line[i]);
        else {
            sentence.append(line[i]);
            sentence.append(" ");
        }
    }
    
    int space = l - sentence.length();
    sentence.append(string(space, ' '));
    ret.push_back(sentence);

    return ret;
}


    // res = []
    // line, length = [], 0
    // i = 0
    
    // while (i < len(words)):
    //     if (length + len(line) + len(words[i]) > l):
    //         extra_space = l - length
    //         spaces = extra_space // max(1, len(line) - 1)
    //         remainder = extra_space % max(1, len(line) -1)
            
    //         for j in range(max(1, len(line) - 1)):
    //             line[j] += " " * spaces
    //             if remainder:
    //                 line[j] += " "
    //                 remainder -= 1
    //         res.append("".join(line))
    //         line, length = [], 0
        
    //     line.append(words[i])
    //     length += len(words[i])
    //     i += 1
    
    // last_line = " ".join(line)
    // trail_space = l - len(last_line)
    // res.append(last_line + " " * trail_space)
    // return res