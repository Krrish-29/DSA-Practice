// 3966. Count Good Integers in a Range
class Solution {
private:
    vector<vector<vector<vector<long long>>>>dp;//pos,tight,leadingZero,prev digit
    long long helper(int pos,int tight,int started,int prevDigit,string digit,int k){
        if(pos==digit.size()) return started;
        if(dp[pos][tight][started][prevDigit+1]!=-1) return dp[pos][tight][started][prevDigit+1];
        long long res=0;
        int limit=tight?digit[pos]-'0':9;
        for(int d=0;d<=limit;d++){
            int nextTight=tight&&(d==digit[pos]-'0');
            if(!started&&d==0) res+=helper(pos+1,nextTight,0,-1,digit,k);
            else{
                if(prevDigit!=-1&&abs(d-prevDigit)>k) continue;
                res+=helper(pos+1,nextTight,1,d,digit,k);
            }
        }
        return dp[pos][tight][started][prevDigit+1]=res;
    }
public:
    long long goodIntegers(long long l, long long r, int k) {
        string left=to_string(l-1),right=to_string(r);
        long long leftVal,rightVal;
        dp.assign(right.size(),vector<vector<vector<long long>>>(2,vector<vector<long long>>(2,vector<long long>(11,-1))));
        rightVal=helper(0,1,0,-1,right,k);
        dp.assign(left.size(),vector<vector<vector<long long>>>(2,vector<vector<long long>>(2,vector<long long>(11,-1))));
        leftVal=helper(0,1,0,-1,left,k);
        return rightVal-leftVal;
    }
};