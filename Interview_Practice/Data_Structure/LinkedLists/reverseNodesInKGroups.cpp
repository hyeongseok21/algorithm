// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//

ListNode<int> * reverseOneGroup(ListNode<int> * pre, ListNode<int> * next) {
    ListNode<int> * begin = pre;
    ListNode<int> * cur = begin->next;
    ListNode<int> * first = cur;
    while(cur != next) {
        ListNode<int> * next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    begin->next = pre;
    first->next = cur;
    return first;
}

ListNode<int> * solution(ListNode<int> * head, int k) {
    if (!head || k == 1) return head;
    ListNode<int> *dummy = new ListNode<int>(-1);
    ListNode<int> *pre = dummy, *cur = head;
    dummy->next = head;
    int i = 0;
    while (cur) {
        ++i;
        if (i % k == 0) {
            pre = reverseOneGroup(pre, cur->next);
            cur = pre->next;
        } else {
            cur = cur->next;
        }
    }
    return dummy->next;
}



// ListNode<int> * solution(ListNode<int> * l, int k) {
//     stack<int> st;
//     ListNode<int> * currentNode = l;
//     for(ListNode<int> * currentNode; currentNode != nullptr; currentNode = currentNode -> next) {
//         int i = k;
//         while (i > 0) {
//             st.push(currentNode -> value);
//             currentNode = currentNode -> next;
//             i--;
//             cout << i;
//         }
//         while (!st.empty()) {
//             if(currentNode -> next != nullptr) {
//                 currentNode -> value = st.top();
//                 st.pop();
//                 currentNode = currentNode -> next;
//             }
//             else {
//                 ListNode<int> * newNode;
//                 newNode = (struct ListNode<int>*)malloc(sizeof(struct ListNode<int>));
//                 currentNode -> next = newNode;
//                 newNode -> next = nullptr;
//                 currentNode -> value = st.top();
//                 st.pop();
//                 if(st.empty()) {
//                     currentNode -> next = nullptr;
//                 }
//                 currentNode = currentNode -> next;
//             }
//         }
//         cout << currentNode->value;
//     }
//     return currentNode;
// }