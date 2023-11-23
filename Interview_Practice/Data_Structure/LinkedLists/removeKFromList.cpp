// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//

ListNode<int> * solution(ListNode<int> * l, int k) {
    
    ListNode<int> **previousNodesNext = &l;
    
    for(ListNode<int> *currentNode = l; currentNode != nullptr; 
                                        currentNode = currentNode -> next)
    {
        if(currentNode -> value == k)
            *previousNodesNext = currentNode -> next;
        else {
            previousNodesNext = &currentNode -> next;
        }
    }
    return l;
}

// ListNode<int> * solution(ListNode<int> * l, int k) {
//     if (l == nullptr) return nullptr;
//     l->next = solution(l->next, k);
//     if (l->value == k) return l->next;
//     return l;
// }