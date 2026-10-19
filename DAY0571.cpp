// 2602. Minimum Operations to Make All Array Elements Equal
class Solution {
private:
    int upper_bound(vector<int>& nums,int target){
        int left=0,right=nums.size(),mid;
        while(left<right){
            mid = left + (right-left)/2;
            if(target >= nums[mid]) left = mid+1;
            else right = mid;
        }
        return left;
    }
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        // approach is that in brute force to converage all nums to query[i] we use the diff b/w the 
        // num and query[i] but if we see that nums above the query[i] will have to reduced (by say -x) 
        // and nums below query[i] will need to be increased (by say +y) 
        // and small observation is that if all nums were above query[i] we could have used the 
        // (sum of all nums) - (size of nums * query[i]) this would have given 
        // the operations required to reduce all nums to query[i]
        // similar thing if we converged all nums of a larger number ,just changing the -ve sign
        // in this problem we cant do that currently since summing -x and +y would cancel each others operations
        // since the parity will be different for some elems from others
        // so we sort the nums and use prefix sum afterwards,then use upperbound and lower bound for each query[i]
        // upperbond tell starting idx from where all elems are above the query[i], 
        // and lowerbound does the opposite , for each of the both segments the parity is same across all elems 
        // therefore we can add them and subtract the size of segment * query[i] accordingly
        sort(nums.begin(),nums.end());
        int size = nums.size();
        vector<long long>prefixSum(size+1,0);
        for(int i=0;i<size;i++){ // sum of first i numbers 
            prefixSum[i+1]=(prefixSum[i]+nums[i]);
        }
        vector<long long>operations;
        long long op=0,ub,left,right;
        for(int &query:queries){
            if(query<nums[0]){
                op  = (prefixSum[size]-(size*1LL*query));
            }
            else if(query>nums[size-1]){
                op  = ((size*1LL*query)-prefixSum[size]);
            }
            else{
                ub = upper_bound(nums,query);
                left = prefixSum[ub];
                right = prefixSum[size] - prefixSum[ub];
                op = ((query*1LL*ub) - left ) + (right - query*1LL*(size-ub));
            }
            operations.push_back(op);
        }
        return operations;
    }
};