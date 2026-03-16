// 1048. Longest String Chain
class Solution {
private:
    vector<vector<int>>dp;
    bool predecessor(string &a,string &b){
        int size1=a.size(),size2=b.size(); //size2 > size1
        if((size2-size1)!=1) return false;
        int i=0,j=0,mistake=0;
        while(i<size1&&j<size2){
            if(a[i]==b[j]) {
                i++;
            }
            j++;
        }   
        return i==size1?true:false;
    }
    int helper(vector<string>&words,int idx,int prev){
        if(idx==words.size()) return 0;
        if(prev!=-1&&dp[idx][prev]!=-1) return dp[idx][prev];
        int skip=0,take=0;
        skip=helper(words,idx+1,prev);
        if(prev==-1||(prev!=-1&&predecessor(words[prev],words[idx]))) take=1+helper(words,idx+1,idx);
        if(prev==-1) return max(skip,take);
        return dp[idx][prev]=max(skip,take);
    }
public:
    int longestStrChain(vector<string>& words) {
        // recursive n^2 * k(for string checking)
        sort(words.begin(),words.end(),[](const string &a,const string &b){
            return a.size()<b.size();
        });
        int size=words.size();
        dp.resize(size,vector<int>(size,-1));
        return helper(words,0,-1);


        // bottoms up n^2 * k
        // state is dp[i] is the longest chain possible at index i
        // int size=words.size(),maxLen=1;
        // sort(words.begin(),words.end(),[](const string &a,const string &b){
        //     return a.size()<b.size();
        // });
        // vector<int>dp(size,1);
        // for(int i=1;i<size;i++){
        //     for(int j=0;j<i;j++){
        //         if(predecessor(words[j],words[i])) dp[i]=max(dp[i],dp[j]+1);
        //     }
        //     maxLen=max(maxLen,dp[i]);
        // }
        // return maxLen;
    }
};