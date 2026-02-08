// 3833. Count Dominant Indices
class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int size=nums.size();
        vector<int>suffix(size,0);
        suffix[size-1]=nums[size-1];
        for(int i=size-2;i>=0;i--){
            suffix[i]=suffix[i+1]+nums[i];
        }
        int count=0;
        for(int i=0;i<size-1;i++){
            if( nums[i]> ( suffix[i+1] / (size-(i+1)) ) ) count++;
        }
        return count;
    }
};