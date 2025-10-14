// 3349. Adjacent Increasing Subarrays Detection I
// good question try again looks easy but buidling solution is tough
class Solution {
private:
    bool isIncresing(vector<int>&nums,int start,int k){
        for(int i=start+1;i<start+k;i++){
            if(nums[i]<=nums[i-1]) return false;
        }
        return true;
    }
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int size=nums.size();
        for(int i=0;i+2*k<=size;i++){
            if(isIncresing(nums,i,k)&&isIncresing(nums,i+k,k)) return true;
        }
        return false;
    }
};