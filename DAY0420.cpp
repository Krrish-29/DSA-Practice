// 154. Find Minimum in Rotated Sorted Array II
class Solution {
public:
    int findMin(vector<int>& nums) {
        // int minEle=INT_MAX;
        // for(auto &num:nums){
        //     minEle=min(minEle,num);
        // }
        // return minEle;
        
        int left=0,right=nums.size()-1,mid;
        while(left<right){
            mid=left+(right-left)/2;
            if(nums[mid]>nums[right]) {
                left=mid+1;
            }
            else if(nums[mid]<nums[right]){
                right=mid;
            }
            else{
                right--;
            }
        }
        return nums[left];
    }
};