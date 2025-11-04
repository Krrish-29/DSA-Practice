// 560. Subarray Sum Equals K
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>prefix;
        prefix[0]++;
        int currSum=0,count=0;
        for(int num:nums){
            currSum+=num;
            count+=prefix[currSum-k];
            prefix[currSum]++;
        }
        return count;
    }
};