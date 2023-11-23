string solution(int level, int pos) {
    if(level == 1)
        return "Engineer";
    if(solution(level-1, (pos+1)/2) == "Engineer") {
        if(pos % 2 == 0)
            return "Doctor";
        if(pos % 2 == 1)
            return "Engineer";
    }
    if(pos % 2 == 0)
        return "Engineer";
    if(pos % 2 == 1)
        return "Doctor";        
}