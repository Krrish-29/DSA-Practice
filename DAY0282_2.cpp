// 3784. Minimum Deletion Cost to Make All Characters Equal
class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        vector<long long>alphaCost(26,0);
        long long total=0,ans=LLONG_MAX;
        int size=s.size();
        for(int i=0;i<size;i++){
            alphaCost[s[i]-'a']+=cost[i];
            total+=cost[i];
        }
        for(int i=0;i<26;i++){
            ans=min(ans,total-alphaCost[i]);
        }
        return ans;
    }
};