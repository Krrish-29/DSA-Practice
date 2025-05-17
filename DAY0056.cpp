// 75. Sort Colors
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size=nums.size(),left=0,right=size-1,it=0;
        while(it<=right){
            if(nums[it]==0){
                swap(nums[left],nums[it]);
                left++;
                it++;
            }
            else if(nums[it]==2){
                swap(nums[right],nums[it]);
                right--;
            }
            else{
                it++;
            }

        }
    }
};