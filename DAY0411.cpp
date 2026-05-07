// 3660. Jump Game IX
class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int size=nums.size();
        vector<int>prefixMax(size,0),suffixMin(size,0);
        prefixMax[0]=nums[0];
        for(int i=1;i<size;i++){
            prefixMax[i]=max(prefixMax[i-1],nums[i]);
        }
        suffixMin[size-1]=nums[size-1];
        for(int i=size-2;i>=0;i--){
            suffixMin[i]=min(suffixMin[i+1],nums[i]);
        }
        vector<int>ans(size,prefixMax[size-1]);
        for(int i=size-2;i>=0;i--){
            if(prefixMax[i]<=suffixMin[i+1]) ans[i]=prefixMax[i];
            else ans[i]=ans[i+1];
        }
        return ans;
    }
};