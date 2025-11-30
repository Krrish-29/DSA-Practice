// 3702. Longest Subsequence With Non-Zero Bitwise XOR
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total=0;
        bool allZero=true;
        for(int num:nums){
            if(num!=0) allZero=false;
            total^=num;
        }
        if(allZero) return 0;
        return total==0?nums.size()-1:nums.size();
    }
};