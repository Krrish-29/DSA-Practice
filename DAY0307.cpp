// 2616. Minimize the Maximum Difference of Pairs
class Solution {
private:
    bool pairsPossible(vector<int>&nums,int target,int size,int pairs){
        int pair=0;
        for(int i=1;i<size;i++){
            if(abs(nums[i]-nums[i-1])<=target) {
                pair++;
                i++;
            }
            if(pair==pairs) return true;
        }
        return false;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        if(p==0) return 0;
        sort(nums.begin(),nums.end());
        int size=nums.size(),left=0,right=nums[size-1]-nums[0],mid;
        while(left<=right){
            mid=left+(right-left)/2;
            if(pairsPossible(nums,mid,size,p)) right=mid-1;
            else left=mid+1;
        }
        return left;
    }
};