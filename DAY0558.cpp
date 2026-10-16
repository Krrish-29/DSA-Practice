// 886. Possible Bipartition
class Solution {
private:
    bool dfs(vector<vector<int>>& adj_list,int currPerson,int group,unordered_map<int,int>& seenMap){
        seenMap[currPerson]=group;
        for(int &disLikes:adj_list[currPerson]){
            if(!seenMap.count(disLikes)){
                if(!dfs(adj_list,disLikes,(seenMap[currPerson]+1)%2,seenMap)) return false;
            }
            else if(seenMap[disLikes] != (seenMap[currPerson]+1)%2) return false;
        }
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // a dislikes b and same way around,therefore a undirected edge b/w two people
        // keep the first elem in say set 1 and anyone it dislikes in set 2 and
        // explore the people the second person dislikes and repeat the cycle 
        // since there are two sets if a person is in set 1 the one's it dislikes will be in 2 or vice versa
        // if someone is disliked and is already seen in a set which is not the expected set then what means
        // that two people disliking each other are in same set.
        // explore all people ,if the person is not seen before that means its a complete new tree there we can add it to either of the groups
        // since its an undirected graph , and start exploring again.
        unordered_map<int,int>seenMap; // person , set
        vector<vector<int>> adj_list(n+1); // either use -1 in all people for 0 based indexing, but i choose to stick with 1 based indexing in question
        for(auto &disLike:dislikes){
            adj_list[disLike[0]].push_back(disLike[1]);
            adj_list[disLike[1]].push_back(disLike[0]);
        }
        for(int i=1;i<=n;i++){
            if(!seenMap.count(i) && !dfs(adj_list,i,0,seenMap)) return false;
        }
        return true;

        // bfs
        queue<int>q;
        for(int i=1;i<=n;i++){
            if(!seenMap.count(i)) {
                seenMap[i] = 0;
                q.push(i);
            }
            while(!q.empty()){
                int a = q.front(); q.pop();
                for(int &b:adj_list[a]){
                    if(!seenMap.count(b)){
                        q.push(b);
                        seenMap[b] = (seenMap[a]+1)%2; // put b in different set than a 
                    } // else we have seen b in a set that we already expected it to be in 
                    else if(seenMap[b] != (seenMap[a]+1)%2) return false; // we found that b is seen in an set not expected
                }
            }
        }
        return true;
    }
};