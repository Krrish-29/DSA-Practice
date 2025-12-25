// 3756. Concatenate Non-Zero Digits and Multiply by Sum II
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<long long>pow10(s.size()+1,1);
        const int MOD=1e9+7;
        for (int i = 1; i <= s.size(); i++) {
            pow10[i] = (pow10[i-1] * 10) % MOD;
        }

        vector<tuple<long long,int,int>>digits; // num , sum , unique digits
        int num=0,sum=0,unique=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!='0'){
                num=(num*1LL*10+(s[i]-'0'))%MOD;
                sum+=(s[i]-'0');
                unique++;
            }
            digits.push_back({num,sum,unique});
        }
        vector<int>ans;
        int length,currSum,x;
        for(auto q:queries){
            if(q[0]==0) ans.push_back(get<0>(digits[q[1]])*1LL*get<1>(digits[q[1]])%MOD);
            else{
                length=get<2>(digits[q[1]])-get<2>(digits[q[0]-1]);
                currSum=get<1>(digits[q[1]])-get<1>(digits[q[0]-1]);
                x=(get<0>(digits[q[1]])-get<0>(digits[q[0]-1])*pow10[length])%MOD;
                if(x<0) x+=MOD;
                ans.push_back(currSum*1LL*x%MOD);
            
            }
        }
        return ans;
    }
};