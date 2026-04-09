// 3883. Count Non Decreasing Arrays With Given Digit Sums
class Solution {
private:
    unordered_map<int,vector<int>>map;
    void solve(){
        for(int i=0;i<=5000;i++){
            int x=i;
            int sum=0;
            while(x>0){
                sum+=x%10;
                x/=10;
            }
            map[sum].push_back(i);
        }
    }
public:
    int countArrays(vector<int>& digitSum) {
        int size=digitSum.size();
        const int MOD=1e9+7;
        for(int &num:digitSum) if(num>31) return 0;
        solve();
        vector<vector<int>>digitMap;
        for(int &num:digitSum){
            digitMap.push_back(map[num]);
        }
        vector<vector<int>>dp(size);
        dp[0].resize(digitMap[0].size(),1);
        for(int i=1;i<size;i++){
            vector<long long>pref(digitMap[i-1].size(),0);
            pref[0]=dp[i-1][0];
            for(int j=1;j<digitMap[i-1].size();j++) pref[j]=(pref[j-1]+dp[i-1][j])%MOD;
            dp[i].resize(digitMap[i].size());

            for(int j=0;j<digitMap[i].size();j++){
                int idx=upper_bound(digitMap[i-1].begin(),digitMap[i-1].end(),digitMap[i][j])-digitMap[i-1].begin()-1;
                if(idx>=0) dp[i][j]=pref[idx];
            }
        }
        long long ans=0;
        for(long long x:dp[size-1]){
            ans=(ans+x)%MOD;
        }
        return ans;
    }
};