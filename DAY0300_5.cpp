// 2448. Minimum Cost to Make Array Equal
// posted solution for detiled answer
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int size=nums.size();
        int left=INT_MAX,right=INT_MIN,mid;
        for(int i=0;i<size;i++){
            left=min(left,nums[i]);
            right=max(right,nums[i]);
        }
        long long totalCost=LLONG_MAX;
        long long midCost=0,midCost1=0;
        while(left<=right){
            mid=left+(right-left)/2;
            midCost=0;midCost1=0;
            for(int i=0;i<size;i++){
                midCost+=(abs(mid-nums[i])*1LL*cost[i]);
                midCost1+=(abs(mid+1-nums[i])*1LL*cost[i]);
            }
            totalCost=min({totalCost,midCost,midCost1});
            if(midCost1<midCost) left=mid+1;
            else right=mid-1;
        }
        return totalCost;
    }
};