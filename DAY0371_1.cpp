// 3880. Minimum Absolute Difference Between Two Values
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int idx1=-1,idx2=-1,ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) idx1=i;
            else if(nums[i]==2) idx2=i;
            if(idx1!=-1&&idx2!=-1) ans=min(ans,abs(idx1-idx2));
        }
        return ans==INT_MAX?-1:ans;
    }
};