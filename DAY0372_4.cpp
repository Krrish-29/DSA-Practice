// 3886. Sum of Sortable Integers
class Solution {
private:
    int size;
    int solve(vector<int>&nums,int limit){
        int prevMax=INT_MIN;
        for(int i=0;i<size;i+=limit){
            bool flag=false;
            int currMax=INT_MIN,currMin=INT_MAX;
            for(int k=i;k<i+limit&&k<size;k++){
                if((k+1<i+limit && k+1<size) && nums[k]>nums[k+1] && !flag) flag=true;
                else if((k+1<i+limit && k+1<size) && nums[k]>nums[k+1] && flag) return 0;
                currMax=max(currMax,nums[k]);
                currMin=min(currMin,nums[k]);
            }
            if(flag &&nums[i]<nums[i+limit-1]) return 0; // if rotated the last ele should be less than first
            if(currMin<prevMax) return 0;
            prevMax=currMax;
        }
        return limit;
    }
public:
    int sortableIntegers(vector<int>& nums) {
        size=nums.size();
        int ans=0;
        for(int i=1;i<=size;i++){
            if(size%i==0) ans+=solve(nums,i);
        }
        return ans;
    }
};