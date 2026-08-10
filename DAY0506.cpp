// 2642. Design Graph With Shortest Path Calculator
class Graph {
private:
    int size;
    vector<vector<pair<int,int>>>adj_list;
public:
    Graph(int n, vector<vector<int>>& edges) {
        size=n;
        adj_list.resize(n);
        for(auto &edge:edges){
            adj_list[edge[0]].push_back({edge[1],edge[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj_list[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        //djikstra 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; // dist , node
        vector<int>distance(size,INT_MAX);
        pq.push({0,node1});
        distance[node1]=0;
        while(!pq.empty()){
            auto [dist,u] = pq.top();pq.pop();
            for(auto &[v,weight]:adj_list[u]){
                if(distance[u]+weight < distance[v]){
                    distance[v] = distance[u]+weight;
                    pq.push({distance[v],v});
                }
            }

        }
        return distance[node2]==INT_MAX?-1:distance[node2];

    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */