// 540. Single Element in a Sorted Array
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // int size=nums.size();
        // for(int i=1;i<size;i+=2){
        //     if(nums[i]!=nums[i-1]) return nums[i-1];
        // }
        // return nums[size-1];
        // int xorSum=0;
        // for(int num:nums){
        //     xorSum^=num;
        // }
        // return xorSum;
        int size=nums.size()-1,left=0,right=size-1,mid;
        while(left<right){
            mid=left+(right-left)/2;
            if(mid%2==1) mid--;
            if(nums[mid]==nums[mid+1]) left=mid+2;
            else right=mid;
        }
        return nums[left];
    }
};