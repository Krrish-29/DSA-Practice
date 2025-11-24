// 1018. Binary Prefix Divisible By 5
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int bnum=0;
        vector<bool>ans;
        for(int num:nums){
            bnum=(bnum%5)*2+num;
            if(bnum%5==0) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};