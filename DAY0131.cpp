// 898. Bitwise ORs of Subarraysclass Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>prev;
        unordered_set<int>result;
        for(int num:arr){
            unordered_set<int>current;
            current.insert(num);
            for(int val:prev){
                current.insert(val|num);
            }
            prev=move(current);
            for(int val:prev){
                result.insert(val);
            }
        }
        return result.size();
    }
};