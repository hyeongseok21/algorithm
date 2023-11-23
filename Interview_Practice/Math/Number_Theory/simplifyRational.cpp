vector<int> solution(int numerator, int denominator) {
    if(gcd(numerator, denominator) == 1) {
        if (denominator < 0) return {-numerator, -denominator};
        else return {numerator, denominator};
    }
    int n = numerator / gcd(numerator, denominator);
    int d = denominator / gcd(numerator, denominator);
    if (d < 0) return {-n, -d};
    else return {n, d};   
}