// 462. Minimum Moves to Equal Array Elements II
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int median=nums[nums.size()/2];
        int count=0;
        for(auto &num:nums){
            count+=abs(num-median);
        }
        return count;
    }
};