// 2439. Minimize Maximum of Array
class Solution {
private:
    bool checkMaxMin(vector<int>&nums,int mid){
        long long buffer=0;
        for(int num:nums){
            if(num<=mid) buffer+=(mid-num);
            else {
                if(num-mid>buffer) return false;
                buffer-=(num-mid);
            }
        }
        return true;
    }
public:
    int minimizeArrayValue(vector<int>& nums) {
        int left=nums[0],right=*max_element(nums.begin(),nums.end()),mid;
        while(left<=right){
            mid=left+(right-left)/2;
            if(checkMaxMin(nums,mid)) right=mid-1;
            else left=mid+1;
        }
        return left;
    }
};