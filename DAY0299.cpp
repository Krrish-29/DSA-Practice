// 2316. Count Unreachable Pairs of Nodes in an Undirected Graph
class DSU{
public:
    vector<int>Size;
    vector<int>Parent;
    DSU(int n){
        Parent.resize(n);
        for(int i=0;i<n;i++){
            Parent[i]=i;
        }
        Size.resize(n,1);
    }
    int find (int i){
        int root=Parent[i];
        if(Parent[root]!=root) return Parent[i]=find(root);
        return root;
    }
    void unionBySize(int i,int j){
        int parentI=find(i);
        int parentJ=find(j);
        if (parentI==parentJ) return;
        int sizeI=Size[parentI];
        int sizeJ=Size[parentJ];
        if (sizeI<sizeJ){
            Parent[parentI]=parentJ;
            Size[parentJ]+=Size[parentI];
        }
        else{
            Parent[parentJ]=parentI;
            Size[parentI]+=Size[parentJ];
        }
    }
};
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DSU uf(n);
        for(auto &edge:edges){
            uf.unionBySize(edge[0],edge[1]);
        }
        long long pairs=0;
        set<int>seen;
        int rem=n;
        for(int i=0;i<n;i++){
            int parent=uf.find(i);
            if(seen.find(parent)==seen.end()){
                int size=uf.Size[parent];
                rem-=size;
                pairs+=(rem*1LL*size);
                seen.insert(parent);
            }
        }
        return pairs;
    }
};