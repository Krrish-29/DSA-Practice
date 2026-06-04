// 2033. Minimum Operations to Make a Uni-Value Grid
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>arr;
        for(auto &row:grid){
            for(auto &col:row){
                arr.push_back(col);
            }
        }
        sort(arr.begin(),arr.end());
        int median=arr[arr.size()/2];
        int count=0;
        for(auto &row:grid){
            for(auto &col:row){
                if(abs(col-median)%x!=0) return -1;
                count+=abs(col-median)/x;
            }
        }
        return count;
    }
};