// 2438. Range Product Queries of Powers
class Solution {
private:
    int modInv(long long base,long long exp,int mod){
        int result=1;
        base%=mod;
        while(exp>0){
            if(exp%2==1) result=(result*base)%mod;
            base = (base*base)%mod;
            exp/=2;
        }
        return result;
    }
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD=1e9+7;
        vector<long long>powers;
        for(int i=0;i<30;i++){
            if(n&(1<<i)) powers.push_back(1<<i);
        }
        for(int i=1;i<powers.size();i++){
            powers[i]=(powers[i]*powers[i-1])%MOD;
        }
        vector<int>ans;
        for(auto query:queries){
            int start=query[0],end=query[1];
            ans.push_back(powers[end]*modInv(start>0?powers[start-1]:1,MOD-2,MOD)%MOD);
        }
        return ans;
    }
};