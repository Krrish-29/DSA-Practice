// 3644. Maximum K to Sort a Permutation
class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int size=nums.size(),ans=-1;
        for(int i=0;i<size;i++){
            if(i!=nums[i]){
                if(ans==-1) ans=nums[i];
                else ans&=nums[i];
            }
        }
        return ans>0?ans:0;
    }
};