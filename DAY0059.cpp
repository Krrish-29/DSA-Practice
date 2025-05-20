// 3355. Zero Array Transformation I
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>arr(nums.size()+1,0);
        for(int i=0;i<queries.size();i++){
            arr[queries[i][0]]++;
            arr[queries[i][1]+1]--;
        }
        for(int i=1;i<nums.size()+1;i++){
            arr[i]+=arr[i-1];
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>arr[i]) return false;
        }
        return true;
    }
};