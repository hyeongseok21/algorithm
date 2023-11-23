//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
Tree<int> * solution(vector<int> inorder, vector<int> preorder) {
    if(inorder.empty()) return nullptr;
    
    Tree<int> * ret = new Tree<int>(preorder[0]);
    int idx = 0;
    while(inorder[idx] != preorder[0]) ++idx;
    
    // preorder 맨 앞 원소를 삭제
    preorder.erase(preorder.begin());
    ret->left = solution(vector<int>(inorder.begin(), inorder.begin() + idx),
                        vector<int>(preorder.begin(), preorder.begin() + idx));
    ret->right = solution(vector<int>(inorder.begin() + idx + 1, inorder.end()), 
                        vector<int>(preorder.begin()+idx, preorder.end()));
    
    // preorder 맨 앞 원소를 삭제하지 않을 경우
    // ret->left = solution(vector<int>(inorder.begin(), inorder.begin() + idx),
    //                     vector<int>(preorder.begin() + 1, preorder.begin() + idx + 1));
    // ret->right = solution(vector<int>(inorder.begin() + idx + 1, inorder.end()), 
    //                     vector<int>(preorder.begin()+idx+1, preorder.end()));
    
    
    return ret;
}