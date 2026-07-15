// 1331. Rank Transform of an Array
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,vector<int>>map;
        for(int i=0;i<arr.size();i++){
            map[arr[i]].push_back(i);
        }
        int rank=1;
        for(auto it:map){
            for(auto &idx:it.second){
                arr[idx]=rank;
            }
            rank++;
        }
        return arr;
    }
};