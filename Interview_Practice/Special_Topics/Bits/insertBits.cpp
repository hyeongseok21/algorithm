// int solution(int n, int a, int b, int k) {
//     int mask = 0;
//     for( int i = a ; i <= b ; ++i ){
//         mask |= 1<<i;
//     }
//     return (n & ~mask) | ((k << a) & mask);
// }

int solution(int n, int a, int b, int k) {
    int mask = pow(2, (b-a+1))-1;
    mask = ~(mask<<a);
    return (n & mask) | k << a;
}