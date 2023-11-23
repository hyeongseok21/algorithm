//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };


vector<long long> ret(2000, 0);
void backtrack(Tree<int> *t, long long n) {
    n = (n * 10) + t->value;
    
    if (t->left == NULL && t->right == NULL) {
        ret.push_back(n);
    }
    
    if (t->left) backtrack(t->left, n);
    if (t->right) backtrack(t->right, n);
}

long long solution(Tree<int> * t) {
    if(!t) return 0;
    backtrack(t, 0);
    long long sum = 0;
    for(int i = 0; i < ret.size(); ++i) {
        sum += ret[i];
    }
    return sum;
}