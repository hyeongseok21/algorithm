//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
int count = 0;
int solution(Tree<int> * t, int k) {
    stack<Tree<int> *> st;
    
    // traverse preorder, find smallest number and reduce k one by one
    while(true) {
        while(t != NULL) {
            st.push(t);
            t = t->left;
        }
        t = st.top();
        st.pop();
        k--;
        if (k == 0)
            return t->value;
        t = t->right;
    }
}