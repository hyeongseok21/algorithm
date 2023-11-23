//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
vector<int> solution(Tree<int> * t) {
    vector<int> ret;
    if (t==NULL) return ret;
    int maxval, n;
    queue<Tree<int> *> q;
    q.push(t);
    while(!q.empty()) {
        n = q.size();
        maxval = INT_MIN;
        while(n > 0) {
            Tree<int> *node = q.front(); q.pop();
            maxval = max(maxval, node->value);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            n--;
        }
        ret.push_back(maxval);
    }
    return ret;
}