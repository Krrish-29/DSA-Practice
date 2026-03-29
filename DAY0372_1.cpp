// 3881. Direction Assignments with Exactly K Visible People
class Solution {
private:
    int pow(int base,int exp,int MOD){
        base%=MOD;
        int res=1;
        while(exp>0){
            if(exp%2==1) res=(1LL*res*base)%MOD;
            base=(1LL*base*base)%MOD;
            exp/=2;
        }
        return res;
    }
    int modInv(int b,int MOD){
        return pow(b,MOD-2,MOD);
    }
public:
    int countVisiblePeople(int n, int pos, int k) {
        // n-1 C k = (n-1)! / (n-1-k)! k!
        // the above is true for one dir of the pos person so 2X it for all comb.
        // long long ans=2;
        // const int MOD=1e9+7;
        // for(int i=1;i<=k;i++){
        //     ans=ans*(n-i)%MOD;
        //     ans=(ans%MOD*modInv(i,MOD))%MOD;
        // }
        // return ans;

        long long top=2,bottom=1;
        const int MOD=1e9+7;
        for(int i=1;i<=k;i++){
            top=(top*(n-i))%MOD;
            bottom=(bottom*i)%MOD;
        }
        return (top*1LL*modInv(bottom,MOD)%MOD);
    }
};