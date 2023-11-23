//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };

bool isMirror(Tree<int> * t, Tree<int> * s) {
    if(t == NULL && s == NULL) return true;
    if(t == NULL || s == NULL) return false;
    
    if(t->value == s->value) {
        return isMirror(t->left, s->right) && isMirror(t->right, s->left);
    }
    return false;
}

bool solution(Tree<int> * t) {
    return isMirror(t, t);
}

// bool checkSymmetry(Tree<int> *t) {
//     if(t == NULL) return true;
//     Tree<int> *leftSubtree = t->left;
//     Tree<int> *rightSubtree = t->right;
//     if (leftSubtree == NULL && rightSubtree == NULL) return true;
//     if (leftSubtree == NULL || rightSubtree == NULL) return false;
    
//     if(leftSubtree->value == rightSubtree->value)
//         return (checkSymmetry(leftSubtree->left) && checkSymmetry(rightSubtree->right)) && (checkSymmetry(leftSubtree->right) && checkSymmetry(rightSubtree->left));
//     return false;
// }

// bool solution(Tree<int> * t) {
//     if (t == NULL) return true;
//     return checkSymmetry(t);
// }



// using stack
// bool solution(Tree<int> * t) {
//     if(t == NULL) return true;
//     stack<Tree<int> *> stack;
//     stack.push(t->left);
//     stack.push(t->right);
    
//     while(!stack.empty()) {
//         Tree<int> * tree1 = stack.top();
//         stack.pop();
//         Tree<int> * tree2= stack.top();
//         stack.pop();
        
//         if (tree1 == NULL && tree2 == NULL)
//             continue;
//         if (tree1 == NULL || tree2 == NULL)
//             return false;
//         if (tree1->value != tree2->value)
//             return false;
        
//         stack.push(tree1->left);
//         stack.push(tree2->right);
//         stack.push(tree1->right);
//         stack.push(tree2->left);        
//     }
    
//     return true;
    
// // }

// // using queue
// bool solution(Tree<int> * t) {
//     if(t == NULL) return true;
//     queue<Tree<int> *> q;
//     q.push(t->left);
//     q.push(t->right);
    
//     while(!q.empty()) {
//         Tree<int> * tree1 = q.front();
//         q.pop();
//         Tree<int> * tree2= q.front();
//         q.pop();
        
//         if (tree1 == NULL && tree2 == NULL)
//             continue;
//         if (tree1 == NULL || tree2 == NULL)
//             return false;
//         if (tree1->value != tree2->value)
//             return false;
        
//         q.push(tree1->left);
//         q.push(tree2->right);
//         q.push(tree1->right);
//         q.push(tree2->left);        
//     }
    
//     return true;
// }