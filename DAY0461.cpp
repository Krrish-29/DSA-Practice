// 3965. Finish Time of Tasks I
class Solution {
private:
    long long dfs(int node,vector<vector<int>>& adj_list,vector<int>& baseTime){
        if(adj_list[node].size()==0) return baseTime[node];
        long long earliest=LLONG_MAX,latest=LLONG_MIN,time;
        for(int &nextNode:adj_list[node]){
            time=dfs(nextNode,adj_list,baseTime);
            earliest=min(earliest,time);
            latest=max(latest,time);
        }
        return (latest - earliest + baseTime[node]) + latest;
    }
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>>adj_list(n);
        for(auto &edge:edges){
            adj_list[edge[0]].push_back(edge[1]);
        }
        return dfs(0,adj_list,baseTime);
    }
};