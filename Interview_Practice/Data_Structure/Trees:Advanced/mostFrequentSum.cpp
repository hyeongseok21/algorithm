//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };

int subtreeSum(Tree<int> * t, unordered_map<int, int> &sumfreq, int &maxfreq) {
    if (!t) return 0;
    
    int leftsum = subtreeSum(t->left, sumfreq, maxfreq);
    int rightsum = subtreeSum(t->right, sumfreq, maxfreq);
    
    int currentsum = leftsum + rightsum + t->value;
    
    sumfreq[currentsum]++;
    maxfreq = max(maxfreq, sumfreq[currentsum]);
    
    return currentsum;
}

vector<int> solution(Tree<int> * t) {
    unordered_map<int, int> sumfreq;
    int maxfreq = 0;
    
    subtreeSum(t, sumfreq, maxfreq);
    
    cout << maxfreq << '\n';
    for(auto sum : sumfreq) {
        cout << sum.first << ' ' << sum.second << '\n';
    }
    
    vector<int> ret;
    for(auto &sum : sumfreq) {
        if(sum.second == maxfreq) {
            ret.push_back(sum.first);
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}