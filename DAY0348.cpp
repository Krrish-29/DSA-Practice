// 146. LRU Cache
class LRUCache {
private:
    struct ListNode {
        int key;
        int val;
        ListNode *prev;
        ListNode *next;
        ListNode() :key(0) ,val(0), next(nullptr) , prev(nullptr) {};
        ListNode(int k,int v) :key(k) ,val(v), next(nullptr) ,prev(nullptr) {};
    };
    int cap;
    unordered_map<int,ListNode*>map;
    ListNode *head,*tail;
public:
    LRUCache(int capacity) {
        cap=capacity;
        head=new ListNode();
        tail=new ListNode();
        head->next=tail;
        tail->prev=head;
    }
    void insertAtHead(ListNode *node){
        node->next=head->next;
        node->prev=head;
        head->next->prev=node;
        head->next=node;
    }
    void deleteNode(ListNode *node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
    int get(int key) {
        if(map.find(key)!=map.end()) {
            deleteNode(map[key]);
            insertAtHead(map[key]);
            return map[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(map.find(key)!=map.end()) {
            map[key]->val=value;
            deleteNode(map[key]);
            insertAtHead(map[key]);
        }
        else{
            ListNode *newNode=new ListNode(key,value);
            if(map.size()==cap){
                map.erase(tail->prev->key);
                deleteNode(tail->prev);
            }
            map[key]=newNode;
            insertAtHead(newNode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */