// 2336. Smallest Number in Infinite Set
class SmallestInfiniteSet {
private:
    int minEle=1;
    priority_queue<int,vector<int>,greater<int>>q;
    unordered_map<int,bool>map;
public:
    SmallestInfiniteSet() {}
    
    int popSmallest() {
        if(q.empty()){
            return minEle++;
        }
        int ele=q.top();
        map[ele]=false;
        q.pop();
        return ele;
    }
    
    void addBack(int num) {
        if(num<minEle&&map[num]==false) {
            q.push(num);
            map[num]=true;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */