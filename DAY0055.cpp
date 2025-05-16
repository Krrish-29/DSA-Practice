// 2901. Longest Unequal Adjacent Groups Subsequence II
class Solution {
public:
    bool stringcheck(string &x,string &y){
        if(x.size()!=y.size()) return false;
        int flag=0;
        for(int i=0;i<x.size();i++){
            if(x[i]!=y[i]) flag++;
            if(flag>1) return false;
        }
        return true;
    }
    vector<int>dfs(int node,vector<vector<int>>&graph,vector<vector<int>>&dp,vector<bool>&visited){
        if(!dp[node].empty()) return dp[node];
        if(visited[node]) return {};
        visited[node]=true;
        vector<int> longest_path;
        for(int x:graph[node]){
            vector<int>path=dfs(x,graph,dp,visited);
            if(path.size()>longest_path.size()){
                longest_path=path;
            }
        }
        visited[node]=false;
        longest_path.insert(longest_path.begin(),node);
        dp[node]=longest_path;
        return dp[node];
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int size=groups.size();
        if(size==1) return words;
        vector<vector<int>>graph(size);
        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
                if(groups[i]!=groups[j]&&stringcheck(words[i],words[j])){
                   graph[i].push_back(j);
                }
            }
        }
        vector<vector<int>>dp(size);
        vector<int>best_path;
        for(int i=0;i<size;i++){
            vector<bool>visited(size,false);
            vector<int>path=dfs(i,graph,dp,visited);
            if(path.size()>best_path.size()){
                best_path=path;
            }
        }
        vector<string>answer;
        for(int i:best_path){
            answer.push_back(words[i]);
        }
        return answer;
    }
};
/* Best Space
class Solution {
public:

    bool d(string &a, string &b){
        int n=a.size(),d=0;
        for (int i=0;i<n;i++) if (a[i]!=b[i]) if (++d==2) return false;
        return true;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size(),np[11],x[11][n],max[n],next[n];
        for (int i=0;i<=10;i++) np[i]=0;
        for (int i=0;i<n;i++) max[i]=1;
        for (int i=0;i<words.size();i++){
            int l=words[i].size();
            x[l][np[l]++]=i;
        }

        for (int l=1;l<=10;l++){
            int k=np[l];

            for (int i=k-1;i>=0;i--){
                for (int j=i+1;j<k;j++){
                    int a=x[l][i],b=x[l][j];
                    if (groups[a]!=groups[b] && max[a]<1+max[b] && d(words[a],words[b])){
                        max[a]=1+max[b];
                        next[a]=b;
                    }
                }
            }
        }

        int maxSize=0,k;
        for (int i=0;i<n;i++) if (max[i]>maxSize) {
            maxSize=max[i];
            k=i;
        }

        vector<string> ret;
        while(1){
            ret.push_back(words[k]);
            if (max[k]==1) break;
            k=next[k];
        }


        return ret;
    }
};
*/
/* Best Time
class Solution {
public:
    bool hamming1(const string& s, const string& t){
        const int sz = s.size();
        if (sz != t.size()) return false;
        int diff = 0;
        for (int i = 0; i < sz && diff < 2; i++)
            diff += s[i] != t[i];
        return diff == 1;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        const int n = words.size();
        int maxLen = 0, pos = -1;
        vector<int> dp(n, 1), prev(n, -1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(groups[i] != groups[j] && hamming1(words[i], words[j])){
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if(dp[i] > maxLen){
                maxLen = dp[i];
                pos = i;
            }
        }
        vector<string> ans;
        for(; pos != -1; pos = prev[pos]){
            ans.push_back(words[pos]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
*/