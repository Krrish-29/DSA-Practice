// 2553. Separate the Digits in an Array
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(auto &num:nums){
            bool skip=true;
            for(int x=100000;x>0;x/=10){
                if(!skip||(num/x)!=0) {
                    ans.push_back(num/x);
                    skip=false;
                }
                num-=((num/x)*x);
            }
        }
        return ans;
    }
};