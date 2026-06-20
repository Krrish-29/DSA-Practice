// 3963. Create Grid With Exactly One Path
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>grid(m);
        grid[0]=string(n,'.');
        for(int i=1;i<m;i++){
            for(int j=0;j<n-1;j++){
                grid[i].push_back('#');
            }
            grid[i].push_back('.');
        }
        return grid;
    }
};