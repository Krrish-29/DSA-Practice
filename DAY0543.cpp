// 1621. Number of Sets of K Non-Overlapping Line Segments
class Solution {
private:
   vector<vector<int>>dp;
    const int MOD=1e9+7;
    int helper(int n,int k){
        if(n<k) return 0;
        if(k==1) return n*(n-1)/2;
        if(dp[n][k]!=-1) return dp[n][k];
        int count=0;
        for(int i=1;i<=n-k;i++){ // points are more than equal to lines 
        // how many points can be used for 1 line making sure others can be made as well
            count = (count + (i*1LL*helper(n-i,k-1) ))%MOD;
        }
        return dp[n][k]=count;
    }
public:
    int numberOfSets(int n, int k) {
        // staring with basic if we have n points and 1 line do draw it will be nC2 -> n*(n+1)/2
        // so each time we fix 1 line and some x points then we can recurse on points and lines left
        // making sure points are more than the lines 
        // if lines left to be made == 1 then we can simply apply nC2 on points left
        // now for this to work we have to fix 1 line with some points starting from 0 - 1, then 0 - 2
        // that single line can be formed b/w 0 - 1 only 1 time , but b/w 0 - 2 the unique comb not seen prev
        // will be 2 that is why we do i*helper(n-i //reducing i points as those i points will be used to make 1 line in different combinations and each time unique comb will be i,k-1 // reducing 1 line)
        // then using memo  
        dp.assign(n+1, vector<int>(k+1, -1));
        return helper(n,k);
    }
};