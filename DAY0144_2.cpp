// 1752. Check if Array Is Sorted and Rotated
class Solution {
public:
    bool check(vector<int>& nums) {
        int size=nums.size(),count=0,smallest=nums[0];
        for(int i=1;i<size;i++){
            if(nums[i-1]>nums[i]) count++;
            if(count==1&&nums[i]>smallest) count++;
            if(count>1) return false;
        }
        return true;
    }
};