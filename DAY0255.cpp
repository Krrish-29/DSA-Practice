// 3623. Count Number of Trapezoids I
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        map<int,int>map;
        const int MOD=1e9+7;
        int ans=0,pairs=0;
        for(auto p:points) map[p[1]]++;
        for(auto it=map.rbegin();it!=map.rend();++it){
            long long p=it->second*1LL*(it->second-1)/2;
            ans=(ans+pairs*1LL*p%MOD)%MOD;
            pairs+=p;
        }
        return ans;
    }
};