// 1722. Minimize Hamming Distance After Swap Operations
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        // can use union find as well 
        // here i used bfs for simple code 
        int size=source.size();
        vector<vector<int>>adj_list(size);
        for(auto &swap:allowedSwaps){
            adj_list[swap[0]].push_back(swap[1]);
            adj_list[swap[1]].push_back(swap[0]);
        }
        int hamming=0;
        vector<bool>seen(size,false);
        for(int i=0;i<size;i++){
            if(!seen[i]){
                vector<int>idx;
                queue<int>q;
                q.push(i);
                idx.push_back(i);
                seen[i]=true;
                while(!q.empty()){
                    int v=q.front();q.pop();
                    for(int &u:adj_list[v]){
                        if(!seen[u]){
                            q.push(u);
                            idx.push_back(u);
                            seen[u]=true;
                        }
                    }
                }
                unordered_map<int,int>map;
                for(int &x:idx){
                    map[source[x]]++;
                    map[target[x]]--;
                }
                int temp=0;
                for(auto it=map.begin();it!=map.end();++it){
                    temp+=abs(it->second);
                }
                // any two mismatches can be clubed together to reduce the Hamming distance
                hamming+=(temp/2);
            }
        }
        return hamming;
    }
};