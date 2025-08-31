// 15. 3Sum
class Solution {
private:
    int binarySearch(vector<int>&nums,int left,int right,int target){
        int mid;
        while(left<=right){
            mid=left+(right-left)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) right=mid-1;
            else left=mid+1;
        }
        return -1;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int size=nums.size();
        vector<vector<int>>answer;
        for(int i=0;i<size-2;i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<size-1;j++){
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                int k=binarySearch(nums,j+1,size-1,-nums[i]-nums[j]);
                if(k!=-1){
                    answer.push_back({nums[i],nums[j],nums[k]});
                }
            }
        }
        return answer;
    }
};