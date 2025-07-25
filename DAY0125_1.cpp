// 3487. Maximum Unique Subarray Sum After Deletion
class Solution {
public:
    int maxSum(vector<int>& nums) {
        // vector<int>hashmap(202,0);
        sort(nums.begin(),nums.end());
        int size=nums.size(),maxSum=INT_MIN,current=0,prev=INT_MAX;
        for(int i=size-1;i>=0;i--){
            // if(hashmap[nums[j]+100]==0){
                // hashmap[nums[j]+100]++;
            if(nums[i]!=prev){
                current+=nums[i];
                prev=nums[i];
                maxSum=max(current,maxSum);
            }
        }
        return maxSum;
    }
};