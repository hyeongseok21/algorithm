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
    if (t == nullptr) return ret;
    queue<Tree<int> *> q;
    q.push(t);
    while(!q.empty()) {
        Tree<int> *t = q.front();
        ret.push_back(t->value);
        q.pop();
        if (t->left) q.push(t->left);
        if (t->right) q.push(t->right);
    }
    
    return ret;
}