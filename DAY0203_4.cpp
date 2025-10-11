// 3709. Design Exam Scores Tracker
// try again 
// first try used map with the due to high no. of sum queries 
// then used sparse segment tree to log(n) sum queries and log(n) record queries
struct Node {
    long long val = 0;
    Node *left = nullptr, *right = nullptr;
};

class SparseSegTree {
public:
    Node *root;
    long long L, R; // overall range limits

    SparseSegTree(long long l, long long r) {
        root = new Node();
        L = l;
        R = r;
    }

    void update(Node* node, long long l, long long r, long long idx, long long val) {
        if (l == r) {
            node->val += val;
            return;
        }
        long long mid = (l + r) / 2;
        if (idx <= mid) {
            if (!node->left) node->left = new Node();
            update(node->left, l, mid, idx, val);
        } else {
            if (!node->right) node->right = new Node();
            update(node->right, mid + 1, r, idx, val);
        }

        node->val = 0;
        if (node->left) node->val += node->left->val;
        if (node->right) node->val += node->right->val;
    }

    long long query(Node* node, long long l, long long r, long long ql, long long qr) {
        if (!node || qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return node->val;

        long long mid = (l + r) / 2;
        return query(node->left, l, mid, ql, qr) +
               query(node->right, mid + 1, r, ql, qr);
    }

    // Helper wrappers
    void update(long long idx, long long val) { update(root, L, R, idx, val); }
    long long query(long long l, long long r) { return query(root, L, R, l, r); }
};

class ExamTracker {
private:
    // unordered_map<int,int>tracker;
    SparseSegTree tree;
public:
    ExamTracker():tree(1, 1e9) {
        
    }
    
    void record(int time, int score) {
        // tracker[time]=score;
        tree.update(time,score);
    }
    
    long long totalScore(int startTime, int endTime) {
        // long long score=0;
        return tree.query(startTime,endTime);
        
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */