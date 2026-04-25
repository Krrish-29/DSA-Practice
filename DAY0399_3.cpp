// 3910. Count Connected Subgraphs with Even Node Sum
class Solution {
private:
    int count=0;
    void check(vector<vector<int>>&adj_list,unordered_set<int>currNodes,vector<int>&nums){
        queue<int>q;
        q.push(*currNodes.begin());
        int sum=0;
        unordered_set<int>seen;
        seen.insert(*currNodes.begin());
        while(!q.empty()){
            int v=q.front();q.pop();
            sum+=nums[v];
            for(auto &u:adj_list[v]){
                if(currNodes.count(u)&&!seen.count(u)){
                    q.push(u);
                    seen.insert(u);
                }
            }
        }
        if(currNodes==seen&&sum%2==0) count++;
    }
    void helper(int node,vector<int>&nums,vector<vector<int>>&adj_list,unordered_set<int>&currNodes){
        if(node==nums.size()) {
            if(currNodes.size()!=0) check(adj_list,currNodes,nums);
           return ;
        }
        // skip current node 
        helper(node+1,nums,adj_list,currNodes);
        // consider current node
        currNodes.insert(node);
        helper(node+1,nums,adj_list,currNodes);
        currNodes.erase(node);
    }
public:
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        vector<vector<int>>adj_list(n);
        for(auto &edge:edges){
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }
        unordered_set<int>currNodes;
        helper(0,nums,adj_list,currNodes);
        return count;
    }
};