// 81. Search in Rotated Sorted Array II
class Solution {
private:
    int pivot(vector<int>&nums,int size){
        int left=0,right=size-1,mid;
        while(left<right){
            while(left<right&&nums[left]==nums[left+1]) left++;
            while(left<right&&nums[right]==nums[right-1]) right--;
            mid=left+(right-left)/2;
            if(nums[mid]>nums[right]) left=mid+1;
            else right=mid;
        }
        return left;
    }
    int binary_search(vector<int>&nums,int left,int right,int target){
        int mid;
        while(left<=right){
            mid=left+(right-left)/2;
            if(nums[mid]==target) return true;
            else if(nums[mid]>target) right=mid-1;
            else left=mid+1;
        }
        return false;
    }
public:
    bool search(vector<int>& nums, int target) {
        int size=nums.size();
        int k=pivot(nums,size);
        return binary_search(nums,0,k-1,target)||binary_search(nums,k,size-1,target);
    }
};