// 1685. Sum of Absolute Differences in a Sorted Array
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int size=nums.size();
        vector<int>suffix(size,0);
        for(int i=size-2;i>=0;i--){
            suffix[i]=suffix[i+1]+nums[i+1];
        }
        vector<int>ans(size);
        int left=0,right=0;
        for(int i=0;i<size;i++){
            left=left+i*(nums[i]-(i>0?nums[i-1]:0)),right=suffix[i]-nums[i]*(size-1-i);
            ans[i]=left+right;
        }
        return ans;
    }
};