// 162. Find Peak Element
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left=0,right=nums.size()-1,middle;
        bool l=false,r=false;
        if(right==left) return 0;
        if(left+1<=right&&nums[left]>nums[left+1]) return left;
        if(right-1>=left&&nums[right]>nums[right-1]) return right;
        while(left<=right){
            l=false;
            r=false;
            middle=left+(right-left)/2;
            if(nums[middle]>nums[middle+1]) r=true;
            if(nums[middle]>nums[middle-1]) l=true;
            if(l&&r) return middle;
            if(!l&&r){
                right=middle;
            }
            else{
                left=middle+1;
            }
        }
        return -1;
    }
};