// 18. 4Sum
class Solution {
private:
    int binary_search(vector<int>&nums,int start,int end,long target){
        int mid;
        while(start<=end){
            mid=start+(end-start)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) end=mid-1;
            else start=mid+1;
        }
        return -1;
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>answer;
        for(int i=0;i<size-3;i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<size-2;j++){
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                for(int k=j+1;k<size-1;k++){
                    if(k>j+1&&nums[k]==nums[k-1]) continue;
                    int l=binary_search(nums,k+1,size-1,target-1LL*nums[i]-1LL*nums[j]-1LL*nums[k]);
                    if(l!=-1&&nums[i]+nums[j]+nums[k]+nums[l]==target) answer.push_back({nums[i],nums[j],nums[k],nums[l]});
                }
            }
        }
        return answer;
    }
};