// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
bool solution(ListNode<int> * l) {
    if (l == nullptr)
        return true;
    stack<int> st;
    for(ListNode<int> *currentNode = l; currentNode != nullptr; 
                                        currentNode = currentNode->next) {
        st.push(currentNode->value);
    }
    for(ListNode<int> *currentNode = l; currentNode != nullptr;
                                        currentNode = currentNode->next) {
        if(currentNode->value != st.top())
            return false;
        st.pop();                      
    }
    return true;
}