// 3981. Count Distinct Ways to Form Target from Two Strings
class Solution {
private:
    vector<vector<vector<int>>>dp;
    const int MOD=1e9+7;
    int helper(string &word1,int idx1,string &word2,int idx2,bool picked1,bool picked2,string &target,int idx){
        if(idx==target.size()){
            if(picked1&&picked2) return 1;
            else return 0;
        } 
        if(dp[idx1][idx2][idx]!=-1) return dp[idx1][idx2][idx];
        long long res=0;
        for(int i=idx1;i<word1.size();i++){
            if(word1[i]==target[idx]) res+=helper(word1,i+1,word2,idx2,true,picked2,target,idx+1);
        }
        for(int i=idx2;i<word2.size();i++){
            if(word2[i]==target[idx]) res+=helper(word1,idx1,word2,i+1,picked1,true,target,idx+1);
        }
        return dp[idx1][idx2][idx]=res%MOD;
    }
public:
    int interleaveCharacters(string word1, string word2, string target) {
        dp.assign(word1.size()+1,vector<vector<int>>(word2.size()+1,vector<int>(target.size(),-1)));
        return helper(word1,0,word2,0,false,false,target,0);
    }
};