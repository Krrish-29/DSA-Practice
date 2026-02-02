// 3010. Divide an Array Into Subarrays With Minimum Cost I
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int size=nums.size(),i=0,min0=nums[i],min1=INT_MAX,min2=INT_MAX;
        for(i=1;i<size;i++){
            if(nums[i]<min1){
                min2=min1;
                min1=nums[i];
            }
            else if(nums[i]<min2){
                min2=nums[i];
            }
        }
        return min0+min1+min2;
    }
};