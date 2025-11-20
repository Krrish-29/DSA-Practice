// 3502. Minimum Cost to Reach Every Position
class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int size=cost.size();
        for(int i=1;i<size;i++){
            cost[i]=min(cost[i],cost[i-1]);
        }
        return cost;
    }
};