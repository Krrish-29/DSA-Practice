// 797. All Paths From Source to Target
class Solution {
private:
    vector<vector<int>>paths;
    void dfs(vector<vector<int>>& adj_list,int currNode, int& finalNode, vector<int> currPath){
        currPath.push_back(currNode);
        if(currNode == finalNode){
            paths.push_back(currPath);
            return ;
        } 
        for(int &neightbours:adj_list[currNode]){
            dfs(adj_list,neightbours,finalNode,currPath);
        }
        currPath.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // approach is to make adj_list and then dfs or bfs 
        // in dfs every node till we see he final node is considered in the path 
        // when we see the final node add the path to the paths possible 
        // and backtrack and remove the last node from the path and move to the next path possible
        // and no seen set is required since we need to check all paths and also the graph is directed 

        // in bfs we store the path starting from node 0 , and we use the last node 
        // to explore all neighbours of it and create new paths from the current path
        // and when we see that the last node of a path is finalNode we add it the paths and skip exploring that path
        int nodes = graph.size();
        vector<vector<int>>adj_list(nodes);
        for(int node = 0; node < nodes; node++){
            sort(graph[node].begin(),graph[node].end());
            adj_list[node] = graph[node];
        }

        int finalNode = nodes-1;
        // dfs(adj_list,0,finalNode,{});
        // return paths;

        queue<vector<int>>q; // path
        q.push({0});
        vector<vector<int>>paths;
        vector<int> currPath,newPath;
        while( !q.empty() ){
            currPath =  q.front(); q.pop();
            if( currPath.back() == finalNode ) {
                paths.push_back(currPath);
                continue;
            }
            for(int &neightbours:adj_list[currPath.back()]){
                newPath = currPath; // creating a new path from the curr path 
                newPath.push_back(neightbours);
                q.push(newPath);
            }
        }
        return paths;
    }
};