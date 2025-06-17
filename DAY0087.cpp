// 2016. Maximum Difference Between Increasing Elements
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        // int max=-1,size=nums.size();
        // for(int i=0;i<size-1;i++){
        //     for(int j=i+1;j<size;j++){
        //         if(nums[i]!=nums[j]&&nums[j]-nums[i]>max) max=nums[j]-nums[i];
        //     }
        // }
        // return max;
        int min=INT_MAX,diff=-1,size=nums.size();
        for(int i=0;i<size;i++){
            if(nums[i]<=min) min=nums[i];
            else diff=max(diff,nums[i]-min);
        }
        return diff;
    }
};