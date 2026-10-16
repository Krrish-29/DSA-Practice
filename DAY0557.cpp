// 841. Keys and Rooms
class Solution {
private:
    unordered_set<int>unique;
    bool dfs(vector<vector<int>>& rooms,int currKey){
        unique.insert(currKey);
        for(int &key:rooms[currKey]){
            if(!unique.count(key)){
                if(dfs(rooms,key)) return true;
            }
        }
        return unique.size() == rooms.size();
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // simple dfs and need not to use any seen set , since we do not need to answer any minimum query 
        // but since we need to know can we go in all rooms use a set to store unique keys
        // and if the unique keys seen is equal to n or rooms.size() then return true else false
        // also we do not need any explict traversal order , since at the end it only matters that we go through all rooms
        // return dfs(rooms,0);

        // same approach in bfs find all unique keys we can get from the rooms for which we have keys and repeat till 
        // no keys left
        queue<int>keys;
        keys.push(0);
        unique.insert(0);
        while(!keys.empty()){
            int currKey = keys.front();keys.pop();
            for(int &key:rooms[currKey]){
                if(!unique.count(key)){
                    unique.insert(key);
                    keys.push(key);
                }
            }
        }
        return unique.size() == rooms.size();
    }
};