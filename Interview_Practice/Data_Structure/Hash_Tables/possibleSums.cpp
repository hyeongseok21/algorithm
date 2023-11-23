// int solution(vector<int> coins, vector<int> quantity) {
//     set<int> sum;
//     sum.insert(0);
//     for(int i = 0; i < quantity.size(); i++) {
//         auto p = sum;
//         for (int k : p) {
//             for(int f = 1; f <= quantity[i]; f++) {
//                 sum.insert(k + f*coins[i]);
//             }
//         }
//     }
//     return sum.size()-1;
// }

void bt(vector <int> &c, vector <int> &q, unordered_set <int> &sums, int idx, int sum) {
    if (idx == c.size()) {
        if (sum) sums.insert(sum);
        return;
    }
    
    for (int i = 0; i <= q[idx]; ++i) {
        bt(c, q, sums, idx + 1, sum + c[idx] * i);
    }
}

int solution(vector<int> coins, vector<int> quantity) {
    unordered_set <int> sums;
    bt(coins, quantity, sums, 0, 0);
    return sums.size();
}