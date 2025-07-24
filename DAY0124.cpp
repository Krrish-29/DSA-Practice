// 2322. Minimum Score After Removals on a Tree
class Solution {
private:
    void dfs1(int node,int parent,vector<int>ancestor,vector<vector<bool>>&is_ancestor,vector<vector<int>>&adj_list){
        for(int p:ancestor) is_ancestor[p][node]=true;
        for(int q:adj_list[node]){
            if(q!=parent){
                ancestor.push_back(node);
                dfs1(q,node,ancestor,is_ancestor,adj_list);
                ancestor.pop_back();
            }
        }
    }
    int dfs2(int node,int parent,vector<int>&xorSum,vector<int>& nums,vector<vector<int>>&adj_list){
        int current=nums[node];
        for(int p:adj_list[node]){
            if(p!=parent){
                current^=dfs2(p,node,xorSum,nums,adj_list);
            }
        }
        xorSum[node]=current;
        return current;
    }
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>>adj_list(n);
        for(auto edge:edges){
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }
        vector<vector<bool>>is_ancestor(n,vector<bool>(n,false));
        dfs1(0,-1,{},is_ancestor,adj_list);
        vector<int>xorSum(n,0);
        dfs2(0,-1,xorSum,nums,adj_list);
        int res=INT_MAX,xorP,xorQ,currentBest;
        for(int p=1;p<n;p++){
            for(int q=p+1;q<n;q++){
                xorP=xorSum[p];
                xorQ=xorSum[q];
                if(is_ancestor[p][q]){
                    res=min(max({xorQ,xorP^xorQ,xorSum[0]^xorP})-min({xorQ,xorP^xorQ,xorSum[0]^xorP}),res);
                }
                else if(is_ancestor[q][p]){
                    res=min(max({xorP,xorQ^xorP,xorSum[0]^xorQ})-min({xorP,xorQ^xorP,xorSum[0]^xorQ}),res);
                }
                else{
                    res=min(max({xorP,xorQ,xorSum[0]^xorP^xorQ})-min({xorP,xorQ,xorSum[0]^xorP^xorQ}),res);
                }
            }
        }
        return res;
    }
};