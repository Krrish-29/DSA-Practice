// 1345. Jump Game IV
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int size=arr.size();
        if(size==1) return 0;

        // preprocess the arr to compress it
        // trying to keep only start and end of continuous elems which are more than 2 
        int end=0,counter=0,same=-1;
        for(int i=0;i<size;i++){
            if(arr[i]!=same){
                same=arr[i];
                counter=1;
            }
            else {
                counter++;
            }
            arr[end]=arr[i];
            if(counter<=2) end++;
        }
        size=end;

        //combining idx of same numbers
        // so that along with +1 -1 jumps we can do 3rd jump to same elems
        unordered_map<int,vector<int>>indices;
        for(int i=size-1;i>=0;i--){
            indices[arr[i]].push_back(i);
        }
        // bfs
        queue<pair<int,int>>q;//idx , moves
        unordered_set<int>seen;
        q.push({0,0});  
        seen.insert(0);
        while(!q.empty()){
            auto e = q.front();q.pop();
            int idx=e.first;
            int moves=e.second;
            if(idx==size-1){
                return moves;// cause of level order traversal the first time we see the end 
                // in the tree would be the min after that we will only increase depth unnecessarily
            }
            if(idx>0 && !seen.count(idx-1)){
                q.push({idx-1,moves+1});
                seen.insert(idx-1);
            }
            if(idx+1<size && !seen.count(idx+1)){
                q.push({idx+1,moves+1});
                seen.insert(idx+1);
            }
            for(int &neighbour:indices[arr[idx]]){
                if(!seen.count(neighbour)){
                    q.push({neighbour,moves+1});
                    seen.insert(neighbour);
                }
            }
            indices[arr[idx]]={};
        }
        return -1;
    }
};