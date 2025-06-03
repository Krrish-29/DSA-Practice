// 1298. Maximum Candies You Can Get from Boxes
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        // queue<int>q;
        // vector<bool>vis(candies.size(),false);
        // vector<int>available(candies.size(),0);
        // int initialBoxesSize=initialBoxes.size();
        // for(int i=0;i<initialBoxesSize;i++){
        //     if(status[initialBoxes[i]]) q.push(initialBoxes[i]);
        //     available[initialBoxes[i]]++;
        // }
        // int totalCandy=0;
        // while(!q.empty()){
        //     int size=q.size();
        //     for(int i=0;i<size;i++){
        //         int currBox=q.front();
        //         q.pop();
        //         if(status[currBox]==0||vis[currBox]) continue;
        //         vis[currBox]=true;
        //         totalCandy+=candies[currBox];
        //         for(int i=0;i<keys[currBox].size();i++){
        //             status[keys[currBox][i]]=1;
        //             if(available[keys[currBox][i]]) q.push(keys[currBox][i]);
        //         }
        //         for(int i=0;i<containedBoxes[currBox].size();i++){
        //             available[containedBoxes[currBox][i]]++;
        //             if(status[containedBoxes[currBox][i]]) q.push(containedBoxes[currBox][i]);
        //         }
        //     }
        // }
        // return totalCandy;

        int totalCandy=0;
        queue<int>q;
        for(auto box:initialBoxes) q.push(box);
        while(!q.empty()){
            int size=q.size();
            vector<int>curr;
            vector<int>inserted;
            for(int i=0;i<size;i++){
                int currBox=q.front();
                curr.push_back(currBox);
                q.pop();
                if(status[currBox]){
                    totalCandy+=candies[currBox];
                    for(auto key:keys[currBox]) status[key]=1;  
                    for(auto boxes:containedBoxes[currBox]) q.push(boxes);
                }
                else{
                    q.push(currBox);
                    inserted.push_back(currBox);
                }
            }
            if(curr==inserted) break;
        }
        return totalCandy;
    }
};