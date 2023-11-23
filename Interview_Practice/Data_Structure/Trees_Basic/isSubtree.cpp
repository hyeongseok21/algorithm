//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
bool areIdentical(Tree<int> * t1, Tree<int> * t2) {
    if (t1 == NULL && t2 == NULL)
        return true;
    if (t1 == NULL || t2 == NULL)
        return false;
    return (t1->value == t2->value && areIdentical(t1->left, t2->left) && areIdentical(t1->right, t2->right));
}

bool solution(Tree<int> *t1, Tree<int> *t2) {
    if (t2 == NULL) return true;
    if (t1 == NULL) return false;
    if (areIdentical(t1, t2))
        return true;
    return solution(t1->left, t2) || solution(t1->right, t2);
}

// bool solution(Tree<int> * t1, Tree<int> * t2) {
//     if(t1 == nullptr) return false;
//     if(t2 == nullptr) return true;
//     if(t1 == NULL && t2 == NULL) return true;
//     if(t1->value != t2->value) {
//         return solution(t1->left, t2) || solution(t1->right, t2);
//     }
//     if(t1->value == t2->value) {
//         return solution(t1->left, t2->left) && solution(t1->right, t2->right);        
//     }
// }