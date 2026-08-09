// 1519. Number of Nodes in the Sub-Tree With the Same Label
class Solution {
private:
    vector<int>ans;
    void dfs1(int node,int prevNode,vector<vector<int>>& adj_list,string &labels,vector<int>& freq){
        int currentChar = labels[node]-'a';
        freq[currentChar]++;
        for(int &neighbour:adj_list[node]){
            if(neighbour!=prevNode){
                vector<int> subTreeFreq(26,0);
                dfs1(neighbour,node,adj_list,labels,subTreeFreq);
                for(int i=0;i<26;i++){
                    freq[i]+=subTreeFreq[i];
                }
            }
        }
        ans[node]=freq[currentChar];
    }

    void dfs2(int node,int prevNode,vector<vector<int>>& adj_list,string &labels,vector<int>& freq){
        int currentChar = labels[node]-'a';
        int prevCount = freq[currentChar];
        freq[currentChar]++;
        for(int &neighbour:adj_list[node]){
            if(neighbour!=prevNode){
                dfs2(neighbour,node,adj_list,labels,freq);
            }
        }
        ans[node]=freq[currentChar]-prevCount;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        // the question is asking to find the freq of chars in each subtree mainly
        // using the freq the return will be an array 
        // first build a adj_list for graph
        // do simple dfs and each step mark visited and count the freq of current char
        // using graph explore new neighbours(subtrees) and the freq array of each subtree will be added
        // to build the freq array of current mainTree/subtree and using all those freq 
        // the value of current idx will be freq of current char found in current Tree 
        
        ans.resize(n,0);

        vector<vector<int>>adj_list(n);
        for(auto &edge:edges){
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        // it uses prevNode to make sure prevNodes are not explored again since prevNode is parent Node

        vector<int>freq(26,0);
        // can use unordered_map to improve on memory 

        dfs1(0,0,adj_list,labels,freq);
        
        // dp solution 
        // storing the currFreq and then using recursion and updating the freq of total Tree then subtracting it from currTotal
        // dfs2(0,0,adj_list,labels,freq);

        return ans;
    }
};