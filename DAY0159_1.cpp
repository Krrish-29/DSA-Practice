// 3446. Sort Matrix by Diagonals
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int size=grid.size(),i,j;
        priority_queue<int>maxheap;
        priority_queue<int,vector<int>,greater<int>>minheap;
        for(int count=0;count<size;count++){
            i=0,j=count;
            while(i<size&&j<size){
                minheap.push(grid[i][j]);
                maxheap.push(grid[j][i]);
                i++;
                j++;
            }
            i=0,j=count;
            while(i<size&&j<size){
                grid[i][j]=minheap.top();
                grid[j][i]=maxheap.top();
                minheap.pop();
                maxheap.pop();
                i++;
                j++;
            }
        }
        return grid;
    }
};