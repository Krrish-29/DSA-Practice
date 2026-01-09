// 1365. How Many Numbers Are Smaller Than the Current Number
class Solution {
private:
    // int lowerBound(vector<int>&nums,int target){
    //     int left=0,right=nums.size(),mid;
    //     while(left<right){
    //         mid=left+(right-left)/2;
    //         if(nums[mid]<target) left=mid+1;
    //         else right=mid;
    //     }
    //     return left;
    // }
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>copy=nums;
        sort(copy.begin(),copy.end());
        //either use map for O(nlogn+n) time and O(n+n) space
        // or lowerbound for O(nlogn+nlogn) time and O(n) space
        unordered_map<int,int>map;
        for(int i=nums.size()-1;i>=0;i--){
            map[copy[i]]=i;
        }
        for(int &num:nums){
            // num=lowerBound(copy,num);
            num=map[num];
        }
        return nums;
    }
};