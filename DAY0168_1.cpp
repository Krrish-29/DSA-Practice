// 3668. Restore Finishing Order
class Solution {
private:
    unordered_set<int>hashmap;
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        for(int val:friends) hashmap.insert(val);
        friends.resize(0);
        for(int val:order){
            if(hashmap.find(val)!=hashmap.end()) friends.push_back(val);
        }
        return friends;
    }
};