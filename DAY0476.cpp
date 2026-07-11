// 2685. Count the Number of Complete Components
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // stored a ordered set of neighbours of each element including itself and then 
        // loop on each elem and then any unseen elem loop on its neighbours and compare their ordered set to make sure that they are a part of complete connected component 
        // also mark elems seen as you go
        vector<set<int>>adj_list(n);
        for(auto &edge:edges){
            adj_list[edge[0]].insert(edge[0]);
            adj_list[edge[0]].insert(edge[1]);
            adj_list[edge[1]].insert(edge[0]);
            adj_list[edge[1]].insert(edge[1]);
        }
        unordered_set<int>seen;
        int count=0;
        bool flag;
        for(int node=0;node<n;node++){
            if(!seen.count(node)){
                seen.insert(node);
                flag=true;
                for(auto &neighbour:adj_list[node]){
                    seen.insert(neighbour);
                    if(adj_list[neighbour]!=adj_list[node]){
                        flag=false;
                        break;
                    }
                }
                if(flag) count++;
            }
        }
        return count;
    }
};