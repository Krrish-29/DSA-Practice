// 36. Valid Sudoku
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // unordered_set<string>hashmap;
        // for(int i=0;i<9;i++){
        //     for(int j=0;j<9;j++){
        //         if(board[i][j]=='.') continue;
        //         string row=to_string(board[i][j])+"row"+to_string(i);
        //         string col=to_string(board[i][j])+"col"+to_string(j);
        //         string box=to_string(board[i][j])+"box"+to_string(i/3)+to_string(j/3);
        //         printf("hi ");
        //         if(hashmap.find(row)!=hashmap.end()||hashmap.find(col)!=hashmap.end()||hashmap.find(box)!=hashmap.end()) return false;
        //         hashmap.insert(row);
        //         hashmap.insert(col);
        //         hashmap.insert(box);
        //     }
        // }
        // return true;
        for(int i=0;i<9;i++){
            vector<bool>present(9,false);
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                if(present[board[i][j]-1]) return false;
                present[board[i][j]-1]=true;
            }
        }
        for(int i=0;i<9;i++){
            vector<bool>present(9,false);
            for(int j=0;j<9;j++){
                if(board[j][i]=='.') continue;
                if(present[board[j][i]-1]) return false;
                present[board[j][i]-1]=true;
            }
        }
        for(int boxrow=0;boxrow<3;boxrow++){
            for(int boxcol=0;boxcol<3;boxcol++){
                vector<bool>present(9,false);
                for(int i=3*boxrow;i<3+3*boxrow;i++){
                    for(int j=3*boxcol;j<3+3*boxcol;j++){
                        if(board[i][j]=='.') continue;
                        if(present[board[i][j]-1]) return false;
                        present[board[i][j]-1]=true;
                    }
                }
            }
        }
        return true;
    }
};