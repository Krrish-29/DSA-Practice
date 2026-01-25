// 3820. Pythagorean Distance Nodes in a Tree
class Solution {
private:
    vector<int> bfs_dist(vector<vector<int>>&adj_list,int node,int n){
        vector<int>dist(n,INT_MAX);
        queue<int>q;
        dist[node]=0;
        q.push(node);
        while(!q.empty()){
            int u=q.front();q.pop();
            for(int v:adj_list[u]){
                if(dist[v]==INT_MAX){
                    dist[v]=dist[u]+1;
                    q.push(v);
                }
            }
        }
        return dist;
    }
public:
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>>adj_list(n);
        for(vector<int> &edge:edges){
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }
        vector<int>distX=bfs_dist(adj_list,x,n);
        vector<int>distY=bfs_dist(adj_list,y,n);
        vector<int>distZ=bfs_dist(adj_list,z,n);
        int count=0;
        for(int i=0;i<n;i++){
            if(distX[i]==INT_MAX||distY[i]==INT_MAX||distZ[i]==INT_MAX) continue;
            vector<int>temp={distX[i],distY[i],distZ[i]};
            sort(temp.begin(),temp.end());
            if((temp[0]*1LL*temp[0])+(temp[1]*1LL*temp[1])==(temp[2]*1LL*temp[2])) count++;
        }
        return count;
    }
};