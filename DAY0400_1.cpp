// 3912. Valid Elements in an Array
class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        vector<int>ans;
        int size=nums.size();
        int leftMax=0;
        for(int i=0;i<size;i++){
            bool right=true;
            for(int j=i+1;j<size;j++){
                if(nums[i]<=nums[j]) right=false;
            }
            if((nums[i]>leftMax)||right) ans.push_back(nums[i]);
            leftMax=max(leftMax,nums[i]);
        }
        return ans;
        
    }
};