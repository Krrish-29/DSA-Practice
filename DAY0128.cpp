// 2044. Count Number of Maximum Bitwise-OR Subsets
class Solution {
public:
    void pairs(int start,int &end,int &count,vector<int>&nums,int currentSum,int&sum){
        if(start==end){
            if (currentSum==sum){
                count++;
            }
            return ;
        }
        pairs(start+1,end,count,nums,currentSum,sum);
        pairs(start+1,end,count,nums,currentSum|nums[start],sum);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int sum=0,size=nums.size(),count=0;
        for(auto num:nums){
            sum|=num;
        }
        pairs(0,size,count,nums,0,sum);
        return count;
    }
};