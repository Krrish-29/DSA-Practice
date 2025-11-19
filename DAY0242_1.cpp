// 2154. Keep Multiplying Found Values by Two
class Solution {
private:
    bool binary_search(vector<int>&nums,int left,int right,int target){
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
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(),nums.end());
        int flag=binary_search(nums,0,nums.size()-1,original);
        while(flag){
            original*=2;
            flag=binary_search(nums,0,nums.size()-1,original);
        }
        return original;
    }
};