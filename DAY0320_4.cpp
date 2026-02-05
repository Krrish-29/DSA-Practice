// 3825. Longest Strictly Increasing Subsequence With Non-Zero Bitwise AND
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int len=0;
        for(int bit=0;bit<31;bit++){
            vector<int>temp;
            for(int &num:nums){
                if(num&(1<<bit)) temp.push_back(num);
            }
            // longest increasing subsequence
            vector<int>tails;
            for(int &x:temp){
                auto it=lower_bound(tails.begin(),tails.end(),x);
                if(it==tails.end()) tails.push_back(x);
                else *it=x;
            }
            len=max(len,(int)tails.size());
        }
        return len;
    }
};