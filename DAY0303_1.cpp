// 139. Word Break
class Solution {
private:
    unordered_map<int,bool>memo;
    bool backTrack(string &s,vector<string>& wordDict,int start,string currStr){
        if(currStr==s) return true;
        if(memo.find(start)!=memo.end()) return memo[start];
        for(string &word:wordDict){
            int len=word.size();
            if(start+len<=s.size()&&s.substr(start,len)==word){
                if(backTrack(s,wordDict,start+len,currStr+word)) return memo[start]=true;
            }
        }
        return memo[start]=false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return backTrack(s,wordDict,0,"");
    }
};