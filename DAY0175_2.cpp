// 289. Game of Life
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size(),n=board[0].size();
        vector<vector<int>>dir={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int total=0;
                for(auto d:dir){
                    if(i+d[0]<m&&i+d[0]>=0&&j+d[1]<n&&j+d[1]>=0&&abs(board[i+d[0]][j+d[1]])==1) total++;
                }
                if(board[i][j]==1&&(total<2||total>3)) board[i][j]=-1;
                else if(board[i][j]==0&&total==3) board[i][j]=2;

            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                board[i][j]=board[i][j]>0?1:0;
            }
        }
    }
};