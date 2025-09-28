// 976. Largest Perimeter Triangle
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int size=nums.size(),left,right,maxPeri=0;
        for(int i=size-1;i>1;i--){
            if(nums[i-1]+nums[i-2]>nums[i]){
                maxPeri=max(maxPeri,nums[i-1]+nums[i-2]+nums[i]);
            }
        }
        return maxPeri;
    }
};