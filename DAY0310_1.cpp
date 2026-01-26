// 3507. Minimum Pair Removal to Sort Array I
class Solution {
private:
    bool is_sorted(vector<int>&nums){
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]) return false;
        }
        return true;
    }
    int minSumIdx(vector<int>&nums){
        int idx=0;
        for(int i=1;i<nums.size()-1;i++){
            if((nums[i]+nums[i+1])<(nums[idx]+nums[idx+1])) idx=i;
        }
        return idx;
    }
public:
    int minimumPairRemoval(vector<int>& nums) {
        int op=0;
        while(!is_sorted(nums)){
            int idx=minSumIdx(nums);
            nums[idx]+=nums[idx+1];
            nums.erase(idx+1+nums.begin());
            op++;
        }
        return op;
    }
};