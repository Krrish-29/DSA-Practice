// 2608. Shortest Cycle in a Graph
class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        // to find a loop to a node we need to start from that node and do either dfs or bfs
        // so we need to check each node one by one and to find the loop distance 
        // need to maintain parent and distance of nodes seen so far starting from a particular node
        // also there can be two options either a node has not been seen yet with its distance as 
        // -1 or INT_MAX , or it has been seen and it is not a previous node (since the graph is undirected)
        // which means there was a path from the same starting point that led to that node 
        // and if we move to that node we can trace back to the starting point forming the loop
        // with distance of currNode , that seen node and + 1
        vector<vector<int>>adj_list(n);
        for(vector<int> &edge:edges){
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }
        int minPath=INT_MAX;
        queue<int>q;
        for(int node=0;node<n;node++){
            vector<int>parent(n,-1);
            vector<int>distance(n,-1);

            q.push(node);
            distance[node]=0;
            while(!q.empty()){
                int currNode = q.front(); q.pop();
                for(int &neighbours:adj_list[currNode]){
                    if( distance[neighbours]== -1){ // not seen yet
                        q.push(neighbours);
                        parent[neighbours]=currNode;
                        distance[neighbours] = distance[currNode]+1;
                    }
                    else if(parent[currNode] != neighbours){ // already seen and it is not the previous node (parent of currNode)
                    // means it has been seen from some other path , it has a path from this node to the startnode
                    // and going to this node using +1 distance , will make a loop 
                        minPath = min(minPath,distance[neighbours]+distance[currNode]+1);
                    }
                }
            }
        }
        return minPath==INT_MAX ? -1 : minPath;
    }
};