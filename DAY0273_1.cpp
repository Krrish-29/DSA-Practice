// 3779. Minimum Number of Operations to Have Distinct Elements
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int size=nums.size();
        unordered_map<int,int>map;
        int maxOp=0;
        for(int i=0;i<size;i++){
            if(map.find(nums[i])!=map.end()) maxOp=max(maxOp,map[nums[i]]);
            map[nums[i]]=i/3+1;
        }
        return maxOp;
    }
};