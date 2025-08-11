// 2438. Range Product Queries of Powers
class Solution {
private:
    const int MOD=1e9+7;
     long long modInverse(long long base, long long exp) {
        long long result = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        // range sum querys with product
        vector<int>power;
        for(int i=0;i<31;i++){
            if(n&(1<<i)){
                power.push_back(1<<i);
            }
        }
        vector<long long>range;
        range.push_back(1);
        for(int p:power){
            range.push_back((p*range.back())%MOD);
        }
        vector<int>answer;
        long long res;
        for(auto q:queries){
            res=(range[q[1]+1]*modInverse(range[q[0]],MOD-2));
            answer.push_back(res%MOD);
        }
        return answer;
    }
};