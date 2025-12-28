// 3789. Minimum Cost to Acquire Required Items
class Solution {
public:
    long long minimumCost(long long cost1, long long cost2, long long costBoth, long long need1, long long need2) {
        long long ans=0;
        if(need1==0&&need2==0) return 0;
        long long x=min(need1,need2);
        cost1=min(cost1,costBoth);
        cost2=min(cost2,costBoth);
        ans=min((cost1*need1+cost2*need2),(costBoth*(x)+cost1*(need1-x)+cost2*(need2-x)));
        return ans;
    }
};