// 1589. Maximum Sum Obtained of Any Permutation
class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        // brute force we have to count how many time each idx has come in a request range 
        // therefore the idx which has come maximum times can be binded with the max in nums
        // and so on soforth for each less freq idx with corressponding elem in nums[i]
        // the time complexity of the idx freq counting is about n^2 
        // to minimize we can use line sweep and mark the start and end+1 (cause end is inclusize) with +1 and -1
        // allowing us to know where each range is starting and ending and we can then use prefix sum 
        // to move over each idx and know its freq (popularity) then sort freq and nums and return ans
        int size = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>reqMap(size+1,0);
        for(auto &request:requests){
            reqMap[request[0]]++;
            reqMap[request[1]+1]--;
        }
        for(int i=1;i<=size;i++){
            reqMap[i]+=reqMap[i-1];
        }
        sort(reqMap.begin(),reqMap.end());
        int res=0;
        const int MOD = 1e9+7;
        for(int i=0;i<size;i++){
            res=(res+(nums[i]*1LL*reqMap[i+1])%MOD)%MOD;
        }
        return res;
    }
};