// 3186. Maximum Total Damage With Spell Casting
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int,long>map;
        priority_queue<vector<int>,vector<vector<int>>>heap;
        for(int num:power) map[num]++;
        long ans=0,backEl=0,prevEl;
        unordered_map<int,long>dp;
        for(auto [el,fq]:map){
            auto it=map.lower_bound(el-2);
            if(it!=map.begin()) backEl=(*(--it)).first;
            dp[el]=max(dp[prevEl],el*fq+dp[backEl]);
            ans=max(ans,dp[el]);
            prevEl=el;
        }
        return ans;
    }
};