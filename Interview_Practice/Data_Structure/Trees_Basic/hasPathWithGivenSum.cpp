//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
// bool solution(Tree<int> * t, int s) {
//     if(t == NULL) return s == 0;
//     s -= t->value;
//     if (s == 0 && t->left == NULL && t->right == NULL)
//         return true;
//     if (t->left == NULL)
//         return solution(t->right, s);
//     if (t->right == NULL)
//         return solution(t->left, s);
    
//     return solution(t->left, s) || solution(t->right, s);
// }

bool solution(Tree<int> * t, int s) {
    if(t == NULL) return s == 0;
    int subSum = s - t->value;
    
    if (subSum == 0 && t->left == NULL && t->right == NULL)
        return true;
    if (t->left == NULL)
        return solution(t->right, subSum);
    if (t->right == NULL)
        return solution(t->left, subSum);
    
    return solution(t->left, subSum) || solution(t->right, subSum);
}