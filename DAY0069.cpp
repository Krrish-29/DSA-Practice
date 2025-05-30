// 2359. Find Closest Node to Given Two Nodes
class Solution {
public:
    // void dfs(int node,vector<int>&distance,vector<int>&edges,vector<bool>&visited,int curr_dist){
    //     if(node!=-1&&!visited[node]){
    //         distance[node]=curr_dist;
    //         visited[node]=true;
    //         dfs(edges[node],distance,edges,visited,curr_dist+1);
    //         visited[node]=false;
    //     }
    // }   
    void bfs(int node,vector<int>&distance,vector<int>&edges){
        queue<int>queue;
        queue.push(node);
        distance[node]=0;
        while(!queue.empty()){
            int curr_node=queue.front();
            queue.pop();
            int neighbour=edges[curr_node];
            if(neighbour!=-1&&distance[neighbour]==INT_MAX){
                distance[neighbour]=distance[curr_node]+1;
                queue.push(neighbour);
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int size=edges.size(),distance=INT_MAX,index=-1;
        vector<int>distance1(size,INT_MAX);
        vector<int>distance2(size,INT_MAX);
        // vector<bool>visited(size,false);
        // dfs(node1,distance1,edges,visited,0);
        // dfs(node2,distance2,edges,visited,0);
        bfs(node1,distance1,edges);
        bfs(node2,distance2,edges);
        for(int i=0;i<size;i++){
            if(max(distance1[i],distance2[i])<distance){
                distance=max(distance1[i],distance2[i]);
                index=i;
            }
        }
        return index;
    }
};