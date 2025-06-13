// 3423. Maximum Difference Between Adjacent Elements in a Circular Array
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int size=nums.size(),difference=abs(nums[0]-nums[size-1]);
        for(int i=1;i<size;i++){
            if(abs(nums[i-1]-nums[i])>difference) difference=abs(nums[i-1]-nums[i]); 
        }
        return difference;
    }
};