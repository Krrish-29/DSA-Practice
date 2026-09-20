// 4040. Minimum Operations to Form Subset Sum I
class Solution {
private:
    vector<vector<int>>dp;
    long long helper(vector<int>& nums,int idx,int sum){
        if(sum==0) return 0;
        if(idx==nums.size()) return INT_MAX;
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        long long op=INT_MAX,num=nums[idx];
        op = min(op,helper(nums,idx+1,sum));
        long long divop=0,mulop=0;
        while(num<=sum){
            op = min(op,mulop+helper(nums,idx+1,sum-num));
            num*=2;
            mulop++;
        }
        num = nums[idx];
        while(num>sum){
            num/=2;
            divop++;
        }
        while(num>0){
            op = min(op,divop+helper(nums,idx+1,sum-num));
            num/=2;
            divop++;
        }
        return dp[idx][sum]=op;
    }
public:
    int minOperations(vector<int>& nums, int sum) {
        // simple 2d dp with idx and sum
        // either we skip the idx or first multiply it until it becomes more than currSum
        // and each multiplication is a operation
        // and then we start from the same num and first reduce it equal or less than the currSum 
        // then substracting it from num and each dividing is a operation
        // make sure the sum is never < 0
        // if the sum is reduced to 0 at any idx then return 0 else return INT_MAX if idx == size
        // use long long to prevent int overflow
        dp.assign(nums.size(),vector<int>(sum+1,-1));
        int ans = helper(nums,0,sum);
        return ans>=INT_MAX?-1:ans;
    }
};