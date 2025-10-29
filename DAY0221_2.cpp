// 2352. Equal Row and Column Pairs
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        const int mod=1e9+7;
        // take mod for keeping value reasonable and for hashing mul by 11
        int n=grid.size();
        long long num;
        unordered_map<long,int>map;
        for(int i=0;i<n;i++){
            num=0;
            for(int j=0;j<n;j++){
                num=((num*11)+grid[i][j])%(mod);
            }
            map[num]++;
        }
        int count=0;
        for(int i=0;i<n;i++){
            num=0;
            for(int j=0;j<n;j++){
                num=((num*11)+grid[j][i])%(mod);
            }
            if(map.find(num)!=map.end()) count+=map[num];
        }
        return count;
    }
};