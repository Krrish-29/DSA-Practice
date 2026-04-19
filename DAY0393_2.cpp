// 3904. Smallest Stable Index II
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
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
        for(int i=0;i<size;i++){
            if((prefixMax[i]-suffixMin[i])<=k) {
                return i;
            }
        }
        return -1;
    }
};