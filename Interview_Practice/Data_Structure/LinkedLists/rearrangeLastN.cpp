// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * solution(ListNode<int> * l, int n) {
    ListNode<int> *first, *last;
    
    // store start point in dummy next
    ListNode<int> *dummy = new ListNode<int>(-1);
    dummy->next = l;
    
    first = dummy, last = dummy;
    
    // store first, last pointer with distance n
    for(int i = 0; i < n; ++i)
        last = last->next;
    while(last->next) {
        first = first->next;
        last = last->next;
    }
    
    // if first pointer is dummy, n is equal to length of linked list
    if (first != dummy) {
        last->next = dummy->next; // link last pointer to start point
        dummy->next = first->next; // move start point to next to first pointer
        first->next = nullptr; // first pointer should be last
    }
    
    return dummy->next;
}