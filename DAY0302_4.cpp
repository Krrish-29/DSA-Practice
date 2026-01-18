// 3810. Minimum Operations to Reach Target Array
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        unordered_set<int>set;
        int size=nums.size();
        for(int i=0;i<size;i++){
            if(nums[i]!=target[i]) set.insert(nums[i]);
        }
        return set.size();
    }
};