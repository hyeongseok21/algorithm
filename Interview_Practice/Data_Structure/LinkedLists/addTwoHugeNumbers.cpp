// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * solution(ListNode<int> * a, ListNode<int> * b) {
    stack<int> st1, st2;
    
    // store 1st list in a stack
    for(ListNode<int> *currentNode = a; currentNode != nullptr; 
                                        currentNode = currentNode -> next) {
        st1.push(currentNode -> value);
    }
    // store 2nd list in a stack
    for(ListNode<int> *currentNode = b; currentNode != nullptr; 
                                        currentNode = currentNode -> next) {
        st2.push(currentNode -> value);
    }
    
    // pop two stack following roundupNum, store result
    int roundup = 0;
    stack<int> result;
    while(!st1.empty() && !st2.empty()) {
        int currentnum = st1.top() + st2.top();
        st1.pop(), st2.pop();
        currentnum += roundup;
        roundup = 0;
        if (currentnum > 9999) {
            currentnum -= 10000;
            roundup = 1;
        }
        result.push(currentnum);        
    }
    // check first stack still has elements
    while(!st1.empty()) {
        int currentnum = st1.top();
        st1.pop();
        currentnum += roundup;
        roundup = 0;
        if (currentnum > 9999) {
            currentnum -= 10000;
            roundup = 1;
        }
        result.push(currentnum);
    }
    // check second stack still has elements
    while(!st2.empty()) {
        int currentnum = st2.top();
        st2.pop();
        currentnum += roundup;
        roundup = 0;
        if (currentnum > 9999) {
            currentnum -= 10000;
            roundup = 1;
        }
        result.push(currentnum);
    }
    // when the case last summation has roundupnum
    if (roundup == 1) {
        int currentnum = 1;
        result.push(currentnum);
    }
    
    // build new linked list
    ListNode<int> * currentNode = a;
    while(!result.empty()) {
        if(currentNode -> next != nullptr) {
            currentNode -> value = result.top();
            result.pop();
            currentNode = currentNode -> next;
        }
        else {
            ListNode<int> * newNode;
            newNode = (struct ListNode<int>*)malloc(sizeof(struct ListNode<int>));
            currentNode -> next = newNode;
            newNode -> next = nullptr;
            currentNode -> value = result.top();
            result.pop();
            if(result.empty()) {
                currentNode -> next = nullptr;
            }
            currentNode = currentNode -> next;
        }
        
        if(result.empty())
            return a;
    }
}