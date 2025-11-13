// 3736. Minimum Moves to Equal Array Elements III
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxVal=0;
        for(int num:nums) maxVal=max(num,maxVal);
        int ans=0;
        for(int num:nums) ans+=(maxVal-num);
        return ans;
    }
};