// 1. 숫자가 연속될 경우
// 2. 알파벳이 연속될 경우
// 3. 숫자 다음 [ 일 경우
// 4. [a..[ 일 경우


string solution(string s) {
    stack<string> chars;
    stack<int> nums;
    int num = 0;
    string res = "";
    
    for(char c : s) {
        if (isdigit(c)) {
            num = num * 10 + (c-'0');
        }
        if (isalpha(c)) {
            res += c;
        }
        if (c == '[') {
            nums.push(num);
            num = 0;
            chars.push(res);
            res = "";
        }
        else if (c == ']') {
            string temp = res;
            for(int i = 1; i < nums.top(); ++i) {
                res += temp;
            }
            res = chars.top() + res;
            chars.pop(); nums.pop();
        }
    }
    return res;
}