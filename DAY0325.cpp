// 3719. Longest Balanced Subarray I
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        // normal sliding window will work
        int maxLen=0;
        int size=nums.size();
        unordered_set<int>even;
        unordered_set<int>odd;
        for(int i=0;i<size;i++){
            odd.clear();even.clear();
            for(int j=i;j<size;j++){
                if(nums[j]%2==0) even.insert(nums[j]);
                else odd.insert(nums[j]);
                if(even.size()==odd.size()) maxLen=max(maxLen,j-i+1);
            }
        }
        return maxLen;
    }
};