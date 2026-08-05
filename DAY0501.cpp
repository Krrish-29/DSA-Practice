// 3310. Remove Methods From Project
class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // question is easy except this line
        // A group of methods can only be removed if no 
        // method outside the group invokes any methods within it.
        // since the first thing is to identify all sus methods , 
        // use adj_list and map out the graph
        // starting from k using bfs/dfs find all sus methods
        // now the main point is the line
        // if we want to remove the group of sus elems we have to make sure that
        // they are isolated from all other healthy elems and due to the nature of sus elems 
        // they all will be in a single group 
        // move over all non sus methods and find other nonsus methods as well but 
        // if we find that a non sus elem is invoking a sus elem then 
        // we cannot remove any sus elems and return all elems
        // else we keep collection non sus elem and return then
        vector<vector<int>>adj_list(n);
        for(auto &invocation:invocations){
            adj_list[invocation[0]].push_back(invocation[1]);
        }

        unordered_set<int>susMethods;
        queue<int>susQ;
        susQ.push(k);
        while(!susQ.empty()){
            int susEle = susQ.front(); susQ.pop();
            susMethods.insert(susEle);
            for(int &neighbour:adj_list[susEle]){
                if(!susMethods.count(neighbour)) susQ.push(neighbour);
            }
        }

        vector<int>goodMethods;

        unordered_set<int>nonSusMethods;
        queue<int>nonSusQ;
        for(int i=0;i<n;i++){
            if(!susMethods.count(i)){ 
                // elem is not sus 
                nonSusQ.push(i);
                goodMethods.push_back(i);
                while(!nonSusQ.empty()){
                    int nonSusEle = nonSusQ.front(); nonSusQ.pop();
                    nonSusMethods.insert(nonSusEle);
                    for(int &neighbour:adj_list[nonSusEle]){
                        
                        if(susMethods.count(neighbour)){
                            // sus group is not isolated 
                            goodMethods.assign(n,0);
                            for(int i=0;i<n;i++) goodMethods[i]=i;
                            return goodMethods;
                        }
                        
                        if(!nonSusMethods.count(neighbour)) nonSusQ.push(neighbour);
                    }
                }
            }
        }   
        return goodMethods;
    }
};