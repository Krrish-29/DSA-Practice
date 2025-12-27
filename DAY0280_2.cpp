// 153. Find Minimum in Rotated Sorted Array
class Solution {
private:
    int pivot(vector<int>&nums,int size){
        int left=0,right=size-1,mid;
        while(left<right){
            mid=left+(right-left)/2;
            if(nums[mid]>nums[right]) left=mid+1;
            else right=mid;
        }
        return nums[left];
    }
public:
    int findMin(vector<int>& nums) {
        return pivot(nums,nums.size());
    }
};